#pragma once
#include"Board.h"
#include"Location.h"
class Board;

/**
 * @class Piece
 * @brief Represents a general piece of chess game. 
 * Every specific piece inherits from it.
 */
class Piece
{

public:
	Piece();
	Piece(bool pieceColor, Board* b);
	virtual bool canMove(Location start, Location end) = 0;
	bool getIsLive() const;
	bool isWhite() const;

protected:
	Board* board = nullptr;
	bool pieceColorIsWhite;

};