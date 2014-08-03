#pragma once

#include "stdafx.h"
#include "ScoreRenderer.h"
#include "ScoreCache.h"

namespace btetris
{
	// Responsible for updating the score
	class ScoreKeeper
	{
	public:
		ScoreKeeper();
		void updateCurrentScore(int score);
		void renderScores(sf::RenderWindow& window) const;
		void storePersistently() const;
	private:
		ScoreRenderer m_scoreRenderer;
		ScoreCache m_scoreCache;
	};
}
