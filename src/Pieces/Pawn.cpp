//
// Created by algo on 22/04/2021.
//

#include "Pawn.h"
#include "Game.h"


Pawn::Pawn(int index_row, int index_col, Colour color_sign) : Piece(Square(index_row, index_col),
                                                                    color_sign) {}

bool Pawn::isSquarePotentiallyMoved(Square square_to_check) {
    switch (this->getSign()) {
        case WHITE:
            return this->position.getRow() - 1 == square_to_check.getRow()
                   && (this->position.getCol() - 1 == square_to_check.getCol()
                   || this->position.getCol() + 1 == square_to_check.getCol());
        case BLACK:
            return this->position.getRow() + 1 == square_to_check.getRow()
                   && (this->position.getCol() - 1 == square_to_check.getCol()
                   || this->position.getCol() + 1 == square_to_check.getCol());
    }
}

PieceTag Pawn::getTag() {
    return PAWN;
}

bool Pawn::isSquareLegal(Square square_to_check, Piece *piece_on_square) {
    //Handles the Captures
    if (Piece::isSquareLegal(square_to_check, piece_on_square) && piece_on_square != nullptr) {
        if (piece_on_square->getSign() != this->getSign()) {
            return true;
        }
    }

    //Handles the movement
    switch (this->getSign()) {
        case WHITE:{
            if (piece_on_square == nullptr && this->position.createSquareRelativeTo(-1, 0) == square_to_check){
                return true;
            }
            if (this->position.getRow() == SECOND_ROW_WHITE_PAWNS && piece_on_square == nullptr
                && this->position.createSquareRelativeTo(-2, 0) == square_to_check){
                return true;
            }
            break;
        }
        case BLACK:{
            if (piece_on_square == nullptr && this->position.createSquareRelativeTo(1, 0) == square_to_check){
                return true;
            }
            if (this->position.getRow() == SECOND_ROW_BLACK_PAWNS && piece_on_square == nullptr
                && this->position.createSquareRelativeTo(2, 0) == square_to_check){
                return true;
            }
        }
    }
    return false;
}

bool Pawn::checkMove(Square square_to_check, Game &game) {
    if (this->isSquareLegal(square_to_check, game.getPieceFromBoard(square_to_check)))
        return !(this->isCheckHappening(square_to_check, game));
    return false;
}

bool Pawn::isControllingSquare(Square square_to_check, Game &game) {
    if (!isProtectingItself(square_to_check)) {
        if (isSquareInsideBoard(square_to_check)) {
            if (this->isSquarePotentiallyMoved(square_to_check)) {
                return true;
            }
        }
    }
    return false;}






