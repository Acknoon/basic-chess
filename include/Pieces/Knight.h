//
// Created by algo on 22/04/2021.
//

#ifndef CHESSEXERCISE_KNIGHT_H
#define CHESSEXERCISE_KNIGHT_H


#include "../Piece.h"

/**
 * A simple piece that has a unique movement, can't get interrupted in the path and jumps 'L' shaped moves
 */
class Knight : public Piece {
private:

public:
    /**
     * @param index_row row position of the knight relative to the chess board.
     * @param index_col collum position of the knight relative to the chess board.
     * @param color_sign the color of the player.
     */
    Knight(int index_row, int index_col, Colour color_sign);

    /**
     * Checks if the knight can legally move 'L'
     * @param square_to_check checks if the square chosen is legal for the knight to jump.
     * @param game reference, gives access to the chess board and pieces on the board.
     * @return true if the knight can legally jump to the square.
     */
    bool checkMove(Square square_to_check, Game &game) override;

    /**
     * Checks the 8 possible squares that knight can jump to
     * @param square_to_check the square that is checked
     * @return true if the knight moves 'L' shape to the square.
     */
    bool isSquarePotentiallyMoved(Square the_square_to_check) override;

    /**
     * @return The 'n' char that represents the Knight
     */
    PieceTag getTag() override;

    /**
     * Calculates if the knight has presence or control over the square
     * @param square_to_check gets calculated if knight can control.
     * @param game reference, gives access to the chess board and pieces on the board.
     * @return true if the knight can potentially move to
     */
    bool isControllingSquare(Square square_to_check, Game &game) override;
};


#endif //CHESSEXERCISE_KNIGHT_H
