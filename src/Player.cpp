//
// Created by algo on 22/04/2021.
//

#include "Player.h"

Player::Player(Colour color_piece) : color_sign(color_piece){
    this->king = nullptr;
    this->name = {};
}

Player::~Player() {
    delete this->king;
    while (!list_pieces.empty()) {
        delete list_pieces.back();
        list_pieces.pop_back();
    }
}

King *Player::getKing() const {
    return this->king;
}

void Player::addKing(King *newKing) {
    this->king = newKing;
}

Colour Player::getColorSign() const {
    return this->color_sign;
}

void Player::addPiece(Piece *new_piece) {
    this->list_pieces.push_front(new_piece);
}

void Player::removePiece(Piece *piece) {
    if (piece != nullptr) {
        this->list_pieces.remove(piece);
        delete piece;

    }
}

void Player::declareName(string &new_name) {
    this->name = new_name;
}

string Player::getName() {
    return this->name;
}

list<Piece*>& Player::getListOfPieces() {
    return list_pieces;
}
