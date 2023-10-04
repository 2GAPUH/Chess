#include "SelectCirc.h"

SelectCirc::SelectCirc()
{
	texture = new Texture;
	sprite = new Sprite;

	texture->loadFromFile(path);
	sprite->setTexture(*texture);
}

SelectCirc::~SelectCirc()
{
	delete texture;
	delete sprite;
}

void SelectCirc::SetState(bool st)
{
	state = st;
}

bool SelectCirc::GetState()
{
	return state;
}

void SelectCirc::SetPosition(Vector2i pos)
{
	position = pos;
}

void SelectCirc::Draw(RenderWindow* win, Vector2f scale)
{
	if (state)
	{
		auto winSize = win->getSize();
		auto texSize = texture->getSize();
		
		sprite->setScale(scale);

		sprite->setPosition(position.x * texSize.x * scale.x + 23 * scale.x, position.y * texSize.y * scale.y + 23 * scale.y);

		win->draw(*sprite);
	}
}
