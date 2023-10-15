#include "Rooks.h"
#include "Board.h"

bool Rooks::IsMoveValid(const Vector2i& from, const Vector2i& to, Board& board)
{
    // ѕолучаем разницу в позици€х между начальной и конечной клетками.
    Vector2i diff = to - from;
    int rooksColor = board.GetCageArray()[from.x][from.y].unit->GetColor();

    if (diff.x == 0 && diff.y != 0) 
    {
        int stepY = (diff.y > 0) ? 1 : -1;

        // ѕроверка, что на пути ладьи нет других фигур
        for (int y = from.y + stepY; y != to.y; y += stepY) 
        {
            if (board.GetCageArray()[from.x][y].unit != nullptr) {
                return false; // ѕуть заблокирован другой фигурой
            }
        }

        // ѕроверка, что целева€ клетка пуста или содержит фигуру противоположного цвета
        if (board.GetCageArray()[to.x][to.y].unit == nullptr || board.GetCageArray()[to.x][to.y].unit->GetColor() != rooksColor) {
            // ”ничтожение фигуры на целевой клетке, если она там есть
            if (board.GetCageArray()[to.x][to.y].unit != nullptr) {
                board.GetCageArray()[to.x][to.y].unit->SetFigurePosition(Vector2i(-1, -1));
            }
            return true;
        }
    }
    else if (diff.y == 0 && diff.x != 0) {
        int stepX = (diff.x > 0) ? 1 : -1;

        // ѕроверка, что на пути ладьи нет других фигур
        for (int x = from.x + stepX; x != to.x; x += stepX) 
        {
            if (board.GetCageArray()[x][from.y].unit != nullptr) {
                return false; // ѕуть заблокирован другой фигурой
            }
        }

        // ѕроверка, что целева€ клетка пуста или содержит фигуру противоположного цвета
        if (board.GetCageArray()[to.x][to.y].unit == nullptr || board.GetCageArray()[to.x][to.y].unit->GetColor() != rooksColor) {
            // ”ничтожение фигуры на целевой клетке, если она там есть
            if (board.GetCageArray()[to.x][to.y].unit != nullptr) {
                board.GetCageArray()[to.x][to.y].unit->SetFigurePosition(Vector2i(-1, -1));
            }
            return true;
        }
    }

    return false;
}

Rooks::Rooks(Vector2i& pos)
{
    figureType = ROOK;
    position = pos;
    if (pos.x > 4)
    {
        LoadTexture("Sprites\\Chess_WRooks.png");
        color = WHITE;
    }
    else
    {
        LoadTexture("Sprites\\Chess_BRooks.png");
        color = BLACK;
    }
}
