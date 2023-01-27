//
// Created by algo on 22/04/2021.
//

#include "Rook.h"
#include "Game.h"


Rook::Rook(int index_row, int index_col, Colour color_sign) : Piece(Square(index_row, index_col),
                                                                    color_sign) {}

bool Rook::isSquarePotentiallyMoved(Square square_to_check) {
    return (this->position.getRow() == square_to_check.getRow())
            || (this->position.getCol() == square_to_check.getCol());
}

PieceTag Rook::getTag() {
    return ROOK;
}

bool Rook::checkMove(Square square_to_check, Game &game) {
    if (this->isSquareLegal(square_to_check, game.getPieceFromBoard(square_to_check)))
        if (this->isPathCleared(square_to_check, game))
            return !(this->isCheckHappening(square_to_check, game));
    return false;
}

bool Rook::isControllingSquare(Square square_to_check, Game &game) {
    if (!isProtectingItself(square_to_check)) {
        if (isSquareInsideBoard(square_to_check)) {
            if (this->isSquarePotentiallyMoved(square_to_check)) {
                if (isPathCleared(square_to_check, game))
                    return true;
            }
        }
    }
    return false;}

