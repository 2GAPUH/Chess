#include "Unit.h"
int Unit::figuresInitCount = 0;


void Unit::SetFigureType(int type)
{
	figureType = type;
}

int Unit::GetFigureType()
{
	return figureType;
}

void Unit::SetFigurePosition(Vector2i pos)
{
	position = pos;
}

Vector2i Unit::GetFigurePosition()
{
	return position;
}

void Unit::Draw()
{
	
}

Unit::Unit()
{
	std::string path;

	switch (Unit::figuresInitCount)
	{
	case 0:
	case 1:
		path = "Sprites\\Chess_BRooks.png";
		color = BLACK;
		break;

	case 2:
	case 3:
		path = "Sprites\\Chess_BKnight.png";
		color = BLACK;
		break;

	case 4:
	case 5:
		path = "Sprites\\Chess_BBishop.png";
		color = BLACK;
		break;

	case 6:
		path = "Sprites\\Chess_BQuen.png";
		color = BLACK;
		break;

	case 7:
		path = "Sprites\\Chess_BKing.png";
		color = BLACK;
		break;

	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		path = "Sprites\\Chess_BPawn.png";
		color = BLACK;
		break;


	case 16:
	case 17:
		path = "Sprites\\Chess_WRooks.png";
		color = WHITE;
		break;

	case 18:
	case 19:
		path = "Sprites\\Chess_WKnight.png";
		color = WHITE;
		break;

	case 20:
	case 21:
		path = "Sprites\\Chess_WBishop.png";
		color = WHITE;
		break;

	case 22:
		path = "Sprites\\Chess_WQuen.png";
		color = WHITE;
		break;

	case 23:
		path = "Sprites\\Chess_WKing.png";
		color = WHITE;
		break;

	case 24:
	case 25:
	case 26:
	case 27:
	case 28:
	case 29:
	case 30:
	case 31:
		path = "Sprites\\Chess_WPawn.png";
		color = WHITE;
		break;
	}


	image = new Image;
	texture = new Texture;
	sprite = new Sprite;

	image->loadFromFile(path);
	texture->loadFromImage(*image);
	sprite->setTexture(*texture);

	Unit::figuresInitCount++;
	if (Unit::figuresInitCount <= 31)
		Unit::figuresInitCount = 0;
}

Unit::~Unit()
{

	delete image;
	delete texture;
	delete sprite;
}

Vector2i Unit::GetPosition()
{
	return position;
}

