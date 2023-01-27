#ifndef CHESSEXERCISE_SQUARE_H
#define CHESSEXERCISE_SQUARE_H

#include <iostream>
using namespace std;

class Square {
private:
    int row_index;
    int col_index;
public:
    /**
     * creates a square which is a location on the chess board.
     * @param row_position defines which row on the chess board.
     * @param col_position defines which collum on the chess board.
     */
    Square(int row_position, int col_position);

    /**
     * @return the row position on the board.
     */
    int getRow() const;

    /**
     * @return the collum position on the board.
     */
    int getCol() const;

    /**
     * @param row row iterations away from the THIS square
     * @param col collum iterations away from the THIS square
     * @return a new Square relative to THIS square in distance
     */
    Square createSquareRelativeTo(int row, int col) const;

    /**
     * adds values of position to THIS square, changing it's position
     * @param row value adding to the current row value can be negative as well
     * @param col value adding to the current collum value can be negative as well
     */
    void addToSquare(int row, int col);

    /**
     * @return checks if the other_square has the same coordinates value as THIS square.
     */
    bool operator==(const Square &other_square) const;

    /**
     * @return assigns and creates new Square that is the exact same as the other_square.
     */
    Square &operator=(const Square &other_square);
};


#endif //CHESSEXERCISE_SQUARE_H
