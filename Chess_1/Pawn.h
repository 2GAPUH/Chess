#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"

class Pawn : public Unit {
public:
    bool isStartPos = 1;
    bool hasMoved = 0;
    bool IsMoveValid(const Vector2i& from, const Vector2i& to, Board& board);
};