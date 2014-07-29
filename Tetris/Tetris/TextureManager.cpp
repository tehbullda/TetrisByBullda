#include "stdafx.h"
#include "TextureManager.h"

TextureManager::TextureManager(std::string location) {
	m_location = location;
}
TextureManager::~TextureManager(void) {
	for (std::map<std::string, sf::Texture *>::iterator it = m_textures.begin(); it != m_textures.end(); it++) {
		delete it->second;
	}
	m_textures.clear();
}

sf::Texture* TextureManager::Load(std::string filename) {
	std::map<std::string, sf::Texture *>::iterator it = m_textures.find(filename);
	if (it != m_textures.end()) {
		return it->second;
	}

	sf::Texture *texture = new sf::Texture;
	texture->loadFromFile(m_location + filename);
	texture->setSmooth(true);
	m_textures.insert(std::pair<std::string, sf::Texture *>(filename, texture));

	return texture;
}