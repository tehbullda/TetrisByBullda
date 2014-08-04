#pragma once

#include "stdafx.h"
#include "TextRenderer.h"

namespace btetris
{
	class HighScoreRecord;

	// Responsible for rendering score status on screen
	class ScoreRenderer : public TextRenderer
	{
	public:
		ScoreRenderer();
		virtual void RenderScores(sf::RenderWindow& window, const HighScoreRecord& high, const HighScoreRecord& current, const HighScoreRecord& next) const;
	private:
		virtual sf::Text& CreateTextToDisplay
			(sf::Text& text, const std::string& str, float posX, float posY, bool bold = false, sf::Color color = sf::Color::White) const;

		virtual float CalculateYPos(int currentLine) const;

		int m_characterSize;
		std::string m_highScoreText;
		std::string m_currentScoreText;
		std::string m_nextScoreText;
		std::string m_noneLeft;
	};
}
