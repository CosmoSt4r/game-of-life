#include "Field.h"


Field::Field(const size_t x, const size_t y, 
				const char empty, const char filled)
{
	/* ----Default constructor--- 
	 *
	 * Assignes sizeX, sizeY and builds the game-field 
	 * according to these values.
	 * Accepts optional arguments for cells displaying */

	this->sizeX = x;
	this->sizeY = y;

	this->emptyCell = empty;
	this->filledCell = filled;

	this->table = new bool*[sizeY];
	for (size_t i = 0; i < sizeY; ++i)
		table[i] = new bool[sizeX];
}

size_t 
Field::getSizeX() const
{ return this->sizeX; }

size_t 
Field::getSizeY() const
{ return this->sizeY; }

std::ostream& operator<<(std::ostream& stream, const Field& field)
{
	char empty = field.emptyCell, filled = field.filledCell;
	for (size_t y = 0; y < field.sizeY; ++y)
	{
		for (size_t x = 0; x < field.sizeX; ++x)
			stream << (field.table[y][x] ? filled : empty);
		stream << '\n';
	}
	return stream;
}
