#pragma once

#include "stdafx.h"

namespace btetris
{
	class HighScoreRecord
	{
	public:
		HighScoreRecord();
		HighScoreRecord(int score, const std::string& name);
		int GetScore() const;
		std::string GetName() const;
		void SetScore(int score);
		void SetName(const std::string& name);

		friend bool operator< (const HighScoreRecord& r1, const HighScoreRecord& r2)
		{
			return r1.GetScore() < r2.GetScore();
		}

	private:
		int m_score;
		std::string m_name;
	};
}
