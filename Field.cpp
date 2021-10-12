#include "Field.h"

Field::Field(const size_t x, const size_t y)
{
	/* ----Default constructor--- 
	 *
	 * Assignes sizeX, sizeY and builds the game-field 
	 * according to these values. */

	sizeX = x;
	sizeY = y;

	table = new Cell*[sizeX];
	for (size_t i = 0; i < sizeX; ++i)
		table[i] = new Cell[sizeY];
	fillWith(false);
}

size_t 
Field::getSizeX() const
/* Return field's width (X) */
{ return sizeX; }

size_t 
Field::getSizeY() const
/* Return field's height (Y) */
{ return sizeY; }

bool
Field::getCell(size_t x, size_t y) const
/* Return specified cell's value */
{ return table[x][y].getValue(); }

void 
Field::fillWith(const bool fillValue)
{
	/* Fill all cells with `fillValue` (true or false) */

	for (size_t x = 0; x < sizeX; ++x)
		for (size_t y = 0; y < sizeY; ++y)
		{
			table[x][y].assign(fillValue);
			table[x][y].update();
		}
}

void
Field::fillRandom(const int sparseMultiplier)
{
	srand(time(0));
	for (size_t y = 0; y < sizeY; ++y)
		for (size_t x = 0; x < sizeX; ++x)
		{
			table[x][y].assign(rand() % sparseMultiplier == 0);
			table[x][y].update();
		}
}

void
Field::update()
{
	int neighboursCount = 0;
	bool newValue;

	for (size_t y = 0; y < sizeY; ++y)
		for (size_t x = 0; x < sizeX; ++x)
		{
			neighboursCount = countNeighbours(x, y);
			table[x][y].assign(neighboursCount);
		}

	for (size_t y = 0; y < sizeY; ++y)
		for (size_t x = 0; x < sizeX; ++x)
		{
			table[x][y].update();
		}
}

int
Field::countNeighbours(size_t x, size_t y)
{
	bool validIndexes = false;
	int count = 0;

	for (int i = y - 1; i < y + 2; ++i)
	{
		for (int j = x - 1; j < x + 2; ++j)
		{
			validIndexes = i >= 0 & i < sizeY & j >= 0 & j < sizeX;
			validIndexes &= !(i == y && j == x);
			if (validIndexes)
				count += table[j][i].getValue() ? 1 : 0;
		}	
	}

	return count;
}


