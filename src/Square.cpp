//
// Created by algo on 22/04/2021.
//

#include "Square.h"

Square::Square(int row_position, int col_position): row_index(row_position), col_index(col_position) {}

int Square::getRow() const {
    return this->row_index;
}

int Square::getCol() const {
    return this->col_index;
}

bool Square::operator==(const Square &other_square) const{
    return this->col_index == other_square.col_index && this->row_index == other_square.row_index;
}

Square &Square::operator=(const Square &other_square) {
    this->col_index = other_square.getCol();
    this->row_index = other_square.getRow();
    return *this;
}

Square Square::createSquareRelativeTo(int row, int col) const {
    return Square(this->row_index + row, this->col_index + col);
}

void Square::addToSquare(int row, int col) {
    this->row_index += row;
    this->col_index += col;
}

