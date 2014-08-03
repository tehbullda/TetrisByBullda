#include "stdafx.h"
#include "ScoreKeeper.h"

using namespace btetris;

ScoreKeeper::ScoreKeeper()
{}

void ScoreKeeper::updateCurrentScore(int score)
{
	m_scoreCache.updateCurrentScore(score);
}

void ScoreKeeper::renderScores(sf::RenderWindow& window) const
{
	m_scoreRenderer.renderScores(window, m_scoreCache.getHighScore(), m_scoreCache.getCurrentScore());
}

void ScoreKeeper::storePersistently() const
{
	m_scoreCache.storePersistently();
}
