#include "stdafx.h"
#include "InputConverter.h"


InputConverter::InputConverter() {
	for (int i = InputConverter::KEY_ROTATE; i != InputConverter::KEY_COUNT; i++) {
		m_actions.insert(std::pair<InputConverter::Action, std::string>(static_cast<Action>(i), ""));
	}
	LoadLabels("../data/bindings/key_table.txt");
}

InputConverter::~InputConverter() {
}

bool InputConverter::LoadBinds(std::string filename) {

	std::fstream stream(filename);
	if (!stream.is_open()) {
		return false;
	}
	while (!stream.eof()) {
		std::string line;
		std::getline(stream, line, '\n');
		if (line.length() == 0) {
			continue;
		}
		std::stringstream ss(line);
		std::string type;
		std::string key;
		std::string value;
		ss >> type;
		ss >> key;
		ss >> value;
		for (auto it = m_actions.begin(); it != m_actions.end(); it++) {
			if (ActionToString(it->first) == type) {
				it->second = key + " " + value;
			}
		}
	}
	return true;
}

void InputConverter::SaveBinds(std::string filename) {
	std::fstream stream(filename);
	auto it = m_actions.begin();
	while (it != m_actions.end()) {
		stream << ActionToString(it->first) << " " << it->second << "\n";
		it++;
	}
}

void InputConverter::SetDefaultBinds() {
	for (auto it = m_actions.begin(); it != m_actions.end(); it++) {
		switch (it->first) {
		case(KEY_ROTATE) : it->second = "Up 73";
			break;
		case(KEY_REVERSEROTATE) : it->second = "X 23";
			break;
		case(KEY_BOOST) : it->second = "Down 74";
			break;
		case(KEY_LEFT) : it->second = "Left 71";
			break;
		case(KEY_RIGHT) : it->second = "Right 72";
			break;
		case(KEY_DROP) : it->second = "Space 57";
			break;
		default: printf("Unknown key");
			it->second = "";
			break;
		}
	}
}

void InputConverter::LoadLabels(std::string filename) {
	std::ifstream stream(filename);
	if (!stream.is_open()) {
		return;
	}
	while (!stream.eof()) {
		std::string line;
		std::getline(stream, line, '\n');
		if (line.length() == 0) {
			continue;
		}
		std::stringstream ss(line);
		std::string key;
		std::string value;
		ss >> key;
		ss >> value;
		m_labels.insert(std::pair<int, std::string>(std::stoi(key), value));
	}
}

std::string InputConverter::GetLabel(int code) {
	return m_labels.at(code);
}

std::string InputConverter::GetAction(int value) {
	std::string ret = ActionToString(static_cast<Action>(value));
	return ret;
}

std::string InputConverter::GetActionLabel(int value) {
	std::string ret = ActionToStringLabel(static_cast<Action>(value));
	return ret;
}


std::string InputConverter::GetBind(InputConverter::Action action) {
	std::stringstream ss;
	std::string ret;
	ss << m_actions.at(action);
	ss >> ret;
	return ret;
}
std::string InputConverter::GetBind(int value) {
	if (value < 0 || value > InputConverter::KEY_COUNT) {
		return "FAIL";
	}
	std::string ret = m_actions.at(static_cast<Action>(value));
	std::string bind;
	std::stringstream ss;
	ss << ret;
	ss >> bind;
	return bind;
}

int InputConverter::GetKey(InputConverter::Action action) {
	std::stringstream ss;
	std::string type;
	std::string value;
	ss << m_actions.at(action);
	ss >> type >> value;
	return std::stoi(value);
}


void InputConverter::SetBind(InputConverter::Action action, std::string bind, int key) {
	std::stringstream ss;
	ss << bind << " " << key;
	m_actions.at(action) = ss.str();
}

bool InputConverter::SetBind(std::string action, std::string bind, int key) {
	if (key == -1 || action == "INVALID") {
		return false;
	}
	std::stringstream ss;
	ss << bind << " " << key;
	m_actions.at(StringToAction(action)) = ss.str();
	return true;
}

bool InputConverter::CheckConflicts(int index) {
	bool change = false;
	for (auto it = m_actions.begin(); it != m_actions.end(); it++) {
		if (it->first == static_cast<Action>(index)) {
			continue;
		}
		if (it->second == m_actions.at(static_cast<Action>(index))) {
			it->second = "UNBOUND -1";
			change = true;
		}
	}
	return change;
}

InputConverter::Action InputConverter::StringToAction(std::string str) {

	if (str == "KEY_ROTATE") {
		return InputConverter::KEY_ROTATE;
	}
	else if (str == "KEY_REVERSEROTATE") {
		return InputConverter::KEY_REVERSEROTATE;
	}
	else if (str == "KEY_BOOST") {
		return InputConverter::KEY_BOOST;
	}
	else if (str == "KEY_LEFT") {
		return InputConverter::KEY_LEFT;
	}
	else if (str == "KEY_RIGHT") {
		return InputConverter::KEY_RIGHT;
	}
	else if (str == "KEY_DROP") {
		return InputConverter::KEY_DROP;
	}
}


std::string InputConverter::ActionToString(InputConverter::Action action) {
	std::string ret;
	switch (action) {
	case(KEY_ROTATE) : ret = "KEY_ROTATE";
		break;
	case(KEY_REVERSEROTATE) : ret = "KEY_REVERSEROTATE";
		break;
	case(KEY_BOOST) : ret = "KEY_BOOST";
		break;
	case(KEY_LEFT) : ret = "KEY_LEFT";
		break;
	case(KEY_RIGHT) : ret = "KEY_RIGHT";
		break;
	case(KEY_DROP) : ret = "KEY_DROP";
		break;
	default: printf("Unknown key");
		break;
	}
	return ret;
}

std::string InputConverter::ActionToStringLabel(InputConverter::Action action) {
	std::string ret;
	switch (action) {
	case(KEY_ROTATE) : ret = "Rotate";
		break;
	case(KEY_REVERSEROTATE) : ret = "Reverse Rotate";
		break;
	case(KEY_BOOST) : ret = "Boost";
		break;
	case(KEY_LEFT) : ret = "Left";
		break;
	case(KEY_RIGHT) : ret = "Right";
		break;
	case(KEY_DROP) : ret = "Drop";
		break;
	default: printf("Unknown key");
		break;
	}
	return ret;
}

std::string InputConverter::KeyToMappedLabel(int key) {
	return m_labels[key];
}

int InputConverter::KeyToInt(InputConverter::Action action) {
	std::stringstream stream(m_actions.at(action));
	std::string keystr, value;
	stream >> keystr >> value;
	return std::stoi(value);
}

