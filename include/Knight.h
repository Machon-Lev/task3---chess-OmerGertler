#pragma once
#include"Piece.h"

class Knight : public Piece
{
public:
	Knight();
	Knight(bool pieceColor, Board* b);
	bool canMove(Location start, Location end) override;

};