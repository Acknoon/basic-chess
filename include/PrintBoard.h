//
// Created by algo on 05/05/2021.
//

#ifndef CHESSEXERCISE_PRINTBOARD_H
#define CHESSEXERCISE_PRINTBOARD_H

#include "Piece.h"
#include "Constant.h"

const string C_KING = "\u265A";
const string C_QUEEN = "\u265B";
const string C_ROOK = "\u265C";
const string C_BISHOP = "\u265D";
const string C_KNIGHT = "\u265E";
const string C_PAWN = "\u265F";

const string WHITE_TEXT = "97";
const string BLACK_TEXT = "30";
const string EMPTY_TEXT = "0";

const string DARK_SQUARE = ";42m";
const string LIGHT_SQUARE = ";46m";

class PrintBoard {
private:
    /**
     * prints a square of the board as a whole, color of the square, piece and color of the piece
     * @param index_row the coordinate row of the board
     * @param index_col the coordinate collum of the board
     * @param piece_on_square the piece that is located on the coordinate could be null then the square is empty.
     */
    static void printSquare(int index_row, int index_col, Piece *piece_on_square);

    /**
     * @param piece_tag the piece type
     * @return a string of the unix code for the piece, shows it as an image code..
     */
    static string translateTagToUnix(Piece *piece_tag);

    /**
     * @param piece_on_square a color of piece
     * @return translated to unix code in string could be black or white color,
     * as well as empty if the square is empty.
     */
    static string translateSignToUnix(Piece *piece_on_square);

public:
    /**
     * draws the board in the compiler by each cell on the board.
     * @param chess_board the current chess board position
     */
    static void drawBoard(Piece *chess_board[CHESS_BOARD_LENGTH][CHESS_BOARD_LENGTH]);
};


#endif //CHESSEXERCISE_PRINTBOARD_H
