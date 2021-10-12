#include "Cell.h"

Cell::Cell()
{
	/* ----Default constructor----
	 *
	 * `value` - current value of the cell
	 * `changed` - `true` if cell's value has to be changed */

	value = false;
	changed = false;
}

void 
Cell::assign(const bool value)
/* Set `changed` to `true` if cell's value has to be changed */
{ changed = (this->value != value); }

void
Cell::assign(const int neighboursCount)
{
	/* Decide whether cell's value has to be changed
	 * according to it's neighbours' count 
	 * If cell is alive and has not 2 or 3 neighbours - change value 
	 * If cell is dead and has 3 neigbours - change value */

	if (value)
	{
		if (neighboursCount != 2 && neighboursCount != 3)
			changed = true;
	}
	else 
	{
		if (neighboursCount == 3)
			changed = true;
	}
}

void 
Cell::update()
{
	/* Set new cell's current value if it has to be changed */

	if (changed)
	{
		value = !value;
		changed = false;
	}
}

bool 
Cell::getValue() const
/* Get cell's current value */
{ return value; }
