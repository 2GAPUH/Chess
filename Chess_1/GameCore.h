#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Board.h"
using namespace sf;
#define DEFAULT_WIN_W 700
#define DEFAULT_WIN_H 700


class GameCore
{
	RenderWindow* win;
	Board board;

	void draw();
	void update();

public:
	void start();
	GameCore(int w, int h, const string& board_file);
	GameCore();
	~GameCore();

};
