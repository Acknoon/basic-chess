//
// Created by algo on 22/04/2021.
//

#include "King.h"
#include "Game.h"


King::King(int index_row, int index_col, Colour color_sign) : Piece(Square(index_row, index_col),
                                                                    color_sign){}

bool King::isSquarePotentiallyMoved(Square square_to_check) {
    return square_to_check.getRow() <= this->position.getRow() + 1
           && square_to_check.getRow() >= this->position.getRow() - 1
           && square_to_check.getCol() <= this->position.getCol() + 1
           && square_to_check.getCol() >= this->position.getCol() - 1;
}

PieceTag King::getTag() {
    return KING;
}

bool King::checkMove(Square square_to_check, Game &game) {
    if (this->isSquareLegal(square_to_check, game.getPieceFromBoard(square_to_check)))
        return !(this->isCheckHappening(square_to_check, game));
    return false;
}

bool King::isControllingSquare(Square square_to_check, Game &game) {
    if (isSquareInsideBoard(square_to_check)){
        if (this->isSquarePotentiallyMoved(square_to_check)) {
            return true;
        }
    }
    return false;
}

bool King::isKingAbleToMove(Game &game) {
    if (game.isCheck()) {
        for (int indexR = -1; indexR < 2; indexR++) {
            for (int indexC = -1; indexC < 2; indexC++) {
                if ((checkMove(Square(this->position.getRow() + indexR,
                                         this->position.getCol() + indexC), game))) {
                    return true;
                }
            }
        }
        return false;
    }
    return false;
}

bool King::isCheckMate(Game &game) {
    list<Piece*> enemy_threatening_pieces = getEnemyCheckingPieces(game);
    switch (enemy_threatening_pieces.size()) {
        case CHECK: {
            Piece* threat = enemy_threatening_pieces.front();
            if (isKingAbleToMove(game))
                return false;
            if (isPossibleToEliminateThreat(threat, game))
                return false;
            if (isPossibleToBlockThreat(threat, game))
                return false;
            break;
        }
        case DOUBLE_CHECK: {
            return !(isKingAbleToMove(game));
        }
        case NO_CHECK: {
            return false;
        }
    }
    return true;
}

bool King::detectCheck(Game &game) {
    bool flag_check = false;
    for (auto const& enemy_piece : game.getOpponent(this->getSign())->getListOfPieces()) {
        if (enemy_piece->isControllingSquare(this->position, game)) {
            enemy_piece->setCheck(true);
            flag_check = true;
        } else{
            enemy_piece->setCheck(false);
        }
    }

    if (game.getOpponent(this->getSign())->getKing()->isControllingSquare(this->position, game))
        flag_check = true;

    return flag_check;
}

list<Piece *> King::getEnemyCheckingPieces(Game &game) {
    list<Piece*> checking_pieces;
    for (auto const& enemy_piece : game.getOpponent(this->getSign())->getListOfPieces()) {
        if (enemy_piece->isChecking())
            checking_pieces.push_front(enemy_piece);
    }
    return checking_pieces;
}

bool King::isPossibleToEliminateThreat(Piece* threat, Game &game) {
    for (auto const& ally_piece : game.getPlayer(this->getSign())->getListOfPieces()) {
        if (ally_piece->isControllingSquare(threat->getPosition(), game)){
            return true;
        }
    }
    return false;
}

bool King::isPossibleToBlockThreat(Piece* threat, Game &game) {
    list<Square> path_to_threat = getPathSquaresToThreat(threat, game);
    for (auto const& ally_piece : game.getPlayer(this->getSign())->getListOfPieces()) {
        for (auto const& square_in_path : path_to_threat) {
            if (ally_piece->checkMove(square_in_path, game))
                return true;
        }
    }
    return false;
}

list<Square> King::getPathSquaresToThreat(Piece *threat, Game &game) {
    Square index_square(this->position);
    list<Square> path_of_squares;
    int row_pattern = threat->getPosition().getRow() - this->position.getRow();
    int col_pattern = threat->getPosition().getCol() - this->position.getCol();
    if (row_pattern != 0)
        row_pattern /= abs(row_pattern);
    if (col_pattern != 0)
        col_pattern /= abs(col_pattern);

    while (!(index_square == threat->getPosition())){
        if (index_square == threat->getPosition())
            break;
        index_square.addToSquare(row_pattern, col_pattern);
        path_of_squares.push_front(Square(index_square));
    }
    return path_of_squares;
}
