#include "stdafx.h"
#include "TextWriter.h"
#include <iostream>
#include "SFML\Graphics\Text.hpp"

using namespace btetris;
using namespace std;

TextWriter::TextWriter()
{
	m_xPos = 0;
	m_yPos = 0;
	m_characterSize = 30;
	m_color = sf::Color::White;
	
	string font("../data/fonts/ARIAL.TTF");

	if (!m_font.loadFromFile(font))
	{
		string errorMsg("Fatal: Failed to load font from ");
		errorMsg.append(font);
		cout << errorMsg;
		abort(); // bring it down since there is no recovery from this
	}
}

void TextWriter::setPosition(int xPos, int yPos)
{
	m_xPos = xPos;
	m_yPos = yPos;
}

void TextWriter::setCharacterSize(int characterSize)
{
	m_characterSize = characterSize;
}

void TextWriter::setText(const std::string& text)
{
	m_text = text;
}

void TextWriter::write(sf::RenderWindow& window) const
{
	sf::Text graphicsText;
	graphicsText.setFont(m_font);
	graphicsText.setColor(m_color);
	graphicsText.setCharacterSize(m_characterSize);
	graphicsText.setString(m_text);
	
	sf::Vector2f coord(m_xPos, m_yPos);
	graphicsText.setPosition(coord);

	window.draw(graphicsText);
}
