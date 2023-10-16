#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
#include <string.h>
#define BLACK 1
#define WHITE 0
#define QUEN 1
#define PAWN 2
#define ROOK 3
#define KING 4
#define BISH 5
#define KNIG 6
#define BOARD_SCALE 23
#define FIGURES_COUNT 32

class Board;

class Unit
{
private:
	bool isSelected = false;// alex
	bool selected = false;// alex
protected:
	Texture* texture = nullptr;
	Sprite* sprite = nullptr;
	int color = 0;
	int figureType = 0;
	void LoadTexture(sf::String path);
	Vector2i position;
		
public:
	Vector2i GetPosition();
	static int figuresInitCount;
	void SetFigureType(int type);
	int GetFigureType();
	void SetFigurePosition(Vector2i pos);
	Vector2i GetFigurePosition();
	void Draw(RenderWindow* win, Vector2f scale);
	virtual bool IsMoveValid(const Vector2i& from, const Vector2i& to, Board& board);
	int GetColor() {
		return color;
	}
	Unit();
	~Unit();
};

