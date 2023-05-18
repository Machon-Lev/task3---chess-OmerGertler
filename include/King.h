#pragma once
#include"Piece.h"

class King : public Piece
{
public:
	King();
	King(bool pieceColor, Board* b);
	bool canMove(Location start, Location end) override;



};
