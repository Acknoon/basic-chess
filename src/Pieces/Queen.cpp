//
// Created by algo on 22/04/2021.
//

#include "Queen.h"
#include "Game.h"


Queen::Queen(int index_row, int index_col, Colour color_sign) : Piece(Square(index_row, index_col),
                                                                      color_sign) {}

bool Queen::isSquarePotentiallyMoved(Square square_to_check) {
    return (this->position.getRow() == square_to_check.getRow())
           || (this->position.getCol() == square_to_check.getCol())
           || abs(square_to_check.getRow() - this->position.getRow()) ==
              abs(square_to_check.getCol() - this->position.getCol());
}

PieceTag Queen::getTag() {
    return QUEEN;
}

bool Queen::checkMove(Square square_to_check, Game &game) {
    if (this->isSquareLegal(square_to_check, game.getPieceFromBoard(square_to_check)))
        if (this->isPathCleared(square_to_check, game))
            return !(this->isCheckHappening(square_to_check, game));
    return false;
}

bool Queen::isControllingSquare(Square square_to_check, Game &game) {
    if (!isProtectingItself(square_to_check)) {
        if (isSquareInsideBoard(square_to_check)) {
            if (this->isSquarePotentiallyMoved(square_to_check)) {
                if (isPathCleared(square_to_check, game))
                    return true;
            }
        }
    }
    return false;}
