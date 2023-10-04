#pragma once
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class SelectCirc
{
	String path = "Sprites//Chess_SelectCirc.png";
	Texture* texture = NULL;
	Sprite* sprite = NULL;
	bool state = false;
	Vector2i position = {0, 0};

public:
	SelectCirc();
	~SelectCirc();
	void SetState(bool st);
	bool GetState();
	void SetPosition(Vector2i pos);
	void Draw(RenderWindow* win, Vector2f scale);
};