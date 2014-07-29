#include "stdafx.h"

#include "Engine.h"
#include "StateManager.h"
#include "State.h"
#include "State_Game.h"

Engine::Engine() {
	
}

Engine::~Engine() {
	
}

bool Engine::Init() {
	m_window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Tetris", sf::Style::Titlebar | sf::Style::Close);
	m_state_manager = new StateManager();
	m_state_manager->AddState(new State_Game(m_window));
	m_state_manager->SetState("Game");
	return true;
}

void Engine::Run() {
	while (m_state_manager->IsRunning()) {
		m_deltatime = (float)m_clock.restart().asSeconds();
		m_state_manager->Update(m_deltatime);
		m_window->clear();
		m_state_manager->Draw();
		m_window->display();
	}
}

void Engine::Cleanup() {
	if (m_state_manager != nullptr) {
		delete m_state_manager;
		m_state_manager = nullptr;
	}
}