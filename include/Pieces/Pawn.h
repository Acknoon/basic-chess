//
// Created by algo on 22/04/2021.
//

#ifndef CHESSEXERCISE_PAWN_H
#define CHESSEXERCISE_PAWN_H


#include "../Piece.h"

/**
 * A unique piece in chess that can only capture other pieces 1 square in diagonal,
 * from the direction it's moving towards. A pawn has special moves.
 * such as at the start of the game a pawn can move 2 squares up instead of 1,
 * then it can only move 1 square once the special move been used.
 */
class Pawn: public Piece {
public:
    /**
     * @param index_row row position on the chess board
     * @param index_col collum position on the chess board
     * @param color_sign the pawn color belonging to what player being played
     */
    Pawn(int index_row, int index_col, Colour color_sign);

    /**
     * checks all the specific conditions for the pawn to move to,
     * checks the direction of the pawn if it can move forwards or capture diagonally
     * @param square_to_check chosen for the pawn to move to
     * @param piece_on_square the piece that is located on the square that the pawn wants to move to.
     * @return true when the pawn can capture or move to the square.
     */
    bool isSquareLegal(Square square_to_check, Piece *piece_on_square) override;

    /**
     * checks if the moves the pawns can move to aren't blocked and if the squares he can captures have pieces on.
     * @param square_to_check the square that the pawn can capture or move to.
     * @param game reference, gives access to the chess board and pieces on the board.
     * @return true if pawn can make the move to the square.
     */
    bool checkMove(Square square_to_check, Game &game) override;

    /**
     * checks the squares if the pawn can legally capture a piece in front of it.
     * @param square_to_check the square chosen for pawn to move
     * @return true if mathematically the pawn can move to potentially.
     */
    bool isSquarePotentiallyMoved(Square square_to_check) override;

    /**
     * @return The 'p' char that represents the Pawn
     */
    PieceTag getTag() override;

    /**
     * Calculates if the pawn has presence or control over the square
     * @param square_to_check gets calculated if pawn can control.
     * @param game reference, gives access to the chess board and pieces on the board.
     * @return true if the pawn can potentially move to
     */
    bool isControllingSquare(Square square_to_check, Game &game) override;
};


#endif //CHESSEXERCISE_PAWN_H
