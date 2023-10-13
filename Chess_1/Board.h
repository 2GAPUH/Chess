#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Unit.h"
#include "SelectCirc.h"
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
private:
	bool color=WHITE; //
	void FillFigures();
	Cage** cageArray = NULL;
	Unit* figuresArray[32] = {0};
	SelectCirc** circArray = NULL;
	Vector2f scale = { 0, 0 };
	Vector2i lastClick = { -1, -1 };
	Vector2i prevClick = { 0, 0 };

	Texture* texture = NULL;
	Sprite* sprite = NULL;

public:
	bool select = 0;
	Board(const std::string& path);
	~Board();
	void Draw(RenderWindow* win);
	void CheckClick(Vector2i mousePos);
	void InitCircs();
	void FigureSelect();
	Vector2f GetScale();
	Vector2i GetLstClick();
	Vector2i GetPrevClick();
	void SwapFigures(Vector2i pos1, Vector2i pos2);
	SelectCirc** GetCircArray();
	void ClearCircArray();
	void SetColor(bool i); //
	bool GetColor(); //
	void RefreshFigures();
	Cage** GetCageArray();
};