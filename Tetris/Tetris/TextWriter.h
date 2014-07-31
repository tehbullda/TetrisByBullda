#pragma once

#include "stdafx.h"
#include <string>
#include "SFML\Graphics\Font.hpp"
#include "SFML\Graphics\RenderWindow.hpp"

namespace btetris
{
	class TextWriter
	{
	public:
		TextWriter();

		void setPosition(int xPos,int yPos);
		void setText(const std::string& text);
		void setCharacterSize(int characterSize);
		void write(sf::RenderWindow& window) const;

	private:
		int m_xPos;
		int m_yPos;
		int m_characterSize;
		std::string m_text;
		sf::Font m_font;
		sf::Color m_color;
	};
}
