#include "Field.h"


Field::Field(size_t x, size_t y)
{
	this->sizeX = x;
	this->sizeY = y;

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
	for (size_t y = 0; y < field.sizeY; ++y)
	{
		for (size_t x = 0; x < field.sizeX; ++x)
			stream << (field.table[y][x] ? '*' : ' ');
		stream << '\n';
	}
	return stream;
}
