#include "stdafx.h"
#include "Block.h"



Block::Block(BlockType type) {
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
	switch (type) { //Probably not the most beautiful solution but they have to be declared differently and not dynamically
	case (BlockType::L) :
		m_type = "L";
		tile1 = { 4, 0, false };
		tile2 = { 4, 1, false };
		tile3 = { 4, 2, false };
		tile4 = { 5, 2, false };
		m_shape.push_back(tile1);
		m_shape.push_back(tile2);
		m_shape.push_back(tile3);
		m_shape.push_back(tile4);
		break;

	case (BlockType::ReverseL) :
		m_type = "ReverseL";
		tile1 = { 5, 0, false };
		tile2 = { 5, 1, false };
		tile3 = { 5, 2, false };
		tile4 = { 4, 2, false };
		m_shape.push_back(tile1);
		m_shape.push_back(tile2);
		m_shape.push_back(tile3);
		m_shape.push_back(tile4);
		break;
	case (BlockType::T) :
		m_type = "T";
		tile1 = { 4, 0, false };
		tile2 = { 4, 1, false };
		tile3 = { 4, 2, false };
		tile4 = { 5, 1, false };
		m_shape.push_back(tile1);
		m_shape.push_back(tile2);
		m_shape.push_back(tile3);
		m_shape.push_back(tile4);
		break;
	case (BlockType::I) :
		m_type = "I";
		tile1 = { 4, 0, false };
		tile2 = { 4, 1, false };
		tile3 = { 4, 2, false };
		tile4 = { 4, 3, false };
		m_shape.push_back(tile1);
		m_shape.push_back(tile2);
		m_shape.push_back(tile3);
		m_shape.push_back(tile4);
		break;
	case (BlockType::Squiggly) :
		m_type = "Squiggly";
		tile1 = { 4, 0, false };
		tile2 = { 4, 1, false };
		tile3 = { 5, 1, false };
		tile4 = { 5, 2, false };
		m_shape.push_back(tile1);
		m_shape.push_back(tile2);
		m_shape.push_back(tile3);
		m_shape.push_back(tile4);
		break;
	case (BlockType::ReverseSquiggly) :
		m_type = "ReverseSquiggly";
		tile1 = { 5, 0, false };
		tile2 = { 5, 1, false };
		tile3 = { 4, 1, false };
		tile4 = { 4, 2, false };
		m_shape.push_back(tile1);
		m_shape.push_back(tile2);
		m_shape.push_back(tile3);
		m_shape.push_back(tile4);
		break;
	case (BlockType::Square) :
		m_type = "Square";
		tile1 = { 4, 0, false };
		tile2 = { 4, 1, false };
		tile3 = { 5, 0, false };
		tile4 = { 5, 1, false };
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
	return true;
}

bool Block::IsActive() const {
	return m_active;
}