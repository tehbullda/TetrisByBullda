#pragma once

#include "stdafx.h"
#include "TextRenderer.h"

namespace btetris
{
	// Responsible for rendering high score and current score
	class ScoreRenderer : public TextRenderer
	{
	public:
		ScoreRenderer();
		virtual void renderScores(sf::RenderWindow& window, int highScore, int currentScore) const;
	private:

		virtual sf::Text& createTextToDisplay
			(sf::Text& text, const std::string& str, float posX, float posY, bool bold = false, sf::Color color = sf::Color::White) const;

		int m_characterSize;
		std::string m_highScoreText;
		std::string m_currentScoreText;
	};
}
