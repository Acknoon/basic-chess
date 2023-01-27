//
// Created by algo on 22/04/2021.
//

#ifndef CHESSEXERCISE_QUEEN_H
#define CHESSEXERCISE_QUEEN_H


#include "../Piece.h"

/**
 * Queen is the most powerful piece that can move horizontally, vertically and diagonally
 */
class Queen : public Piece {
private:

public:
    /**
     * @param index_row row position of the queen relative to the chess board.
     * @param index_col collum position of the queen relative to the chess board.
     * @param color_sign the color of the player.
     */
    Queen(int index_row, int index_col, Colour color_sign);

    /**
     * checks if the queen can move to a certain square without getting blocked by a piece on the way.
     * @param square_to_check checks if the square chosen is legal for the queen to move to.
     * @param game reference, gives access to the chess board and pieces on the board.
     * @return true if the queen can legally move to the square.
     */
    bool checkMove(Square square_to_check, Game &game) override;

    /**
     * calculates mathematically if the queen can move to a certain square,
     * however doesn't calculate if there is a piece on it's path to a certain square.
     * @param the_square_to_check desired square for the queen to move to.
     * @returntrue if it's potentially possible for the queen to move to that square., false otherwise.
     */
    bool isSquarePotentiallyMoved(Square the_square_to_check) override;

    /**
     * @return a tag 'q' in char to represent the queen.
     */
    PieceTag getTag() override;

    /**
     * calculated if the queen can reach a certain square without getting blocked in it's path towards the square.
     * @param square_to_check desired square for the queen to move to.
     * @param game reference, gives access to the chess board and pieces on the board.
     * @return true if nothing blocks the queen on the path and it's still in the chess board.
     */
    bool isControllingSquare(Square square_to_check, Game &game) override;
};


#endif //CHESSEXERCISE_QUEEN_H
