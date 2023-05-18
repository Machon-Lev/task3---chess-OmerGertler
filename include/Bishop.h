#pragma once
#include"Piece.h"

class Bishop : public Piece
{
public:
	Bishop();
	Bishop(bool pieceColor, Board* b);
	bool canMove(Location start, Location end) override;

private:
	enum DIR { UP_RIGHT, DOWN_RIGHT, UP_LEFT, DOWN_LEFT };
	DIR dir = UP_RIGHT;
	void setDir(int srcX, int srcY, int dstX, int dstY);
	Location nextSlot(int row, int col);

};
