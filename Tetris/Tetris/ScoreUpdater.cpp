#include "stdafx.h"
#include "ScoreUpdater.h"
#include "HighScoreRecord.h"

using namespace btetris;

ScoreUpdater::ScoreUpdater()
:	m_renderWindow(0),
	m_initialized(false)
{

}

bool ScoreUpdater::Initialize(sf::RenderWindow* const window)
{
	if (window == nullptr)
	{
		return false;
	}

	m_renderWindow = window;
	
	if (m_scoreKeeper.Initialize())
	{
		m_initialized = true;
	}

	return m_initialized;
}

void ScoreUpdater::IncreaseScoreBy(int score)
{
	if (!m_initialized)
	{
		return;
	}

	m_scoreKeeper.IncreaseScoreBy(score);

	HighScoreRecord high = m_scoreKeeper.GetHighScore();
	HighScoreRecord current = m_scoreKeeper.GetCurrentScore();
	HighScoreRecord next = m_scoreKeeper.GetNextOnList();

	m_scoreRenderer.RenderScores(*m_renderWindow, high, current, next);
}

bool ScoreUpdater::IsHighScore() const
{
	return m_scoreKeeper.IsHighScore();
}

void ScoreUpdater::EndGame(const std::string& playerName)
{
	if (IsHighScore())
	{
		m_scoreKeeper.UpdateHighScore(playerName);
	}
}

void ScoreUpdater::Finalize()
{
	if (!m_initialized)
	{
		return;
	}

	m_renderWindow = nullptr; // not adopted, do not delete
	m_initialized = false;
}
