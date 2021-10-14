#include <fstream>
#include <ctime>

#include "Cell.h"

typedef unsigned long long size_t;

/* Class for Game of Life game-field implementation 
 * Handles both field storing and game logic */
class Field {
public:
	explicit Field(const size_t, const size_t);
	~Field();

	size_t getSizeX() const;
	size_t getSizeY() const;

	bool getCell(size_t, size_t) const;
	void setCell(const size_t, const size_t, const bool);

	void fillWith(const bool fillValue);
	void fillRandom(const int sparseMultiplier = 2);
	void assignNewValues();
	void update();

private:
	Cell **table;
	size_t sizeX, sizeY;
	size_t prevTableHash;

	int countNeighbours(long long, long long);
};
