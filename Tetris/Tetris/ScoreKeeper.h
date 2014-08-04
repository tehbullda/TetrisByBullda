#pragma once

#include "stdafx.h"
#include "ScoreRenderer.h"
#include "HighScoreRecord.h"
#include "HighScoreList.h"

namespace btetris
{
	// Responsible for updating the score
	class ScoreKeeper
	{
	public:
		ScoreKeeper();
		bool Initialize();
		void IncreaseScoreBy(int score);
		HighScoreRecord GetHighScore() const;
		HighScoreRecord GetCurrentScore() const;
		HighScoreRecord GetNextOnList() const;
		bool IsHighScore() const;

		void UpdateHighScore(const std::string& playerName);
	private:
		HighScoreRecord m_currentScoreRecord;
		HighScoreList m_highScoreList;
	};
}
