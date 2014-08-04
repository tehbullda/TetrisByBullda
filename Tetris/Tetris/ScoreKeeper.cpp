#include "stdafx.h"
#include "ScoreKeeper.h"
#include <iostream>

using namespace btetris;

ScoreKeeper::ScoreKeeper()
{}

bool ScoreKeeper::Initialize()
{
	if (!m_highScoreList.Load())
	{
		std::cout << "Error: failed to initialize highscore list";
		return false;
	}

	return true;
}

void ScoreKeeper::IncreaseScoreBy(int score)
{
	if (score != 0)
	{
		int currentScore = m_currentScoreRecord.GetScore();
		m_currentScoreRecord.SetScore(currentScore + score);
	}
}

HighScoreRecord ScoreKeeper::GetHighScore() const
{
	int currentScore = m_currentScoreRecord.GetScore();
	int currentPos = m_highScoreList.CalculatePositionFor(currentScore);

	if (currentPos == 1)
	{
		return m_currentScoreRecord;
	}

	return m_highScoreList.GetHighScoreAt(1);
}

HighScoreRecord ScoreKeeper::GetCurrentScore() const
{
	return m_currentScoreRecord;
}

HighScoreRecord ScoreKeeper::GetNextOnList() const
{
	int currentScore = m_currentScoreRecord.GetScore();
	int currentPos = m_highScoreList.CalculatePositionFor(currentScore);

	if (currentPos == 1)
	{
		return m_currentScoreRecord;
	}

	return m_highScoreList.GetHighScoreAt(currentPos - 1);
}

void ScoreKeeper::UpdateHighScore(const std::string& playerName)
{
	m_currentScoreRecord.SetName(playerName);
	m_highScoreList.Put(m_currentScoreRecord);
	m_highScoreList.Save();
}

bool ScoreKeeper::IsHighScore() const
{
	return m_highScoreList.IsHighScore(m_currentScoreRecord.GetScore());
}
