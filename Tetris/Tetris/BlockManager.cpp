#include "stdafx.h"
#include "BlockManager.h"
#include "Randomizer.h"

BlockManager::BlockManager() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 22; j++) {
			Tile tile = {i,j,true};
			m_tiles.push_back(tile);
		}
	}
}

BlockManager::~BlockManager() {

}

void BlockManager::AddBlock(Block* block) {
	if (block != nullptr && block->GetType() != "") { // If the block exists and isn't a faulty type
		m_blocks.push_back(block);
		m_current_block = block;
		for (unsigned int i = 0; i < m_tiles.size(); i++) {
			for (int j = 1; j < 4; j++) {
				if (m_tiles[i].x == block->GetTileFromShape(j).x) {
					if (m_tiles[i].y == block->GetTileFromShape(j).y) {
						if (m_tiles[i].open) {
							m_tiles[i].open = false; // Make the tiles now occupied by this block closed.
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
		if (m_current_block->IsActive() && input == "Down" && m_time > m_speed/2) {
			MoveBlock(input);
			m_time = 0.0f;
		}
	}
	else {
		AddBlock(new Block(static_cast<BlockType>(Randomizer::GetRandomInt(1, 7))));
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
		for (int j = 1; j < 4; j++) {
			if (!m_blocks[i]->GetTileFromShape(j).open) { // If any of the four tiles in the shape has been removed due to a line-removal then that tile will not be drawn
				window->draw(m_blocks[i]->GetTileFromShape(j).sprite);
			}
		}
	}
	/*for (int i = 0; i < m_tiles.size(); i++) { // Another way to do the same thing, not sure which one is best
		if (!m_tiles[i].open) {
			window->draw(m_tiles[i].sprite);
		}
	}*/
}

void BlockManager::SetBlockSpeed(int speed) {
	if (speed > 0 && speed <= 10) {
		m_speed = 11 - speed; // This is the time needed between updates of the blocks, higher value = slower.
	}
}