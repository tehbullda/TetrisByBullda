#pragma once

#include "State.h"

class BlockManager;
class TextureManager;
class InputConverter;

class State_Game : public State {
public:
	State_Game(sf::RenderWindow *window);
	~State_Game(void);

	bool Enter();
	void Exit();

	bool Update(float deltatime);
	void Draw();

	void DrawBG();

	std::string Next();
	bool IsType(std::string check);
private:

	bool UpdateEvents();
private:
	sf::RenderWindow *m_window;
	sf::View m_view;

	BlockManager *m_block_manager;
	TextureManager *m_texture_manager;
	InputConverter *m_input_converter;
	std::string m_input;

	std::string m_next, m_state;


};