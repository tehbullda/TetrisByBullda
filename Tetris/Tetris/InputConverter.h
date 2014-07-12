#pragma once

class InputConverter {
public:
	enum Action {
		KEY_ROTATE,
		KEY_REVERSEROTATE,
		KEY_BOOST,
		KEY_LEFT,
		KEY_RIGHT,
		KEY_DROP,
		KEY_COUNT
	};

public:
	InputConverter();
	~InputConverter();

	bool LoadBinds(std::string filename);
	void SaveBinds(std::string filename);
	void SetDefaultBinds();

	void LoadLabels(std::string filename);

	std::string GetAction(int value);
	std::string GetActionLabel(int value);
	std::string GetBind(Action action);
	std::string GetBind(int value);
	int GetKey(Action action);

	std::string GetLabel(int code);

	void SetBind(Action action, std::string bind, int key);
	bool SetBind(std::string action, std::string bind, int key);

	bool CheckConflicts(int index);

	std::string ActionToString(Action action);
	std::string ActionToStringLabel(Action action);
	std::string KeyToMappedLabel(int key);

	Action StringToAction(std::string str);

	int KeyToInt(Action action);
private:
	std::map<Action, std::string> m_actions;
	std::map<int, std::string> m_labels;
};

