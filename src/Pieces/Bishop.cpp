//
// Created by algo on 22/04/2021.
//

#include "Bishop.h"
#include "Game.h"

Bishop::Bishop(int index_row, int index_col, Colour color_sign) : Piece(Square(index_row, index_col),
                                                                        color_sign) {}

bool Bishop::isSquarePotentiallyMoved(Square square_to_check) {
    return abs(square_to_check.getRow() - this->position.getRow()) ==
           abs(square_to_check.getCol() - this->position.getCol());
}

PieceTag Bishop::getTag() {
    return BISHOP;
}

bool Bishop::checkMove(Square square_to_check, Game &game) {
    if (this->isSquareLegal(square_to_check, game.getPieceFromBoard(square_to_check)))
        if (this->isPathCleared(square_to_check, game))
            return !(this->isCheckHappening(square_to_check, game));
    return false;
}

bool Bishop::isControllingSquare(Square square_to_check, Game &game) {
    if (!isProtectingItself(square_to_check)) {
        if (isSquareInsideBoard(square_to_check)) {
            if (this->isSquarePotentiallyMoved(square_to_check)) {
                if (isPathCleared(square_to_check, game))
                    return true;
            }
        }
    }
    return false;
}
