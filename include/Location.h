#pragma once
#include <iostream>
using std::ostream;

struct Location
{
	int row;
	int col;

	Location();
	Location(int x, int y);

	int getX();
	int getY();
	void setX(int newRow);
	void setY(int newCol);
	bool operator == (const Location& loc) const;
	bool operator != (const Location& loc) const;
	Location operator+(const Location& loc) const;
	Location& operator+=(const Location& loc);
	Location operator-(const Location& loc) const;

	friend ostream& operator<<(ostream& os, const Location& loc);
};