class Cell {
public:
	void assign(const bool);
	void assign(const int);
	void update();

	bool getValue() const;
private:
	bool value, changed;
};
