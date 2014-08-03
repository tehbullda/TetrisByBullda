#pragma once

#include "stdafx.h"

namespace btetris
{
	// Responsible for rendering text
	class TextRenderer
	{
	public:
		TextRenderer();
		virtual void render(sf::RenderWindow& window, sf::Text& text) const;

	private:
		sf::Font m_font;
	};
}
