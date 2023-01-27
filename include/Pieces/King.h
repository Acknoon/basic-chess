//
// Created by algo on 22/04/2021.
//

#ifndef CHESSEXERCISE_KING_H
#define CHESSEXERCISE_KING_H


#include "Piece.h"

class Player;

/**
 * a King is a special piece where if it gets capture the player loses the game.
 */
class King : public Piece {
private:

public:
    /**
     * @param index_row which row on the chess board the King located
     * @param index_col which collum on the chess board King located
     * @param color_sign decides which Player the King belongs to (White or Black)
     */
    King(int index_row, int index_col, Colour color_sign);

    /**
     * checks if the move is legal for the king to move to where king can move only 1 square in every direction
     * however the king can't move into a square that is controlled by the enemy pieces.
     * @param square_to_check desired square for the king to move to legally.
     * @param game reference, gives access to the chess board and pieces on the board.
     * @return true if the king is able to move to that square.
     */
    bool checkMove(Square square_to_check, Game &game) override;

    /**
     * calculates mathematically if the King can move to the square
     * @param square_to_check the square chosen for the king to move to
     * @return true if it's potentially possible for the king to move to the square, false otherwise.
     */
    bool isSquarePotentiallyMoved(Square square_to_check) override;

    /**
     * @return a chat 'k' representing the king
     */
    PieceTag getTag() override;

    /**
     * @param square_to_check a square to check if the king can control it
     * @param game reference, gives access to the chess board and pieces on the board.
     * @return true if the can control the square, false otherwise.
     */
    bool isControllingSquare(Square square_to_check, Game &game) override;

    /**
     * calculates if the king can escape the check
     * @param game reference, gives access to the chess board and pieces on the board.
     * @return true if the king can't escape from the check therefore it's CheckMate! game over for the player.
     * false otherwise.
     */
    bool isCheckMate(Game &game);

    /**
     * checks every piece if it checks the King
     * @param game reference, gives access to the chess board and pieces on the board.
     * @return true if there is at least 1 piece that checks the king
     */
    bool detectCheck(Game &game);

    /**
     * returns a list of maximum size of 2 that holds the pieces that check the king
     * @param game reference, gives access to the chess board and pieces on the board.
     * @return a list of pieces that are attacking the king.
     */
    list<Piece *> getEnemyCheckingPieces(Game &game);

    /**
     * checks all the squares that the king is able to move if they are legal
     * @param game reference, gives access to the chess board and pieces on the board.
     * @return true if the king is able to move to at least 1 square false if there are no squares the king can move to.
     */
    bool isKingAbleToMove(Game &game);

    /**
     * checks if there any ally piece can eliminate the threatening piece
     * @param piece that attacks this king
     * @param game reference, gives access to the chess board and pieces on the board.
     * @return true if it's possible to capture the attacking piece.
     */
    bool isPossibleToEliminateThreat(Piece *piece, Game &game);

    /**
     * checks if there is any ally piece that can block the attack towards the king
     * @param piece that attacks this king
     * @param game reference, gives access to the chess board and pieces on the board.
     * @return trie when it's possible to to block the attack.
     */
    bool isPossibleToBlockThreat(Piece *piece, Game &game);

    /**
     * @param threat the piece that attacks this king
     * @param game reference, gives access to the chess board and pieces on the board.
     * @return a list of squares that lead to the piece which attacks the king and checks it
     */
    list<Square> getPathSquaresToThreat(Piece *threat, Game &game);
};


#endif //CHESSEXERCISE_KING_H
