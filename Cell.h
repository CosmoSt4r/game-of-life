/* Class for handling cells' logic in Game of Life */
class Cell {
public:
	Cell();

	void assign(const bool);
	void assign(const int);
	void update();

	bool getValue() const;
private:
	bool value, changed;
};
