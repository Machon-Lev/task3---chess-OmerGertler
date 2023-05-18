#pragma once
#include"Piece.h"

class Rook : public Piece
{
public:
	Rook();
	Rook(bool pieceColor, Board* b);
	bool canMove(Location start, Location end) override;
};

