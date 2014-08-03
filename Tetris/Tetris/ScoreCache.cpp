#include "stdafx.h"
#include "ScoreCache.h"

using namespace btetris;

ScoreCache::ScoreCache()
:	m_currentScore(0),
	m_highScore(0) // initialize this from file 
{

}

int ScoreCache::getCurrentScore() const
{
	return m_currentScore;
}

int ScoreCache::getHighScore() const
{
	return m_highScore;
}

void ScoreCache::updateCurrentScore(int score)
{
	if (m_currentScore != score)
	{
		m_currentScore = score;
	}
}

void ScoreCache::storePersistently() const
{
	// store to file
}