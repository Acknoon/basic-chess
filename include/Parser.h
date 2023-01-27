//
// Created by algo on 22/04/2021.
//

#ifndef CHESSEXERCISE_PARSER_H
#define CHESSEXERCISE_PARSER_H
#include "Square.h"
#include "Constant.h"

const int ROW_TEXT_POSITION = 1;
const int COL_TEXT_POSITION = 0;

class Parser {
private:
    /**
     * @param index_collum_on_board the collum coordinate on the chess board that is a letter
     * @return the index on for the matrix array to pull out the correct coordinate
     */
    static int translateCollumIndex(char index_collum_on_board);

    /**
     * @param index_row_on_board the row coordinate on the chess board that is a number
     * @return the index on for the matrix array to pull out the correct coordinate
     */
    static int translateRowIndex(char index_row_on_board);

public:
    /**
     * splits the string of 2 squares to 1 square of string
     * example: "A2A4" ---> "A2" Or "A4"
     * @param move the string that is move
     * @param which_square the mode of piece Square or the destination square for the piece.
     * @return string of Piece square or the destination square.
     */
    static string splitMoveToSquare(const string &move, TextMoveSquare which_square);

    /**
     * Translate the player input String to the Square on the chess board
     * @param square the string that is a player input string
     * @return a square on the chess board
     */
    static Square getSquareInput(const string &square);

    /**
     * @param player_type what color pieces the player will play as.
     * @return A name of the player inputted.
     */
    static string inputName(Colour player_type);

    /**
     * A full input of a name from a player in string.
     * @param name of a player.
     * @return a move being inputted by the player.
     */
    static string inputMove(const string &name);

    /**
     * prints a message in read that says Check!
     */
    static void printCheck();

    /**
     * prints a message that the player did an illegal move
     */
    static void printIllegalMove();

    /**
     * prints a message of the winner of the game.
     * @param player_name the name of the winner.
     */
    static void printWinner(const string &player_name);
};

#endif //CHESSEXERCISE_PARSER_H
