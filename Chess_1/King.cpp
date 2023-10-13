#include "King.h"
#include "Board.h"


bool King::IsMoveValid(const Vector2i& from, const Vector2i& to, Board& board)
{
    // Получаем разницу в позициях между начальной и конечной клетками.
    Vector2i diff = to - from;
    int kingColor = board.GetCageArray()[from.x][from.y].unit->GetColor();

    // Проверка, что король двигается на одну клетку в любом направлении
    if (abs(diff.x) <= 1 && abs(diff.y) <= 1) 
    {
        // Проверка, что целевая клетка пуста или содержит фигуру противоположного цвета
        if (board.GetCageArray()[to.x][to.y].unit == nullptr || board.GetCageArray()[to.x][to.y].unit->GetColor() != kingColor) {
            // Уничтожение фигуры на целевой клетке, если она там есть
            if (board.GetCageArray()[to.x][to.y].unit != nullptr) {
                board.GetCageArray()[to.x][to.y].unit->SetFigurePosition(Vector2i(-1, -1));
            }
            return true;
        }
    }

    return false;
}