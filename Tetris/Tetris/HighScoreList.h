#pragma once

#include "stdafx.h"
#include "HighScoreRecord.h"
#include <list>

namespace btetris
{
	class HighScoreList
	{
	public:
		HighScoreList();
		bool Load();
		bool Save() const;
		HighScoreRecord GetHighScoreAt(int position) const;
		int CalculatePositionFor(int score) const;
		void Put(const HighScoreRecord& record);
		bool IsHighScore(int score) const;

	private:
		std::list<HighScoreRecord> m_highScoreRecords;
		std::string m_highScoresPath;
		static int MAX_RECORDS;
		static char SEPARATOR;
	};
}
