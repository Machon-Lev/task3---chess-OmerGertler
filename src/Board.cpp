#include"Board.h"
#include"Rook.h"
#include"King.h"
#include"Bishop.h"
#include"Knight.h"
#include"Pawn.h"
#include"Queen.h"

/**
 * @brief Default constructor.
 */
Board::Board() 
{
	for (int i = 0; i < SIZE; ++i)
		for (int j = 0; j < SIZE; ++j)
			board[i][j] = nullptr;
}

/**
 * @brief Constructor that initializes the board from a string.
 * @param str String representing the initial state of the board.
 */
Board::Board(string str)
{
	int row, col;
	Location loc;
	for (int i = 0; i < str.size(); i++)
	{
		row = i / 8;
		col = i % 8;
		switch (str[i])
		{
		case 'R':
			board[row][col] = new Rook(true, this);
			break;
		case 'r':
			board[row][col] = new Rook(false, this);
			break;
		case 'K':
			board[row][col] = new King(true, this);
			break;
		case 'k':
			board[row][col] = new King(false, this);
			break;
		case 'B':
			board[row][col] = new Bishop(true, this);
			break;
		case 'b':
			board[row][col] = new Bishop(false, this);
			break;
		case 'P':
			loc = Location((row), (col));
			board[row][col] = new Pawn(true, this, loc);
			break;
		case 'p':
			loc = Location((row), (col));
			board[row][col] = new Pawn(false, this, loc);
			break;
		case 'N':
			board[row][col] = new Knight(true, this);
			break;
		case 'n':
			board[row][col] = new Knight(false, this);
			break;
		case 'Q':
			board[row][col] = new Queen(true, this);
			break;
		case 'q':
			board[row][col] = new Queen(false, this);
			break;
		case '#':
			board[row][col] = nullptr;
			break;
		default:
			break;
		}
	}
	white = true;
}

/**
 * @brief Retrieves the piece at the specified location.
 * @param loc The location on the board.
 * @return Pointer to the piece at the specified location, or nullptr if the location is empty.
 */
Piece* Board::getPiece(Location loc)
{
	return board[loc.getX()][loc.getY()];
}

/**
 * @brief Retrieves the piece at the specified row and column.
 * @param row The row index.
 * @param col The column index.
 * @return Pointer to the piece at the specified row and column, or nullptr if the location is empty.
 */
Piece* Board::getPiece(int row, int col)
{
	return board[row][col];
}

/**
 * @brief Checks if the source location is empty.
 * @param src The source location.
 * @return True if the source location is empty, false otherwise.
 */
bool Board::isEmptySource(Location src)
{
	return getPiece(src) == nullptr;
}

/**
 * @brief Checks if the source location contains a piece of the opponent player.
 * @param src The source location.
 * @return True if the source location contains a piece of the opponent player, false otherwise.
 */
bool Board::isOpponentSource(Location src)
{
	return getPiece(src)->isWhite() != white;
}

/**
 * @brief Checks if the destination location is not empty and contains a piece of the current player.
 * @param dst The destination location.
 * @return True if the destination location is not empty and contains a piece of the current player, false otherwise.
 */
bool Board::isNotEmptyDest(Location dst)
{
	Piece* piece = getPiece(dst);
	return (piece != nullptr && piece->isWhite() == white);
}

/**
 * @brief Checks if the move from the source location to the destination location is a legal move.
 * @param src The source location.
 * @param dst The destination location.
 * @return True if the move is legal, false otherwise.
 */
bool Board::isLegalMove(Location src, Location dst)
{
	return getPiece(src)->canMove(src, dst);
}

/**
 * @brief Checks if the move from the source location to the destination location causes a check for the specified king color.
 * @param src The source location.
 * @param dst The destination location.
 * @param kingColor The color of the king to check.
 * @return True if the move causes a check, false otherwise.
 */
bool Board::isChessMove(Location src, Location dst, bool kingColor)
{
	bool isCheck = false;
	Location kingLocation = findKingLocation(kingColor);
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			Piece* slot = getPiece(i, j);
			if (slot != nullptr && slot->isWhite() != kingColor)
			{
				// Check if the current piece can move to the king's location
				if (slot->canMove(Location(i, j), kingLocation))
				{
					isCheck = true;
					break;
				}
			}
		}
		if (isCheck)
			break;
	}
	return isCheck;
}

/**
 * @brief Parses the move string into source and destination locations.
 * @param loc The move string in the format "srcRowsrcColdstRowdstCol".
 * @return An array of two locations representing the source and destination locations.
 */
Location* Board::parser(string loc)
{
	int srcX = loc[0] - 'a';
	int srcY = loc[1] - '0' -1;
	int dstX = loc[2] - 'a';
	int dstY = loc[3] - '0' -1;
	Location move[2] = { Location(srcX, srcY), Location(dstX, dstY) };
	return move;
}

/**
 * @brief Calculates the return code for the given move.
 * @param move The move string in the format <char,inr,char,int>.
 *	for example: 'a1c3' moves the piece from a1 to c3 slot.
 * @return The return code indicating the result of the move.
 */
int Board::returnCode(string move)
{
	Location* locs = parser(move);
	Location src = locs[0];
	Location dst = locs[1];
	int code;

	// legal moves checks
	if (isEmptySource(src)) // If there is no tool in the source slot
		code = 11;
	else if (isOpponentSource(src)) // If in the source square there is a tool of the opposing player
		code = 12;
	else if (isNotEmptyDest(dst)) // If the target square has a tool of the current player
		code = 13;
	else if (!isLegalMove(src, dst)) // If the movement of the tool is illegal
		code = 21;

	movePiece(src, dst);

	// chess checks
	if (isChessMove(src, dst, !white)) // If the move causes the current player to check, it is an illegal move
		code = 31;
	else if (isChessMove(src, dst, white)) // A move that will cause the opposing player to check
		code = 41;
	else // A normal move and you just have to perform it
		code = 42;

	return code;
}

/**
 * @brief Moves a piece from the source location to the destination location.
 * @param src The source location.
 * @param dst The destination location.
 */
void  Board::movePiece(Location src, Location dst)
{
	board[dst.getX()][dst.getY()] = board[src.getX()][src.getY()];
	board[src.getX()][src.getY()] = nullptr;
	changePlayer();
}

/**
 * @brief Changes the player's turn.
 */
void Board::changePlayer()
{
	white = !white;
}

/**
 * @brief Finds the location of the king with the specified color.
 * @param kingColor The color of the king to find.
 * @return The location of the king.
 */
Location Board::findKingLocation(bool kingColor)
{
	Location kingLocation;
	for (int i = 0; i < SIZE; ++i)
		for (int j = 0; j < SIZE; ++j)
		{
			Piece* slot = getPiece(i, j);
			if (slot != nullptr && typeid(*(slot)) == typeid(King) && slot->isWhite() == kingColor)
				kingLocation = Location(i, j);
		}
	return kingLocation;
}
