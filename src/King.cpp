#include"King.h"
#include <cmath>	

/**
 * @brief Default constructor for the King class.
 */
King::King() : Piece() {}

/**
 * @brief Parameterized constructor for the King class.
 * Initializes a King object with the specified color and board.
 * @param pieceColor The color of the King.
 * @param b Pointer to the board that the King belongs to.
 */
King::King(bool pieceColor, Board* b) : Piece(pieceColor, b) {}

/**
 * @brief Checks if the King can move from the start location to the end location.
 * @param start The starting location.
 * @param end The destination location.
 * @return True if the move is valid, false otherwise.
 */
bool King::canMove(Location start, Location end) 
{
	int srcX = start.getX();
	int srcY = start.getY();
	int dstX = end.getX();
	int dstY = end.getY();

	return (abs(srcX - dstX) <= 1 && abs(srcY - dstY) <= 1 && start != end);
}
