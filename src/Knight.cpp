#include"Knight.h"

/**
 * @brief Default constructor for the Knight class.
 */
Knight::Knight() : Piece() {}

/**
 * @brief Parameterized constructor for the Knight class.
 * Initializes a Knight object with the specified color and board.
 * @param pieceColor The color of the Knight.
 * @param b Pointer to the board that the Knight belongs to.
 */
Knight::Knight(bool pieceColor, Board* b) : Piece(pieceColor, b) {}

/**
 * @brief Checks if the Knight can move from the start location to the end location.
 * @param start The starting location.
 * @param end The destination location.
 * @return True if the move is valid, false otherwise.
 */
bool Knight::canMove(Location start, Location end)
{
    int deltaX = abs(start.getX() - end.getX());
    int deltaY = abs(start.getY() - end.getY());

    // Check if the move is in an L-shape: deltaX = 1, deltaY = 2 or deltaX = 2, deltaY = 1
    return (deltaX == 1 && deltaY == 2) || (deltaX == 2 && deltaY == 1);
}