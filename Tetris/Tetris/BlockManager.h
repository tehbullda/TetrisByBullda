#pragma once
#include "stdafx.h"
#include <list>
#include "Block.h"

class TextureManager;

class BlockManager {
public:
	BlockManager(TextureManager *tex_mgr);
	~BlockManager();

	void AddBlock(Block* block);

	void Update(float deltatime, std::string input = "Down");
	void MoveBlock(std::string dir);
	bool ValidateMove(std::string move);

	void DrawBlocks(sf::RenderWindow *window);

	void SetBlockSpeed(int speed);

private:
	TextureManager *m_texture_manager;
	std::vector<Block*> m_blocks;
	std::vector<Tile> m_tilegrid;
	const static int m_maxgridWidth, m_maxgridHeight, m_maxTilesperBlock;
	Block *m_current_block;
	int m_speed;
	float m_time;
};