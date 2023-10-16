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

void Unit::LoadTexture(sf::String path)
{
	texture = new Texture;
	sprite = new Sprite;

	texture->loadFromFile(path);
	sprite->setTexture(*texture);
}

Vector2i Unit::GetPosition()
{
	return position;
}


void Unit::Draw(RenderWindow * win, Vector2f scale)
{
	auto texSize = texture->getSize();
	auto winSize = win->getSize();

	sprite->setScale(scale);

	sprite->setPosition(position.x * texSize.x * scale.x + BOARD_SCALE * scale.x, position.y * texSize.y * scale.y + BOARD_SCALE * scale.y);

	win->draw(*sprite);
}

bool Unit::IsMoveValid(const Vector2i& from, const Vector2i& to, Board& board)
{
	return false;
}



Unit::Unit()
{
	Unit::figuresInitCount++;
	if (Unit::figuresInitCount >= FIGURES_COUNT)
		Unit::figuresInitCount = 0;
}


Unit::~Unit()
{
	delete texture;
	delete sprite;
}



