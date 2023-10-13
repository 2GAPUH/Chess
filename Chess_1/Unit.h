#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
#include <string.h>
#define BLACK 1
#define WHITE 0
#define QUEEN 1
#define PAWN 2
#define ROOKS 3
#define KING 4
#define BISHOP 5
#define KNIGHT 6

class Board;

class Unit
{
private:
	bool isSelected = false;// alex
	bool selected = false;// alex
protected:
	Texture* texture;
	Sprite* sprite;
	int color = 0;
	int figureType = 0;

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

