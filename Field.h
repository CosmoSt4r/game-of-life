#include <fstream>

typedef unsigned long long size_t;

/* Class for Game of Life game-field implementation 
 * Handles both field storing and game logic */
class Field {
public:
	explicit Field(const size_t, const size_t, 
					const char empty = ' ', const char filled = 'O');

	size_t getSizeX() const;
	size_t getSizeY() const;

	friend std::ostream& operator<<(std::ostream&, const Field&);

private:
	bool **table;
	size_t sizeX, sizeY;
	char emptyCell, filledCell;
};
