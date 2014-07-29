#pragma once
#include "stdafx.h"
#include <list>
#include "Block.h"

class BlockManager {
public:
	BlockManager();
	~BlockManager();

	void AddBlock(Block* block);

	void Update(float deltatime, std::string input = "Down");
	void MoveBlock(std::string dir);
	bool ValidateMove(std::string move);

	void DrawBlocks(sf::RenderWindow *window);

	void SetBlockSpeed(int speed);

private:
	std::vector<Block*> m_blocks;
	std::vector<Tile> m_tilegrid;
	const static int m_maxgridWidth, m_maxgridHeight, m_maxTilesperBlock;
	Block *m_current_block;
	int m_speed;
	float m_time;
};