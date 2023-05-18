#pragma once
#include"Piece.h"
#include"Location.h"
#include <string>
#include"Piece.h"
class Piece;

using namespace std;

#define SIZE 8

/**
 * @class Board
 * @brief Represents a chessboard and its operations.
 */
class Board 
{
private:
	Piece* board[SIZE][SIZE];
	bool white = true;

	bool isEmptySource(Location Src);
	bool isOpponentSource(Location Src);
	bool isNotEmptyDest(Location dst);
	bool isLegalMove(Location Src, Location dst);
	bool isChessMove(Location Src, Location dst, bool kingColor);
	Location* parser(string loc);
	void movePiece(Location src, Location dst);
	void changePlayer();
	Location findKingLocation(bool kingColor);

public:
	Board();
	Board (string str);

	Piece* getPiece(Location loc);
	Piece* getPiece(int row, int col);

	int returnCode(string move);

};