#pragma once

#include <string>

using namespace std;

class State {
public:
	virtual ~State() {};

	virtual bool Enter() = 0;
	virtual void Exit() = 0;

	virtual bool Update(float deltatime) = 0;
	virtual bool UpdateEvents() = 0;
	virtual void Draw() = 0;

	virtual std::string Next() = 0;
	virtual bool IsType(std::string check) = 0;
};