//
// Created by algo on 22/04/2021.
//

#include "Game.h"

Game::Game() {
    this->white = new Player(WHITE);
    this->black = new Player(BLACK);
    this->check = false;
    current_turn = white;
    fillPiecesToBoard();
}

Game::~Game() {
    delete white;
    delete black;
}

void Game::run() {
    //Name Set up!
    string move_in_string, picked_piece, destination_square;
    string white_name = Parser::inputName(WHITE);
    string black_name = Parser::inputName(BLACK);
    white->declareName(white_name);
    black->declareName(black_name);

    while (!current_turn->getKing()->isCheckMate(*this)){
        do {
            printBoard();
            if (check)
                Parser::printCheck();
            move_in_string = Parser::inputMove(current_turn->getName());
            picked_piece = Parser::splitMoveToSquare(move_in_string, MOVING_PIECE);
            destination_square = Parser::splitMoveToSquare(move_in_string, DESTINATION_SQUARE);
        } while(!(playMove(Parser::getSquareInput(picked_piece), Parser::getSquareInput(destination_square))));
    }
    printBoard();
    Parser::printWinner(getOpponent()->getName());
}

bool Game::playMove(Square the_square_with_piece, Square to_move_to) {
    Piece* piece_been_selected = getPieceFromBoard(the_square_with_piece);
    if (piece_been_selected != nullptr) {
        if (piece_been_selected->getSign() == current_turn->getColorSign()) {
            if (piece_been_selected->checkMove(to_move_to, *this)) {
                doMove(piece_been_selected, to_move_to);
                switchTurn();
                detectPlayerInCheck();
                return true;
            }
        }
    }
    Parser::printIllegalMove();
    return false;
}

void Game::switchTurn() {
    this->current_turn = this->current_turn == this->white ? this->black : this->white;
}

Player* Game::getOpponent() {
    return this->current_turn == this->white ? this->black : this->white;
}

Player *Game::getOpponent(Colour ally_player) {
    return ally_player == this->white->getColorSign() ? this->black : this->white;
}

void Game::printBoard() {
    PrintBoard::drawBoard(chess_board);
}


Piece *Game::getPieceFromBoard(Square square_on_board) {
    return chess_board[square_on_board.getRow()][square_on_board.getCol()];
}

// does move for the player that has the turn.
void Game::doMove(Piece *moving_piece, Square square) {
    getOpponent()->removePiece(chess_board[square.getRow()][square.getCol()]);
    chess_board[square.getRow()][square.getCol()] = moving_piece;
    chess_board[moving_piece->getPosition().getRow()][moving_piece->getPosition().getCol()] = nullptr;
    moving_piece->setPosition(square);

}

bool Game::isCheck() const {
    return check;
}



void Game::detectPlayerInCheck() {
    this->check = current_turn->getKing()->detectCheck(*this);
}

Player *Game::getPlayer(Colour sign) {
    return sign == this->white->getColorSign() ? this->white : this->black;}

void Game::fillPiecesToBoard() {
    for (int index_row = 0; index_row < CHESS_BOARD_LENGTH; index_row++) {
        for (int index_col = 0; index_col < CHESS_BOARD_LENGTH; index_col++) {
            switch (index_row) {
                case LAST_ROW_BLACK_PIECES: {
                    fillUniquePiecesToBoard(this->black, Square(index_row, index_col));
                    break;
                }
                case SECOND_ROW_BLACK_PAWNS: {
                    Pawn* newPawn = new Pawn(index_row, index_col, BLACK);
                    this->chess_board[index_row][index_col] = {newPawn};
                    this->black->addPiece(newPawn);
                    break;
                }
                case SECOND_ROW_WHITE_PAWNS: {
                    Pawn* newPawn = new Pawn(index_row, index_col, WHITE);
                    this->chess_board[index_row][index_col] = {newPawn};
                    this->white->addPiece(newPawn);
                    break;
                }
                case FIRST_ROW_WHITE_PIECES: {
                    fillUniquePiecesToBoard(this->white, Square(index_row, index_col));
                    break;
                }
                default: {this->chess_board[index_row][index_col] = {nullptr};}
            }
        }
    }
}

void Game::fillUniquePiecesToBoard(Player* player, Square square_on_board) {
    switch (square_on_board.getCol()) {
        case 0: {
            Rook* newRook = new Rook(square_on_board.getRow(), square_on_board.getCol(), player->getColorSign());
            this->chess_board[square_on_board.getRow()][square_on_board.getCol()] = {newRook};
            player->addPiece(newRook);
            break;
        }
        case 1: {
            auto* newKnight = new Knight(square_on_board.getRow(), square_on_board.getCol(), player->getColorSign());
            this->chess_board[square_on_board.getRow()][square_on_board.getCol()] = {newKnight};
            player->addPiece(newKnight);
            break;
        }
        case 2: {
            auto* newBishop = new Bishop(square_on_board.getRow(), square_on_board.getCol(), player->getColorSign());
            this->chess_board[square_on_board.getRow()][square_on_board.getCol()] = {newBishop};
            player->addPiece(newBishop);
            break;
        }
        case 3: {
            auto* newQueen = new Queen(square_on_board.getRow(), square_on_board.getCol(), player->getColorSign());
            this->chess_board[square_on_board.getRow()][square_on_board.getCol()] = {newQueen};
            player->addPiece(newQueen);
            break;
        }
        case 4: {
            King* newKing = new King(square_on_board.getRow(), square_on_board.getCol(), player->getColorSign());
            this->chess_board[square_on_board.getRow()][square_on_board.getCol()] = {newKing};
            player->addKing(newKing); // keeping king away from the list of pieces.
            break;
        }
        case 5: {
            auto* newBishop = new Bishop(square_on_board.getRow(), square_on_board.getCol(), player->getColorSign());
            this->chess_board[square_on_board.getRow()][square_on_board.getCol()] = {newBishop};
            player->addPiece(newBishop);
            break;
        }
        case 6: {
            auto* newKnight = new Knight(square_on_board.getRow(), square_on_board.getCol(), player->getColorSign());
            this->chess_board[square_on_board.getRow()][square_on_board.getCol()] = {newKnight};
            player->addPiece(newKnight);
            break;
        }
        case 7: {
            Rook* newRook = new Rook(square_on_board.getRow(), square_on_board.getCol(), player->getColorSign());
            this->chess_board[square_on_board.getRow()][square_on_board.getCol()] = {newRook};
            player->addPiece(newRook);
            break;
        }
    }
}

void Game::setPieceOnBoard(Square square_on_board, Piece *piece) {
    chess_board[square_on_board.getRow()][square_on_board.getCol()] = piece;
}
