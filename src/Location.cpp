#include "Location.h"

Location::Location() {}

Location::Location(int x, int y) { setX(x); setY(y); }

int Location::getX() { return row; }

int Location::getY() { return col; }

void Location::setX(int newRow) { row = newRow; }

void Location::setY(int newCol) { col = newCol; }

bool Location::operator == (const Location& loc) const { return (row == loc.row && col == loc.col); }

bool Location::operator != (const Location& loc) const { return (row != loc.row || col != loc.col); }

Location Location::operator+(const Location& loc) const
{
	Location newLoc;
	newLoc.setX(row + loc.row);
	newLoc.setY(col + loc.col);
	return newLoc;
}

Location& Location::operator+=(const Location& loc)
{
	(*this) = (*this) + loc;
	return *this;
}

Location Location::operator-(const Location& loc) const
{
	Location newLoc;
	newLoc.setX(row - loc.row);
	newLoc.setY(col - loc.col);
	return newLoc;
}

ostream& operator<<(ostream& os, const Location& loc)
{
	os << '(' << loc.row << ", " << loc.col << ')';
	return os;
}