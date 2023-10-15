#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"

class Knight :public Unit {
public:
	bool IsMoveValid(const Vector2i& from, const Vector2i& to, Board& board);
	Knight(Vector2i& pos);
};