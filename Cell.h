class Cell {
public:
	void assign(const bool);
	void update();

	bool getValue() const;
private:
	bool value, changed;
};
