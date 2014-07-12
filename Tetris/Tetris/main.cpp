// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Engine.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Engine* engine = new Engine;
	if (engine->Init()) {
		engine->Run();
	}
	engine->Cleanup();


	return 0;
}

