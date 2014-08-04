#pragma once

#include "stdafx.h"
#include "ScoreKeeper.h"

namespace btetris
{
	class ScoreUpdater
	{
	public:
		ScoreUpdater();
		bool Initialize(sf::RenderWindow* const window);
		void IncreaseScoreBy(int score);
		void EndGame(const std::string& playerName);
		bool IsHighScore() const;
		void Finalize();

	private:

		// noncopyable
		ScoreUpdater(const ScoreUpdater& copy);
		ScoreUpdater& operator=(const ScoreUpdater& rhs);
		
		sf::RenderWindow* m_renderWindow;
		ScoreKeeper m_scoreKeeper;
		ScoreRenderer m_scoreRenderer;

		bool m_initialized;
	};
}
