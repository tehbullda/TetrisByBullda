// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include <stdio.h>
#include <tchar.h>

#include "targetver.h"

#pragma warning(disable:4099)
#define SFML_STATIC

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "openal32.lib")
#pragma comment(lib, "sndfile.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "freetype.lib")
#pragma comment(lib, "glew.lib")
#pragma comment(lib, "jpeg.lib")

#if defined(_DEBUG)
#pragma comment(lib, "Debug/sfml-system-s-d.lib")
#pragma comment(lib, "Debug/sfml-window-s-d.lib")
#pragma comment(lib, "Debug/sfml-graphics-s-d.lib")
#pragma comment(lib, "Debug/sfml-audio-s-d.lib")
//#define NOMINMAX
//#pragma comment(lib, "vld.lib")
//#include <../Debugging/vld.h>
#else
#pragma comment(lib, "Release/sfml-audio-s.lib")
#pragma comment(lib, "Release/sfml-graphics-s.lib")
#pragma comment(lib, "Release/sfml-system-s.lib")
#pragma comment(lib, "Release/sfml-window-s.lib")
#endif

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

// TODO: reference additional headers your program requires here
