#include <fstream>

typedef unsigned long long size_t;

class Field {
public:
	Field(size_t, size_t);

	size_t getSizeX() const;
	size_t getSizeY() const;

	friend std::ostream& operator<<(std::ostream&, const Field&);

private:
	bool **table;
	size_t sizeX, sizeY;
};
