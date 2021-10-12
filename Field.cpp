#include "Field.h"


Field::Field(const size_t x, const size_t y)
{
	/* ----Default constructor--- 
	 *
	 * Assignes sizeX, sizeY and builds the game-field 
	 * according to these values. */

	this->sizeX = x;
	this->sizeY = y;

	this->table = new Cell*[sizeX];
	for (size_t i = 0; i < sizeX; ++i)
		table[i] = new Cell[sizeY];
	this->fillWith(true);
}

size_t 
Field::getSizeX() const
/* Return field's width (X) */
{ return this->sizeX; }

size_t 
Field::getSizeY() const
/* Return field's height (Y) */
{ return this->sizeY; }

bool
Field::getCell(size_t x, size_t y) const
/* Return specified cell's value */
{ return this->table[x][y].getValue(); }

void 
Field::fillWith(const bool fillValue)
{
	/* Fill all cells with `fillValue` (true or false) */

	for (size_t y = 0; y < this->sizeY; ++y)
		for (size_t x = 0; x < this->sizeX; ++x)
		{
			this->table[x][y].assign(fillValue);
			this->table[x][y].update();
		}
}

