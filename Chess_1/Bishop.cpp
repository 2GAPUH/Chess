#include "Bishop.h"
#include "Board.h"


bool Bishop::IsMoveValid(const Vector2i& from, const Vector2i& to, Board& board)
{
    Vector2i diff = to - from;
    int bishopColor = board.GetCageArray()[from.x][from.y].unit->GetColor();

    // ѕровер€ем, что слон двигаетс€ по диагонали (абсолютное значение x равно абсолютному значению y)
    if (abs(diff.x) != abs(diff.y)) {
        return false; // —лон может двигатьс€ только по диагонали
    }

    int stepX = 0, stepY = 0;

    if (from.x != to.x || from.y!=from.y)
    {
        stepX = (diff.x > 0) ? 1 : -1;
        stepY = (diff.y > 0) ? 1 : -1;
    }


    Vector2i current = from + Vector2i(stepX, stepY);

    while (current != to) 
    {
        // ѕровер€ем, что на пути нет фигур
        if (board.GetCageArray()[current.x][current.y].unit != nullptr)
        {
            return false; // ѕреграда на пути
        }
        current += Vector2i(stepX, stepY);
    }

    // ѕровер€ем, что конечна€ клетка пуста

    if (board.GetCageArray()[to.x][to.y].unit != nullptr) {
        if (board.GetCageArray()[to.x][to.y].unit->GetColor() == bishopColor) {
            return false; // —лон не может стать на клетку с фигурой того же цвета
        }
        else {
            // ”ничтожаем вражескую фигуру
            board.GetCageArray()[to.x][to.y].unit->SetFigurePosition(Vector2i(-1, -1));
        }
    }

    // ≈сли все проверки прошли успешно, ход допустим
    return true;
}

