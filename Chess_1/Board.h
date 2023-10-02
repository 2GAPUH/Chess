#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Unit.h"
using namespace sf;
#define COLUMN_COUNT 8
#define ROW_COUNT 8
#define FIGURES_COUNT 32

class Cage
{
public:
	Unit* unit = NULL;
	int j = 0;
};

class Board
{
	Cage** cageArray;
	Unit* figuresArray[32] = {0};

	Texture* texture = NULL;
	Sprite* sprite = NULL;

public:
	Board(const std::string& path);
	~Board();
	void Draw(RenderWindow* win);
	void FillFigures(Unit* figuresArray[], Cage** cageArray);
};