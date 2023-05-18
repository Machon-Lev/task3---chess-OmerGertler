#include"Pawn.h"

/**
 * @brief Default constructor for the Pawn class.
 */
Pawn::Pawn() : Piece() {}

/**
 * @brief Parameterized constructor for the Pawn class.
 * Initializes a Pawn object with the specified color, board, and location.
 * assuming the pown initialized in the correct place, else difault direction is UP.
 * @param pieceColor The color of the Pawn.
 * @param b Pointer to the board that the Pawn belongs to.
 * @param loc The initial location of the Pawn.
 */
Pawn::Pawn(bool pieceColor, Board* b, Location loc) : Piece(pieceColor, b)
{
	int col = loc.getX();
	if (col == 1)
		dir = DOWN;
	else if (col == 6)
		dir = UP;
}

/**
 * @brief Checks if the Pawn can move from the start location to the end location.
 * @param start The starting location.
 * @param end The destination location.
 * @return True if the move is valid, false otherwise.
 */
bool Pawn::canMove(Location start, Location end)
{
	bool isLegalMove = true;
	int deltaY, deltaX;
	int srcX = start.getX();
	int srcY = start.getY();
	int dstX = end.getX();
	int dstY = end.getY();
	deltaX = abs(srcX - dstX);
	deltaY = abs(srcY - dstY);

	if (dir == DOWN)
	{
		if (dstX <= srcX)
			isLegalMove = false;
		if (srcX < 2)
		{
			if (deltaX > 2)
				isLegalMove = false;
		}
		else if (deltaX > 1)
			isLegalMove = false;

	}
	else // UP
	{
		if (dstX >= srcX)
			isLegalMove = false;
		if (srcX > 5)
		{
			if (deltaX > 2)
				isLegalMove = false;
		}
		else if (deltaX > 1)
			isLegalMove = false;
	}

	if (isLegalMove && deltaY > 0) // takes opponent's pawn (diagonal move)
	{
		Piece* enemy = board->getPiece(end);
		if (enemy == nullptr || enemy->isWhite() == pieceColorIsWhite)
			isLegalMove = false;
	}
	return isLegalMove;
}