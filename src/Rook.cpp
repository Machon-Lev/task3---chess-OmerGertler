#include"Rook.h"

/**
 * @brief Default constructor for the Rook class.
 */
Rook::Rook() : Piece() {}

/**
 * @brief Parameterized constructor for the Rook class.
 * Initializes a Rook object with the specified color and board.
 * @param pieceColor The color of the Rook piece.
 * @param b Pointer to the board that the Rook belongs to.
 */
Rook::Rook(bool pieceColor, Board* b) : Piece(pieceColor, b) {}

 /**
  * @brief Determines if the Rook can move from the start location to the end location.
  * The Rook can move horizontally or vertically, but not diagonally.
  * @param start The starting location of the Rook.
  * @param end The ending location of the Rook.
  * @return True if the move is valid, false otherwise.
  */
bool Rook::canMove(Location start, Location end) 
{
	bool isLegalMove = true;
	int maxIndex, minIndex;
	int srcX = start.getX();
	int srcY = start.getY();
	int dstX = end.getX();
	int dstY = end.getY();

	if (srcX != dstX && srcY != dstY)
		isLegalMove = false;
	else if (srcX == dstX) // move horizontaly
	{
		maxIndex = max(srcY, dstY);
		minIndex = min(srcY, dstY) + 1;
		for (; minIndex < maxIndex; ++minIndex)
		{
			Location loc = Location(srcX, minIndex);
			if (board->getPiece(loc) != nullptr)
				isLegalMove = false;
		}
	}
	else if (srcY == dstY) // move verticaly
	{
		maxIndex = max(srcX, dstX);
		minIndex = min(srcX, dstX) + 1;
		for (; minIndex < maxIndex; ++minIndex)
		{
			Location loc = Location(minIndex, srcY);
			if (board->getPiece(loc) != nullptr)
				isLegalMove = false;
		}
	}
	return isLegalMove;
}