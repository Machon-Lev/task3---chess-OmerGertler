#pragma once
#include"Piece.h"

class Queen : public Piece
{
public:
	Queen();
	Queen(bool pieceColor, Board* b);
	bool canMove(Location start, Location end) override;

};
