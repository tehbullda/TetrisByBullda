#include "stdafx.h"
#include "State_Game.h"
#include "BlockManager.h"
#include "InputConverter.h"
#include "TextureManager.h"

State_Game::State_Game(sf::RenderWindow *window) {
	m_window = window;
}
State_Game::~State_Game(void){

}

bool State_Game::Enter() {
	m_texture_manager = new TextureManager("../data/textures/");
	m_block_manager = new BlockManager(m_texture_manager);
	m_block_manager->SetBlockSpeed(3);

	m_input_converter = new InputConverter;
	m_input_converter->SetDefaultBinds();

	m_bg_grid.setTexture(*m_texture_manager->Load("Background_340x640plus2x2border.png"));
	m_bg_grid.setPosition(468, 38);

	m_input = "";
	return true;
}
void State_Game::Exit() {
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
	sf::Event e;
	while (m_window->pollEvent(e)) {
		if (e.type == sf::Event::Closed) {
			m_next = "";
			return true;
		}
		else if (e.type == sf::Event::KeyPressed) {
			if (m_input_converter->GetKey(InputConverter::Action::KEY_BOOST) == e.key.code) {
				m_block_manager->SetBlockSpeed(10);
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
			m_block_manager->SetBlockSpeed(3);
		}

	}
	return false;
}