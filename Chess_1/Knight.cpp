#include "Knight.h"
#include "Board.h"

bool Knight::IsMoveValid(const Vector2i& from, const Vector2i& to, Board& board) 
{
    // ѕолучаем разницу в позици€х между начальной и конечной клетками.
    Vector2i diff = to - from;
    int knightColor = board.GetCageArray()[from.x][from.y].unit->GetColor();

    // ѕроверка, что конь двигаетс€ в форме буквы "L"
    if ((abs(diff.x) == 2 && abs(diff.y) == 1) || (abs(diff.x) == 1 && abs(diff.y) == 2)) 
    {
        // ѕроверка, что целева€ клетка пуста или содержит фигуру противоположного цвета
        if (board.GetCageArray()[to.x][to.y].unit == nullptr || board.GetCageArray()[to.x][to.y].unit->GetColor() != knightColor) 
        {
            // ”ничтожение фигуры на целевой клетке, если она там есть
            if (board.GetCageArray()[to.x][to.y].unit != nullptr) {
                board.GetCageArray()[to.x][to.y].unit->SetFigurePosition(Vector2i(-1, -1));
            }
            return true;
        }
    }

    return false;
}

Knight::Knight(Vector2i& pos)
{
    figureType = KNIG;
    position = pos;
    if (pos.x > 4)
    {
        LoadTexture("Sprites\\Chess_WKnight.png");
        color = WHITE;
    }
    else
    {
        LoadTexture("Sprites\\Chess_BKnight.png");
        color = BLACK;
    }
}
