#include <iostream>

class Field {
public:
	Field(size_t, size_t);

private:
	bool **field;
	size_t x_size, y_size;
};
