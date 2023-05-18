#include"Bishop.h"
#include<cmath>

Bishop::Bishop() : Piece() {}

Bishop::Bishop(bool pieceColor, Board* b) : Piece(pieceColor, b) {}

bool Bishop::canMove(Location start, Location end)
{
	bool isLegalMove = true;
	int deltaX = abs(start.getX() - end.getX());
	int deltaY = abs(start.getY() - end.getY());

	if (deltaX != deltaY)
	{
		isLegalMove = false;
	}
	else
	{
		setDir(start.getX(), start.getY(), end.getX(), end.getY());
		int row = start.getX();
		int col = start.getY();
		Location loc = Location(row, col);
		loc = nextSlot(loc.getX(), loc.getY());

		while (loc != end)
		{
			if (board->getPiece(loc) != nullptr)
			{
				isLegalMove = false;
				break;
			}
			loc = nextSlot(loc.getX(), loc.getY());
		}
	}
	return isLegalMove;


	//bool isLegalMove = true;
	//int row, col, deltaX, deltaY;
	//int srcX = start.getX();
	//int srcY = start.getY();
	//int dstX = end.getX();
	//int dstY = end.getY();

	//deltaX = abs(srcX - dstX);
	//deltaY = abs(srcY - dstY);

	//if (deltaX != deltaY)
	//	isLegalMove = false;
	//else
	//{
	//	setDir(srcX, srcY, dstX, dstY);
	//	row = srcX;
	//	col = srcY;
	//	Location loc = Location(row, col);
	//	loc = nextSlot(loc.getX(), loc.getY());

	//	while (loc != end)
	//	{
	//		if (board->getPiece(loc) != nullptr)
	//			isLegalMove = false;
	//		loc = nextSlot(loc.getX(), loc.getY());

	//	}
	//}
	//return isLegalMove;
}

void Bishop::setDir(int srcRow, int srcCol, int dstRow, int dstCol)
{
	if (srcRow < dstRow) // down
	{
		if (srcCol < dstCol) // right
			dir = DOWN_RIGHT;
		else // left
			dir = DOWN_LEFT;
	}
	else // up
	{
		if (srcCol < dstCol) // right
			dir = UP_RIGHT;
		else // left
			dir = UP_LEFT;
	}
}

Location Bishop::nextSlot(int row, int col)
{
	switch (dir)
	{
	case Bishop::UP_RIGHT:
		--row;
		++col;
		break;
	case Bishop::DOWN_RIGHT:
		++row;
		++col;
		break;
	case Bishop::UP_LEFT:
		--row;
		--col;
		break;
	case Bishop::DOWN_LEFT:
		++row;
		--col;
		break;
	default:
		break;
	}
	Location loc = Location(row, col);
	return loc;
}
