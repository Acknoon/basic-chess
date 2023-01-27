//
// Created by algo on 22/04/2021.
//

#ifndef CHESSEXERCISE_BISHOP_H
#define CHESSEXERCISE_BISHOP_H


#include "../Piece.h"

/**
 * A piece that can move diagonally around the board.
 */
class Bishop : public Piece {
private:

public:
    /**
     * @param index_row which row on the chess board the Bishop located
     * @param index_col which collum on the chess board Bishop located
     * @param color_sign decides which Player the bishop belongs to (White or Black)
     */
    Bishop(int index_row, int index_col, Colour color_sign);

    /**
     * Process the square that was chosen for the Bishop if it can diagonally move to the square.
     * @param square_to_check The position that was chosen for the Bishop to move to
     * @param game reference, gives access to the chess board and pieces on the board.
     * @return true when the move is legal
     */
    bool checkMove(Square square_to_check, Game &game) override;

    /**
     * Calculates if Bishop can move mathematically to the square diagonally
     * @param square_to_check the square that is checked
     * @return true if the bishop moves diagonally to the square.
     */
    bool isSquarePotentiallyMoved(Square square_to_check) override;

    /**
     * @return Character of the Bishop: 'b' or BISHOP
     */
    PieceTag getTag() override;

    /**
     * Calculates if the bishop has presence or control over the square
     * @param square_to_check gets calculated if bishop can control.
     * @param game reference, gives access to the chess board and pieces on the board.
     * @return true if the bishop can have presence on the square and doesn't get interrupted
     */
    bool isControllingSquare(Square square_to_check, Game& game) override;
};


#endif //CHESSEXERCISE_BISHOP_H
