#include "stdafx.h"
#include "HighScoreRecord.h"

using namespace btetris;

HighScoreRecord::HighScoreRecord()
:	m_score(0),
	m_name("")
{

}

HighScoreRecord::HighScoreRecord(int score, const std::string& name)
:	m_score(score),
	m_name(name)
{

}

int HighScoreRecord::GetScore() const
{
	return m_score;
}

std::string HighScoreRecord::GetName() const
{
	return m_name;
}

void HighScoreRecord::SetScore(int score)
{
	m_score = score;
}

void HighScoreRecord::SetName(const std::string& name)
{
	m_name = name;
}

