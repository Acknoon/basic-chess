//
// Created by algo on 22/04/2021.
//

#ifndef CHESSEXERCISE_GAME_H
#define CHESSEXERCISE_GAME_H

#include "Square.h"
#include "Player.h"
#include "Parser.h"
#include "PrintBoard.h"
#include "Pawn.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"

class Game {
private:
    Player *white;
    Player *black;
    Player *current_turn; // pointer that doesn't have allocated memory.
    Piece *chess_board[CHESS_BOARD_LENGTH][CHESS_BOARD_LENGTH]{};
    bool check;

    /**
     * fills the board with pawns and pieces and nullptr on emprty squares
     */
    void fillPiecesToBoard();

    /**
     * Fills the Big variety of pieces on the first and last row
     * @param player Player to declare ownership on the pieces.
     * @param place_on_board the coordinates on the board
     */
    void fillUniquePiecesToBoard(Player* player, Square place_on_board);

    /**
     * executes moves on the board and removes the piece if it was captured from the game.
     * @param moving_piece the Piece that is about to move
     * @param square the destination square for the piece to move into.
     */
    void doMove(Piece *moving_piece, Square square);

public:
    /**
     * Constructor
     */
    Game();

    /**
     * Destructor
     */
    ~Game();

    /**
     * function that runs the game on the Compiler.
     */
    void run();

    /**
     * Switches turn between 2 players,
     * the current_turn is the variable that keeps track of the turns in the game.
     */
    void switchTurn();

    /**
     * checks if the move that been submitted by the player is legal by the rules of the game and plays the move,
     * updates the Matrix when the move is legal.
     * @param the_square_with_piece the selected piece by the player the first 2 character when entering the move.
     * @param to_move_to the last 2 characters entered by the player that is the destination square for that piece.
     * @return true if the move is legal, false if the move wasn't made.
     */
    bool playMove(Square the_square_with_piece, Square to_move_to);

    /**
     * @param square_on_board the square coordinates on the board
     * @return extracted piece from the board,
     * can be null if the the square coordinates pointed on empty square with no piece.
     */
    Piece* getPieceFromBoard(Square square_on_board);

    /**
     * @param square_on_board the square coordinates on the chess board
     * @param piece submitted piece into the chessboard, SHOULD ONLY USE: when applying a move
     */
    void setPieceOnBoard(Square square_on_board, Piece* piece);

    /**
     * @return The opponent Player of the current_turn Player
     */
    Player *getOpponent();

    /**
     * @param ally_player color of the player
     * @return the opponent Player of the match
     */
    Player *getOpponent(Colour ally_player);

    /**
     * @param sign color pieces
     * @return returns the player that plays with this color.
     */
    Player *getPlayer(Colour sign);

    /**
     * @return if there is check being applied on the player that needs to move.
     */
    bool isCheck() const;

    /**
     * Shows the GUI of the Board
     */
    void printBoard();

    /**
     * checks if any piece is able to directly attack the king.
     */
    void detectPlayerInCheck();
};


#endif //CHESSEXERCISE_GAME_H
