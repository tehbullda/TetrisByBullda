#pragma once

class State;

class StateManager {
public:
	StateManager(void);
	~StateManager(void);

	void AddState(State *state);
	void SetState(std::string type);

	void Update(float deltatime);
	void Draw();

	bool IsRunning();
private:
	std::vector<State *> m_states;
	State *m_current;
};