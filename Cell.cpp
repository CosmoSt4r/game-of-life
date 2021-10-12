#include "Cell.h"

void Cell::assign(const bool newValue)
{ this->changed = this->value != newValue; }

void Cell::update()
{ this->value = this->changed ? !this->value : this->value; }

bool Cell::getValue() const
{ return this->value; }
