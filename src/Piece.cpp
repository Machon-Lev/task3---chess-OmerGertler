#include"Piece.h"

/**
 * @brief Default constructor for the Piece class.
 */
Piece::Piece() {}

/**
 * @brief Parameterized constructor for the Piece class.
 * Initializes a Piece object with the specified color and board.
 * @param pieceColor The color of the Piece.
 * @param b Pointer to the board that the Piece belongs to.
 */
Piece::Piece(bool white, Board* b)
{
	pieceColorIsWhite = white;
	board = b;
}

/**
 * @brief Returns the color of the Piece.
 * @return True if the Piece is white, false otherwise.
 */
bool Piece::isWhite() const
{
	return pieceColorIsWhite;
}

