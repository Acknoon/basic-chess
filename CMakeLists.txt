cmake_minimum_required(VERSION 3.19)
project(ChessExercise)

set(CMAKE_CXX_STANDARD 14)

include_directories(include/Pieces include)

add_executable(ChessExercise src/main.cpp src/Game.cpp include/Game.h include/Parser.h src/Square.cpp include/Square.h src/Player.cpp include/Player.h src/Piece.cpp include/Piece.h src/Pieces/King.cpp include/Pieces/King.h src/Pieces/Pawn.cpp include/Pieces/Pawn.h src/Pieces/Knight.cpp include/Pieces/Knight.h src/Pieces/Bishop.cpp include/Pieces/Bishop.h src/Pieces/Queen.cpp include/Pieces/Queen.h src/Pieces/Rook.cpp include/Pieces/Rook.h include/Constant.h include/PrintBoard.h src/PrintBoard.cpp src/Parser.cpp)