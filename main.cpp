#include <iostream>
#include "Field.h"

int main()
{
	const int sizeX = 3, sizeY = 3;

	Field field(sizeX, sizeY);
	field.fillRandom(2);

	for (int y = 0; y < sizeY; ++y)
	{
		for (int x = 0; x < sizeX; ++x)
			std::cout << (field.getCell(x, y) ? 'O' : '.');
		std::cout << std::endl;
	}

	std::cout << "-----------" << std::endl;
	field.update();

	for (int y = 0; y < sizeY; ++y)
	{
		for (int x = 0; x < sizeX; ++x)
			std::cout << (field.getCell(x, y) ? 'O' : '.');
		std::cout << std::endl;
	}


	return 0;
}
