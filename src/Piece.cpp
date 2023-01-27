//
// Created by algo on 22/04/2021.
//

#include "Piece.h"
#include "Game.h"

Piece::Piece(Square position_on_board, Colour color_piece):
        color_sign(color_piece), is_checking(false), position(position_on_board){}

Piece::Piece(int index_row, int index_col, Colour color_piece) :
        color_sign(color_piece), is_checking(false), position(index_row, index_col){}

Colour Piece::getSign() {
    return this->color_sign;
}

void Piece::setCheck(bool check_status) {
    this->is_checking = check_status;
}

bool Piece::isChecking() const {
    return this->is_checking;
}

bool Piece::isSquareLegal(Square square_to_check, Piece* piece_on_square) {
    if (isSquareInsideBoard(square_to_check)){
        if (this->isSquarePotentiallyMoved(square_to_check)) {
            if (piece_on_square != nullptr) {
                if (piece_on_square->getSign() != this->getSign()) {
                    return true;
                }
            } else
                return true;
        }
    }
    return false;
}

Square Piece::getPosition() const{
    return position;
}

bool Piece::isSquareInsideBoard(Square square_to_check) {
    return (square_to_check.getRow() < CHESS_BOARD_LENGTH && square_to_check.getRow() >= 0) &&
            (square_to_check.getCol() < CHESS_BOARD_LENGTH && square_to_check.getCol() >= 0);
}

bool Piece::isPathCleared(Square square_to_check, Game &game) {
    Square index_square(this->position);
    int row_pattern = square_to_check.getRow() - this->position.getRow();
    int col_pattern = square_to_check.getCol() - this->position.getCol();
    if (row_pattern != 0)
        row_pattern /= abs(row_pattern);
    if (col_pattern != 0)
        col_pattern /= abs(col_pattern);

    while (!(index_square == square_to_check)){
        index_square.addToSquare(row_pattern, col_pattern);
        if (index_square == square_to_check) {
            return true;
        }
        if (game.getPieceFromBoard(index_square) != nullptr) {
            if (game.getPieceFromBoard(index_square)->getTag() != KING) {
                return false;
            }
        }
    }
    return true;
}

bool Piece::isCheckHappening(Square square_to_check, Game &game) {
    bool flag_check;
    Piece* eaten_piece_container = game.getPieceFromBoard(square_to_check);
    Square piece_initial_position(this->getPosition());
    game.setPieceOnBoard(square_to_check, this);
    game.setPieceOnBoard(this->position, nullptr);
    this->setPosition(square_to_check);
    if (eaten_piece_container != nullptr)
        game.getOpponent()->getListOfPieces().remove(eaten_piece_container);

    flag_check = game.getPlayer(this->getSign())->getKing()->detectCheck(game);

    game.setPieceOnBoard(piece_initial_position, this);
    game.setPieceOnBoard(square_to_check, eaten_piece_container);
    this->setPosition(piece_initial_position);
    if (eaten_piece_container != nullptr)
        game.getOpponent()->getListOfPieces().push_front(eaten_piece_container);

    return flag_check;
}

void Piece::setPosition(Square square) {
    this->position = square;

}

bool Piece::isProtectingItself(Square square_to_check) {
    return this->position == square_to_check;
}
