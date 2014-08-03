#include "stdafx.h"
#include "TextRenderer.h"

using namespace btetris;
using namespace std;

TextRenderer::TextRenderer()
{
	string font("../data/fonts/ARIAL.TTF");

	if (!m_font.loadFromFile(font))
	{
		string errorMsg("Fatal: Failed to load font from ");
		errorMsg.append(font);
		cout << errorMsg;
		abort(); // bring it down since there is no recovery from this
	}
}

void TextRenderer::render(sf::RenderWindow& window, sf::Text& text) const
{
	text.setFont(m_font);
	window.draw(text);
}
