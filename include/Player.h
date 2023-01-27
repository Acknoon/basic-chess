//
// Created by algo on 22/04/2021.
//

#ifndef CHESSEXERCISE_PLAYER_H
#define CHESSEXERCISE_PLAYER_H

#include <iostream>
#include "Piece.h"
#include "King.h"
using namespace std;

class Player {
private:
    string name;
    Colour color_sign;
    list<Piece *> list_pieces;
    King *king;

public:
    /**
     * Creates the player tha contains a color that the player plays as and a list of pieces that he owns.
     */
    explicit Player(Colour color_piece);

    /**
     * deletes every piece that the player owns.
     */
    ~Player();

    /**
     * @return King of the player
     */
    King *getKing() const;

    /**
     * assignable King to the game
     * @param newKing the new allocated King in the game.
     */
    void addKing(King *newKing);

    /**
     * @param new_name name of the player being declared must be string
     */
    void declareName(string& new_name);

    /**
     * @return a name of the player.
     */
    string getName();

    /**
     * @return a reference to a list of pieces belongs to the player.
     */
    list<Piece*>& getListOfPieces();

    /**
     * @return a sign that the player plays as (White or Black)
     */
    Colour getColorSign() const;

    /**
     * @param new_piece added to the list of pieces
     */
    void addPiece(Piece *new_piece);

    /**
     * @param piece removed from the list and deleted from the memory as well, used when the piece is captured.
     */
    void removePiece(Piece *piece);
};


#endif //CHESSEXERCISE_PLAYER_H
