#pragma once

class TextureManager {
public:
	TextureManager(std::string location);
	~TextureManager(void);

	sf::Texture *Load(std::string filename);
private:
	std::map<std::string, sf::Texture *> m_textures;

	std::string m_location;
};