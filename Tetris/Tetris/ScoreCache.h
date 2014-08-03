#include "stdafx.h"

namespace btetris
{
	class ScoreCache
	{
	public:
		ScoreCache();
		int getCurrentScore() const;
		int getHighScore() const;
		void updateCurrentScore(int score);
		void storePersistently() const;
	private:
		int m_currentScore;
		int m_highScore;
	};
}
