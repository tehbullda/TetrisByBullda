#include "stdafx.h"
#include "Block.h"
#include "TextureManager.h"


Block::Block(BlockType type, TextureManager *tex_mgr) {
	m_gridDistanceFromEdge_X = 470;
	m_gridDistanceFromEdge_Y = 40; //Should probably send the sf::Window as an argument to get these dynamic.
	/* L = 1,
	ReverseL,
	T,
	I,
	Squiggly,
	ReverseSquiggly,
	Square */
	m_active = true;
	Tile tile1;
	Tile tile2;
	Tile tile3;
	Tile tile4;
	sf::Sprite sprite;

	switch (type) { //Probably not the most beautiful solution but they have to be declared differently
	case (BlockType::L) :
		m_type = "L";
		sprite.setTexture(*tex_mgr->Load("Orange_32x32.png"));
		tile1 = { 4, 0, false, sprite };
		tile2 = { 4, 1, false, sprite };
		tile3 = { 4, 2, false, sprite };
		tile4 = { 5, 2, false, sprite };
		m_shape.push_back(tile1);
		m_shape.push_back(tile2);
		m_shape.push_back(tile3);
		m_shape.push_back(tile4);
		break;

	case (BlockType::ReverseL) :
		m_type = "ReverseL";
		sprite.setTexture(*tex_mgr->Load("Blue_32x32.png"));
		tile1 = { 5, 0, false, sprite };
		tile2 = { 5, 1, false, sprite };
		tile3 = { 5, 2, false, sprite };
		tile4 = { 4, 2, false, sprite };
		m_shape.push_back(tile1);
		m_shape.push_back(tile2);
		m_shape.push_back(tile3);
		m_shape.push_back(tile4);
		break;
	case (BlockType::T) :
		m_type = "T";
		sprite.setTexture(*tex_mgr->Load("Pink_32x32.png"));
		tile1 = { 4, 0, false, sprite };
		tile2 = { 4, 1, false, sprite };
		tile3 = { 4, 2, false, sprite };
		tile4 = { 5, 1, false, sprite };
		m_shape.push_back(tile1);
		m_shape.push_back(tile2);
		m_shape.push_back(tile3);
		m_shape.push_back(tile4);
		break;
	case (BlockType::I) :
		m_type = "I";
		sprite.setTexture(*tex_mgr->Load("Teal_32x32.png"));
		tile1 = { 4, 0, false, sprite };
		tile2 = { 4, 1, false, sprite };
		tile3 = { 4, 2, false, sprite };
		tile4 = { 4, 3, false, sprite };
		m_shape.push_back(tile1);
		m_shape.push_back(tile2);
		m_shape.push_back(tile3);
		m_shape.push_back(tile4);
		break;
	case (BlockType::Squiggly) :
		m_type = "Squiggly";
		sprite.setTexture(*tex_mgr->Load("Green_32x32.png"));
		tile1 = { 4, 0, false, sprite };
		tile2 = { 4, 1, false, sprite };
		tile3 = { 5, 1, false, sprite };
		tile4 = { 5, 2, false, sprite };
		m_shape.push_back(tile1);
		m_shape.push_back(tile2);
		m_shape.push_back(tile3);
		m_shape.push_back(tile4);
		break;
	case (BlockType::ReverseSquiggly) :
		m_type = "ReverseSquiggly";
		sprite.setTexture(*tex_mgr->Load("Red_32x32.png"));
		tile1 = { 5, 0, false, sprite };
		tile2 = { 5, 1, false, sprite };
		tile3 = { 4, 1, false, sprite };
		tile4 = { 4, 2, false, sprite };
		m_shape.push_back(tile1);
		m_shape.push_back(tile2);
		m_shape.push_back(tile3);
		m_shape.push_back(tile4);
		break;
	case (BlockType::Square) :
		m_type = "Square";
		sprite.setTexture(*tex_mgr->Load("Yellow_32x32.png"));
		tile1 = { 4, 0, false, sprite };
		tile2 = { 4, 1, false, sprite };
		tile3 = { 5, 0, false, sprite };
		tile4 = { 5, 1, false, sprite };
		m_shape.push_back(tile1);
		m_shape.push_back(tile2);
		m_shape.push_back(tile3);
		m_shape.push_back(tile4);
		break;
	default:
		m_type = "";
		std::cout << "Unsupported BlockType or unexpected error occured" << std::endl;
		m_active = false;
		break;
	}
	SetSpritePositions();
}

Block::~Block() {

}

std::string Block::GetType() const {
	return m_type;
}

Tile Block::GetTileFromShape(int tilenumber) const {
	// Testing the github-syncing.
	// TODO: should check for out of bounds
	// TODO: should check size of m_shape before indexing
	return m_shape[tilenumber - 1];
}

bool Block::MoveBlockDown() {
	for (int i = 0; i < m_shape.size(); i++) {
		m_shape[i].y++;
	}
	SetSpritePositions();
	return true;
}

bool Block::IsActive() const {
	return m_active;
}

void Block::SetSpritePositions() {
	for (int i = 0; i < m_shape.size(); i++) {
		m_shape[i].sprite.setPosition(m_gridDistanceFromEdge_X + m_shape[i].x * 32, m_gridDistanceFromEdge_Y + m_shape[i].y * 32);
	}
}