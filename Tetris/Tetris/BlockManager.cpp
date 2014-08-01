#include "stdafx.h"
#include "BlockManager.h"
#include "Randomizer.h"
#include "TextureManager.h"

#define GRID_MAX_WIDTH 10
#define GRID_MAX_HEIGHT 22
#define MAX_TILES_PER_BLOCK 4

BlockManager::BlockManager(TextureManager *tex_mgr) /*: m_maxgridWidth(10),
m_maxgridHeight(22),
m_maxTilesperBlock(4) */{
	m_texture_manager = tex_mgr;
	for (int i = 0; i < GRID_MAX_WIDTH; i++) {
		for (int j = 0; j < GRID_MAX_HEIGHT; j++) {
			Tile tile = {i,j,true};
			m_tilegrid.push_back(tile);
		}
	}
	
}

BlockManager::~BlockManager() {

}

void BlockManager::AddBlock(Block* block) {
	if (block != nullptr && block->GetType() != "") { // If the block exists and isn't a faulty type
		m_blocks.push_back(block);
		m_current_block = block;
		for (unsigned int i = 0; i < m_tilegrid.size(); i++) {
			for (int j = 1; j <= MAX_TILES_PER_BLOCK; j++) {
				if (m_tilegrid[i].x == block->GetTileFromShape(j).x) {
					if (m_tilegrid[i].y == block->GetTileFromShape(j).y) {
						if (m_tilegrid[i].open) {
							m_tilegrid[i].open = false; // Make the tiles now occupied by this block closed.
						}
						else {
							// If any of the starting-tiles is already occupied, the game is over.
						}
					}
				}
			}
		}
	}
}

void BlockManager::Update(float deltatime, std::string input) {
	m_time += deltatime;
	if (m_current_block != nullptr){
		if (m_current_block->IsActive() && input != "Down"){
			MoveBlock(input);
		}
		if (m_current_block->IsActive() && input == "Down" && m_time > m_speed) {
			MoveBlock(input);
			m_time = 0.0f;
		}
	}
	else {
		AddBlock(new Block(static_cast<BlockType>(Randomizer::GetRandomInt(1, 7)), m_texture_manager));
	}
}

void BlockManager::MoveBlock(std::string dir) {
	std::cout << dir << std::endl;
	if (ValidateMove(dir)) {
		if (dir == "Down") {
			m_current_block->MoveBlockDown(); //bool returned
		} //osv.
	} 
}

bool BlockManager::ValidateMove(std::string move) {
	return true;
}

void BlockManager::DrawBlocks(sf::RenderWindow *window) {
	for (unsigned int i = 0; i < m_blocks.size(); i++){
		for (int j = 1; j <= MAX_TILES_PER_BLOCK; j++) {
			if (!m_blocks[i]->GetTileFromShape(j).open) { // If any of the four tiles in the shape has been removed due to a line-removal then that tile will not be drawn
				window->draw(m_blocks[i]->GetTileFromShape(j).sprite);
			}
		}
	}
	/*for (int i = 0; i < m_tilegrid.size(); i++) { // Another way to do the same thing, not sure which one is best
		if (!m_tilegrid[i].open) {
			window->draw(m_tilegrid[i].sprite);
		}
	}*/
}

void BlockManager::SetBlockSpeed(float speed) {
	if (speed >= 0.25f && speed <= 2.0f) {
		m_speed = 2.25f - speed; // This is the time needed between updates of the blocks, higher value = slower.
	}
}