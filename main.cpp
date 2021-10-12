#include <iostream>
#include <ctime>
#include <unistd.h>

#ifdef _WIN32
#define clear_cmd system("cls")
#else
#define clear_cmd system("clear")
#endif

#include "Field.h"

void printField(const Field& field)
{
	for (int y = 0; y < field.getSizeY(); ++y)
	{
		for (int x = 0; x < field.getSizeX(); ++x)
			std::cout << (field.getCell(x, y) ? 'O' : '.');
		std::cout << std::endl;
	}
}

int main()
{
	const int sizeX = 60, sizeY = 20;

	Field field(sizeX, sizeY);
	field.fillRandom(2);

	while (true)
	{
		clear_cmd;
		printField(field);
		field.update();
		usleep(0.1 * 1000 * 1000);
	}

	return 0;
}
