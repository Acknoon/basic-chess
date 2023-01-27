//
// Created by algo on 05/05/2021.
//

#include "PrintBoard.h"

void PrintBoard::drawBoard(Piece *chess_board[CHESS_BOARD_LENGTH][CHESS_BOARD_LENGTH]){
    string letter_coordinates = {"  ABCDEFGH"};
    cout << "\33[32m" << letter_coordinates << "\33[0m" << endl;
    for (int row_index = 0; row_index < CHESS_BOARD_LENGTH; row_index++) {
        cout << "\33[32m" << CHESS_BOARD_LENGTH - row_index << "\33[0m" << " ";
        for (int col_index = 0; col_index < CHESS_BOARD_LENGTH; col_index++) {
            printSquare(row_index, col_index, chess_board[row_index][col_index]);
        }
        cout << "\33[32m" << " " << CHESS_BOARD_LENGTH - row_index << "\33[0m" << endl;
    }
    cout << "\33[32m" << letter_coordinates << "\33[0m" << endl;
}

void PrintBoard::printSquare(int index_row, int index_col, Piece *piece_on_square) {
    if (index_row % 2 == 0) {
        if (index_col % 2 == 0) {
            cout << "\033[" << translateSignToUnix(piece_on_square) <<
                 LIGHT_SQUARE << translateTagToUnix(piece_on_square) << "\033[0m";
        } else {
            cout << "\033[" << translateSignToUnix(piece_on_square) <<
                 DARK_SQUARE << translateTagToUnix(piece_on_square) << "\033[0m";
        }
    } else if (index_col % 2 == 0) {
        cout << "\033[" << translateSignToUnix(piece_on_square) <<
             DARK_SQUARE << translateTagToUnix(piece_on_square) << "\033[0m";
    } else {
        cout << "\033[" << translateSignToUnix(piece_on_square) <<
             LIGHT_SQUARE << translateTagToUnix(piece_on_square) << "\033[0m";
    }
}

string PrintBoard::translateTagToUnix(Piece* piece_tag) {
    if (piece_tag != nullptr) {
        switch (piece_tag->getTag()) {
            case KING: {
                return C_KING;
            }
            case QUEEN: {
                return C_QUEEN;
            }
            case ROOK: {
                return C_ROOK;
            }
            case BISHOP: {
                return C_BISHOP;
            }
            case KNIGHT: {
                return C_KNIGHT;
            }
            case PAWN: {
                return C_PAWN;
            }
        }
    }
    return " ";
}

string PrintBoard::translateSignToUnix(Piece* piece_on_square) {
    if (piece_on_square != nullptr){
        switch (piece_on_square->getSign()) {
            case WHITE:{
                return WHITE_TEXT;
            }
            case BLACK:{
                return BLACK_TEXT;
            }
        }
    }
    return EMPTY_TEXT;
}
