#include "Field.h"

Field::Field(size_t x, size_t y)
{
	this->x_size = x;
	this->y_size = y;

	this->field = new bool*[y_size];
	for (bool** iter = this->field; iter != iter + y_size; ++iter)
		*iter = new bool[x_size];
}
