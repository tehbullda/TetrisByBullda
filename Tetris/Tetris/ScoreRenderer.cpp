#include "stdafx.h"
#include "ScoreRenderer.h"
#include "HighScoreRecord.h"

#include <list>

using namespace btetris;
using namespace std;

ScoreRenderer::ScoreRenderer()
:	m_characterSize(25),
	m_highScoreText("High Score"),
	m_currentScoreText("You"),
	m_nextScoreText("Next to beat"),
	m_noneLeft("None. YOU'RE WINNER !")
{}

void ScoreRenderer::RenderScores(sf::RenderWindow& window, const HighScoreRecord& high, const HighScoreRecord& current, const HighScoreRecord& next) const
{
	string highScoreName(high.GetName());
	int highScoreValue = high.GetScore();

	string nextScoreName(next.GetName());
	int nextScoreValue = next.GetScore();

	int currentScore = current.GetScore();

	bool hasHighScore = currentScore == highScoreValue;
	std::list<sf::Text* const> texts;

	int currentLine = 0;

	sf::Text sfHighScoreText;
	texts.push_back(&CreateTextToDisplay(sfHighScoreText, m_highScoreText, 0.0f, CalculateYPos(currentLine++)));

	sf::Text sfHighScoreValue;

	string highScoreValueText(std::to_string(highScoreValue));

	if (!hasHighScore)
	{
		highScoreValueText.append(" (");
		highScoreValueText.append(high.GetName());
		highScoreValueText.append(")");
	}

	texts.push_back(&CreateTextToDisplay(sfHighScoreValue, highScoreValueText, 0.0f, CalculateYPos(currentLine++), hasHighScore));

	++currentLine;

	sf::Text sfCurrentScoreText;
	texts.push_back(&CreateTextToDisplay(sfCurrentScoreText, m_currentScoreText, 0.0f, CalculateYPos(currentLine++)));

	sf::Text sfCurrentScoreValue;
	texts.push_back(&CreateTextToDisplay(sfCurrentScoreValue, std::to_string(currentScore), 0.0f, CalculateYPos(currentLine++), hasHighScore));

	++currentLine;

	sf::Text sfNextScoreText;
	texts.push_back(&CreateTextToDisplay(sfNextScoreText, m_nextScoreText, 0.0f, CalculateYPos(currentLine++)));
	
	sf::Text sfNextScoreValueText;
	string nextScoreValueText;

	if (hasHighScore)
	{
		nextScoreValueText.append(m_noneLeft);
	}
	else
	{
		nextScoreValueText.append(std::to_string(next.GetScore()));
		nextScoreValueText.append(" (");
		nextScoreValueText.append(next.GetName());
		nextScoreValueText.append(")");
	}

	texts.push_back(&CreateTextToDisplay(sfNextScoreValueText, nextScoreValueText, 0.0f, CalculateYPos(currentLine++)));

	std::list<sf::Text* const>::const_iterator it;

	for (it = texts.begin(); it != texts.end(); ++it)
	{
		render(window, **it);
	}
}

sf::Text& ScoreRenderer::CreateTextToDisplay(sf::Text& text, const std::string& str, float posX, float posY, bool bold, sf::Color color) const
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

float ScoreRenderer::CalculateYPos(int currentLine) const
{
	return float(currentLine * m_characterSize);
}
