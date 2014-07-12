#include "stdafx.h"
#include "StateManager.h"
#include "State.h"

StateManager::StateManager(void) {
	m_current = nullptr;
}
StateManager::~StateManager(void) {
	for (std::vector<State *>::iterator it = m_states.begin(); it != m_states.end(); it++) {
		delete (*it);
	}
	m_states.clear();

	m_current = nullptr;
}

void StateManager::AddState(State *state) {
	m_states.push_back(state);
}
void StateManager::SetState(std::string type) {
	if (m_current != nullptr) {
		m_current->Exit();
		m_current = nullptr;
	}

	for (std::vector<State *>::iterator it = m_states.begin(); it != m_states.end(); it++) {
		if ((*it)->IsType(type)) {
			if ((*it)->Enter()) {
				m_current = (*it);
			}
			return;
		}
	}
}

void StateManager::Update(float deltatime) {
	if (m_current != nullptr) {
		if (m_current->UpdateEvents() || m_current->Update(deltatime)) {
			SetState(m_current->Next());
		}
	}
}
void StateManager::Draw() {
	if (m_current != nullptr) {
		m_current->Draw();
	}
}

bool StateManager::IsRunning() {
	return m_current != nullptr;
}