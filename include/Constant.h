//
// Created by algo on 05/05/2021.
//

#ifndef CHESSEXERCISE_CONSTANT_H
#define CHESSEXERCISE_CONSTANT_H

enum Colour{WHITE=1, BLACK=-1};
enum PieceTag{KING='k', QUEEN='q', ROOK='r', BISHOP='b', KNIGHT='n', PAWN='p'};
enum TextMoveSquare{MOVING_PIECE, DESTINATION_SQUARE};
enum CheckStatus{DOUBLE_CHECK=2, CHECK=1, NO_CHECK=0};

const int CHESS_BOARD_LENGTH = 8;
const int FIRST_ROW_WHITE_PIECES = 7;
const int SECOND_ROW_WHITE_PAWNS = 6;
const int LAST_ROW_BLACK_PIECES = 0;
const int SECOND_ROW_BLACK_PAWNS = 1;


#endif //CHESSEXERCISE_CONSTANT_H
