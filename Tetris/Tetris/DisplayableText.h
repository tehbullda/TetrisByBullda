#pragma once

#include "stdafx.h"
#include <string>
#include "SFML\Graphics\Font.hpp"
#include "SFML\Graphics\RenderWindow.hpp"

namespace btetris
{
	class DisplayableText
	{
	public:
		DisplayableText();

		void setPosition(float xPos, float yPos);
		void setText(const std::string& text);
		void setCharacterSize(int characterSize);
		void render(sf::RenderWindow& window) const;

	private:
		float m_xPos;
		float m_yPos;
		int m_characterSize;
		std::string m_text;
		sf::Font m_font;
		sf::Color m_color;
	};
}
