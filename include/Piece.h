//
// Created by algo on 22/04/2021.
//

#ifndef CHESSEXERCISE_PIECE_H
#define CHESSEXERCISE_PIECE_H
#include "Square.h"
#include "Constant.h"
#include <list>

class Game; //a way for the piece to know that Game exists.

/**
 * Piece is an abstract class that is getting Inherited from King, Bishop, Queen, Knight, Pawn, Rook Pieces.
 */
class Piece {
protected:
    Square position;
    Colour color_sign;
    bool is_checking;

    /**
     * @param the_square_to_check calculates mathematically this square can potentially be reached
     * @return true if the the square can be reached, false otherwise.
     */
    virtual bool isSquarePotentiallyMoved(Square the_square_to_check) = 0;

    /**
     * checks if the the square is not outside of the board coordinates,
     * the square isn't occupied by ally pieces.
     * @param square_to_check the square where THIS piece checks if it can legally move to
     * @param piece_on_square a piece located on the destination square that THIS piece check
     * @return true if the move is legal to move to by a piece.
     */
    virtual bool isSquareLegal(Square square_to_check, Piece *piece_on_square);

    /**
     * checks for the Piece Queen, bishop and rook if their path is clear for them to not jump over pieces.
     * @param square_to_check destination square for the pathing pieces to move
     * @param game reference gives access to the chess board and pieces on the board.
     * @return true if the there is no pieces in between the the piece and a square.
     */
    bool isPathCleared(Square square_to_check, Game &game);

    /**
     * small that checks if a piece doesn't protect itself and prevent the king to capture it
     * @param square_to_check the square the piece stands on
     * @return true if the piece and square are the same position on the board.
     */
    bool isProtectingItself(Square square_to_check);
public:

    /**
     * @param index_row which row on the chess board
     * @param index_col which collum on the chess board
     * @param color_sign decides which Player the piece belongs to (White or Black)
     */
    Piece(int index_row, int index_col, Colour color_piece);

    /**
     * @param position_on_board which square on the chess board the piece located on.
     * @param color_piece decides which Player the piece belongs to (White or Black)
     */
    Piece(Square position_on_board, Colour color_piece);

    /**
     * @return color sign that the piece belongs to (Black or White)
     */
    Colour getSign();

    /**
     * @param check_status changes when the piece is checking the enemy king or not.
     */
    void setCheck(bool check_status);

    /**
     * @return true when the piece is checking the enemy king.
     */
    bool isChecking() const;

    /**
     * @return returns a Square that contains row and collum indexes related to the chess board.
     */
    Square getPosition() const;

    /**
     * @param square new Square position on the chess board, changes the coordinate of a piece related to the board.
     */
    void setPosition(Square square);

    /**
     * @param square_to_check position that is checked if it's inside the chess board coordinates.
     * @return true when the square is inside the chess board coordinates.
     */
    static bool isSquareInsideBoard(Square square_to_check);

    /**
     * Simulates a move on the board to check if the move is legal from check.
     * @param square_to_check the square the the piece moves in simulation.
     * @param game reference, gives access to the chess board and other pieces.
     * @return if the move is legal to apply
     */
    bool isCheckHappening(Square square_to_check, Game &game);

    /**
     * @return A unique tag for the specific piece, a way to define what type of piece is used.
     */
    virtual PieceTag getTag() = 0;

    /**
     * method that checks fully if the move is legal in chess rules
     * for the piece to move to a certain square that was chosen by the player.
     * @param square_to_check the square chosen by the player for this piece.
     * @param game reference, gives access to the chess board and other pieces.
     * @return true if the move is legal and can be played on the board
     */
    virtual bool checkMove(Square square_to_check, Game &game) = 0;

    /**
     * method that checks if a piece can control a square,
     * this piece has presence or threat level on that certain square.
     * @param square_to_check square that is being controlled or "looking at"
     * @param game reference, give access to the pieces and chess board.
     * @return true if the piece has presence over a square, false otherwise.
     */
    virtual bool isControllingSquare(Square square_to_check, Game& game) = 0;
};


#endif //CHESSEXERCISE_PIECE_H
