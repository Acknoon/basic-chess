//
// Created by algo on 06/05/2021.
//
#include <unordered_map>
#include "Parser.h"

int Parser::translateCollumIndex(char index_collum_on_board) {
    return index_collum_on_board - 'A';
}

int Parser::translateRowIndex(char index_collum_on_board) {
    return index_collum_on_board - '0';
}


string Parser::inputName(Colour type_player) {
    string player_name;
    switch (type_player) {
        case WHITE:{
            cout << "\033[32m" << "Enter white player:" << "\033[0m" << endl;
            break;
        }
        case BLACK:{
            cout << "\033[32m" << "Enter white player:" << "\033[0m" << endl;
        }
    }
    getline(cin, player_name);
    cout << endl;
    return player_name;
}

string Parser::inputMove(const string& name) {
    string move_in_string;
    cout << "\033[32m" << name << ": Enter your move here:" << "\033[0m" << endl;
    getline(cin, move_in_string); // should get letter number letter number string A-H letters and 1-8 letters
    cout << endl;
    return move_in_string;
}

void Parser::printCheck() {
    cout << "\033[0;41m" << "Check!" << "\033[0m" << endl;
}

void Parser::printIllegalMove() {
    cout << "\033[0;41m" << "illegal move" << "\033[0m" << endl;
}

void Parser::printWinner(const string& player_name) {
    cout << "\033[0;44m" << player_name << " won!" << "\033[0m" << endl;
}

Square Parser::getSquareInput(const string& square) {
    return Square(CHESS_BOARD_LENGTH - translateRowIndex(square.at(ROW_TEXT_POSITION)),
                  translateCollumIndex(square.at(COL_TEXT_POSITION)));
}

string Parser::splitMoveToSquare(const string &move, TextMoveSquare which_square) {
    switch (which_square) {
        case MOVING_PIECE:{
            return move.substr(0, 2);
        }
        case DESTINATION_SQUARE:{
            return move.substr(2,2);
        }
    }
}