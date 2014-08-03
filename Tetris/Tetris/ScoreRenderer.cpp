#include "stdafx.h"
#include "ScoreRenderer.h"

#include <list>

using namespace btetris;
using namespace std;

ScoreRenderer::ScoreRenderer()
:	m_characterSize(25),
	m_highScoreText("High Score"),
	m_currentScoreText("You")
{}

void ScoreRenderer::renderScores(sf::RenderWindow& window, int highScore, int currentScore)  const
{
	bool boldValues = currentScore == highScore;
	std::list<sf::Text* const> texts;

	sf::Text sfHighScoreText;
	texts.push_back(&createTextToDisplay(sfHighScoreText, m_highScoreText, 0.0f, 0.0f));

	sf::Text sfHighScoreValue;
	texts.push_back(&createTextToDisplay(sfHighScoreValue, std::to_string(highScore), 0.0f, (float)m_characterSize, boldValues));
	
	sf::Text sfCurrentScoreText;
	float currentScoreTextPosY = float(m_characterSize * 3);
	texts.push_back(&createTextToDisplay(sfCurrentScoreText, m_currentScoreText, 0.0f, currentScoreTextPosY));

	sf::Text sfCurrentScoreValue;
	float currentScoreValuePosY = float(m_characterSize * 4);
	texts.push_back(&createTextToDisplay(sfCurrentScoreValue, std::to_string(currentScore), 0.0f, currentScoreValuePosY, boldValues));

	std::list<sf::Text* const>::const_iterator it;

	for (it = texts.begin(); it != texts.end(); ++it)
	{
		render(window, **it);
	}
}

sf::Text& ScoreRenderer::createTextToDisplay(sf::Text& text, const std::string& str, float posX, float posY, bool bold, sf::Color color) const
{
	text.setString(str);
	text.setColor(color);
	text.setCharacterSize(m_characterSize);

	sf::Vector2f coord(posX, posY);
	text.setPosition(coord);

	if (bold)
	{
		text.setStyle(sf::Text::Bold);
	}

	return text;
}
