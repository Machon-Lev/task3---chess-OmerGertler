#include"Queen.h"
#include"Bishop.h"
#include"Rook.h"

/**
 * @brief Default constructor for the Queen class.
 */
Queen::Queen() : Piece() {}

/**
 * @brief Parameterized constructor for the Queen class.
 * Initializes a Queen object with the specified color and board.
 * @param pieceColorIsWhite The color of the Queen piece.
 * @param b Pointer to the board that the Queen belongs to.
 */
Queen::Queen(bool pieceColorIsWhite, Board* b) : Piece(pieceColorIsWhite, b) {}

/**
 * @brief Determines if the Queen can move from the start location to the end location.
 * The Queen can move either like a Rook or a Bishop, so the move is valid if it is a valid move for either piece.
 * @param start The starting location of the Queen.
 * @param end The ending location of the Queen.
 * @return True if the move is valid, false otherwise.
 */
bool Queen::canMove(Location start, Location end)
{
	Rook rook(pieceColorIsWhite, board);
	Bishop bishoop(pieceColorIsWhite, board);
	return (bishoop.canMove(start, end) || rook.canMove(start, end));
}
