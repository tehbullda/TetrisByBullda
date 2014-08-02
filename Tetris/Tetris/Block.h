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

class TextureManager;

class Block {
public:
	Block(BlockType type, TextureManager *tex_mgr);
	~Block();

	std::string GetType() const;

	Tile GetTileFromShape(int tilenumber) const;
	bool MoveBlockDown();
	bool MoveBlockLeft();
	bool MoveBlockRight();
	bool IsActive() const;

private:
	void SetSpritePositions();

private:
	std::string m_type;
	std::vector<Tile> m_shape;
	bool m_active;
	int m_gridDistanceFromEdge_X, m_gridDistanceFromEdge_Y;
};