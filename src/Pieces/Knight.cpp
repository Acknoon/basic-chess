//
// Created by algo on 22/04/2021.
//

#include "Knight.h"
#include "Game.h"


Knight::Knight(int index_row, int index_col, Colour color_sign) : Piece(Square(index_row, index_col),
                                                                        color_sign) {}

bool Knight::isSquarePotentiallyMoved(Square square_to_check) {
    return (this->position == square_to_check.createSquareRelativeTo(-2, -1)) ||
           (this->position == square_to_check.createSquareRelativeTo(-2, 1)) ||
           (this->position == square_to_check.createSquareRelativeTo(2, -1)) ||
           (this->position == square_to_check.createSquareRelativeTo(2, 1)) ||
           (this->position == square_to_check.createSquareRelativeTo(-1, -2)) ||
           (this->position == square_to_check.createSquareRelativeTo(1, -2)) ||
           (this->position == square_to_check.createSquareRelativeTo(-1, 2)) ||
           (this->position == square_to_check.createSquareRelativeTo(1, 2));
}

PieceTag Knight::getTag() {
    return KNIGHT;
}

bool Knight::checkMove(Square square_to_check, Game &game) {
    if (this->isSquareLegal(square_to_check, game.getPieceFromBoard(square_to_check)))
        return !(this->isCheckHappening(square_to_check, game));
    return false;
}

bool Knight::isControllingSquare(Square square_to_check, Game &game) {
    if (!isProtectingItself(square_to_check)) {
        if (isSquareInsideBoard(square_to_check)) {
            if (this->isSquarePotentiallyMoved(square_to_check)) {
                return true;
            }
        }
    }
    return false;
}
