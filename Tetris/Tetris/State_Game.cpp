#include "stdafx.h"
#include "State_Game.h"
#include "BlockManager.h"
#include "InputConverter.h"
#include "TextureManager.h"

using namespace std;

State_Game::State_Game(sf::RenderWindow *window) {
	m_window = window;
}
State_Game::~State_Game(void){

}

bool State_Game::Enter() {
	m_texture_manager = new TextureManager("../data/textures/");
	m_block_manager = new BlockManager(m_texture_manager);
	m_block_manager->SetBlockSpeed(0.25f);

	m_input_converter = new InputConverter;
	m_input_converter->SetDefaultBinds();

	m_bg_grid.setTexture(*m_texture_manager->Load("Background_340x640plus2x2border.png"));
	m_bg_grid.setPosition(468, 38);

	m_input = "";

	if (!m_scoreUpdater.Initialize(m_window))
	{
		return false;
	}

	return true;
}
void State_Game::Exit() {

	if (m_scoreUpdater.IsHighScore())
	{
		m_scoreUpdater.EndGame("NoName");
	}

	m_scoreUpdater.Finalize();
	m_input_converter->SaveBinds("../data/bindings/binds.ini");
}

bool State_Game::Update(float deltatime) {
	if (m_input != "") {
		m_block_manager->Update(deltatime, m_input);
	}
	else {
		m_block_manager->Update(deltatime);
	}

	return false;
}
void State_Game::Draw() {
	DrawBG();

	m_window->draw(m_bg_grid);
	m_block_manager->DrawBlocks(m_window);
	m_scoreUpdater.IncreaseScoreBy(1);
}

void State_Game::DrawBG() {
}

std::string State_Game::Next() {
	return m_next;
}


bool State_Game::IsType(std::string check) {
	return check.compare("Game") == 0;
}

bool State_Game::UpdateEvents() {
	m_block_manager->SetBlockSpeed(0.25f);
	sf::Event e;
	while (m_window->pollEvent(e)) {
		if (e.type == sf::Event::Closed) {
			m_next = "";
			return true;
		}
		else if (e.type == sf::Event::KeyPressed) {
			if (m_input_converter->GetKey(InputConverter::Action::KEY_BOOST) == e.key.code) {
				m_block_manager->SetBlockSpeed(2.0f);
			}
			if (m_input_converter->GetKey(InputConverter::Action::KEY_LEFT) == e.key.code) {
				m_input = "Left";
			}
			if (m_input_converter->GetKey(InputConverter::Action::KEY_RIGHT) == e.key.code) {
				m_input = "Right";
			}
			if (m_input_converter->GetKey(InputConverter::Action::KEY_ROTATE) == e.key.code) {
				m_input = "Rotate";
			}
			if (m_input_converter->GetKey(InputConverter::Action::KEY_DROP) == e.key.code) {
				m_input = "Drop";
			}
		}
		else if (e.type == sf::Event::KeyReleased) {
			m_input = "";
		}

	}
	return false;
}