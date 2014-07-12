#pragma once

class StateManager;

class Engine {
public:
	Engine();
	~Engine();

	bool Init();
	void Run();
	void Cleanup();

	float UpdateDeltaTime();

private:
	sf::RenderWindow *m_window;
	sf::Clock m_clock;
	float m_deltatime;
	StateManager *m_state_manager;
};