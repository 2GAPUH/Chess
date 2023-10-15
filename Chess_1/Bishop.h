#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"

class Bishop : public Unit {
public:
    bool IsMoveValid(const Vector2i& from, const Vector2i& to, Board& board);
    Bishop(Vector2i& pos);
};