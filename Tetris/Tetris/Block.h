#pragma once
struct Tile {
	int x, y;
	bool open;
	sf::Sprite sprite;
};

enum BlockType {
	L = 1,
	ReverseL,
	T,
	I,
	Squiggly,
	ReverseSquiggly,
	Square
};


class Block {
public:
	Block(BlockType type);
	~Block();

	std::string GetType() const;

	Tile GetTileFromShape(int tilenumber) const;
	bool MoveBlockDown();
	bool IsActive() const;
private:
	std::string m_type;
	std::vector<Tile> m_shape;
	bool m_active;
};