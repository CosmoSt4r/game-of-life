#include "Cell.h"

Cell::Cell()
{
	value = false;
	changed = false;
}

void 
Cell::assign(const bool value)
{ changed = (this->value != value); }

void
Cell::assign(const int neighboursCount)
{
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
	if (changed)
	{
		value = !value;
		changed = false;
	}
}

bool 
Cell::getValue() const
{ return value; }
