#pragma once
#include"Piece.h"
#include"Location.h"

class Pawn : public Piece
{
private:
	enum DIR {UP, DOWN};
	DIR dir = UP;

public:
	Pawn();
	Pawn(bool pieceColor, Board* b) {};
	Pawn(bool pieceColor, Board* b, Location loc);
	bool canMove(Location start, Location end) override;
};