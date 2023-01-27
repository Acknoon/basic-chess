//
// Created by algo on 22/04/2021.
//

#ifndef CHESSEXERCISE_ROOK_H
#define CHESSEXERCISE_ROOK_H


#include "../Piece.h"

class Rook : public Piece {
private:

public:
    /**
     * @param index_row row position of the rook relative to the chess board.
     * @param index_col collum position of the rook relative to the chess board.
     * @param color_sign the color of the player.
     */
    Rook(int index_row, int index_col, Colour color_sign);

    /**
     * @param square_to_check checks if the square chosen is legal for the rook to move,
     *  when it doesn't get blocked on it's path towards that square
     * @param game reference, access to the board and pieces.
     * @return true if the rook can legally move to the square. false otherwise.
     */
    bool checkMove(Square square_to_check, Game &game) override;

    /**
     * calculates mathematically if the rook can move to a certain square,
     * however doesn't calculate if there is a piece on it's path to a square.
     * @param the_square_to_check desired square for the rook to move to.
     * @returntrue if it's potentially possible for the rook to move to that square., false otherwise.
     */
    bool isSquarePotentiallyMoved(Square the_square_to_check) override;

    /**
     * @return a tag 'r' in char to represent the rook.
     */
    PieceTag getTag() override;

    /**
     * calculated if the rook can reach a certain square without getting blocked in it's path towards the square.
     * @param square_to_check desired square for the rook to move to.
     * @param game reference, gives access to the chess board and pieces on the board.
     * @return true if nothing blocks the rook on the path and it's still in the chess board.
     */
    bool isControllingSquare(Square square_ti_check, Game &game) override;
};


#endif //CHESSEXERCISE_ROOK_H
