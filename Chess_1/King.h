#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"

class King :public Unit{
public:
	bool IsMoveValid(const Vector2i& from, const Vector2i& to, Board& board);
	King(Vector2i& pos);
};