#include "Field.h"


Field::Field(const size_t x, const size_t y)
{
	/* ----Default constructor--- 
	 *
	 * Assignes sizeX, sizeY and builds the game-field 
	 * according to these values. */

	this->sizeX = x;
	this->sizeY = y;

	this->table = new bool*[sizeY];
	for (size_t i = 0; i < sizeY; ++i)
		table[i] = new bool[sizeX];
}

void 
Field::clear()
{
	/* Fill all cells with `false` */

	for (size_t y = 0; y < this->sizeY; ++y)
		for (size_t x = 0; x < this->sizeX; ++x)
			this->table[y][x] = false;
}

size_t 
Field::getSizeX() const
{ return this->sizeX; }

size_t 
Field::getSizeY() const
{ return this->sizeY; }

