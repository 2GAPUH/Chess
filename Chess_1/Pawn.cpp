#include "Pawn.h"
#include "Board.h"

bool Pawn::IsMoveValid(const Vector2i& from, const Vector2i& to, Board& board) {
    // ѕолучаем разницу в позици€х между начальной и конечной клетками.
         Vector2i diff = to - from;
        int pawnColor = GetColor();
        int forwardDirection;
        if (GetColor() == WHITE) {
            forwardDirection = -1; // ƒл€ белых фигур движение вперед
        }
        else {
            forwardDirection = 1; // ƒл€ черных фигур движение вперед
        }

        // ѕешка может двигатьс€ на одну клетку вперед в соответствии с направлением
        if (diff.x == forwardDirection && diff.y == 0) 
        {
            // ѕроверка, что целева€ клетка пуста
            if (board.GetCageArray()[to.x][to.y].unit == nullptr)
            {
                return true;
            }
        }

        // ѕешка может атаковать по диагонали в соответствии с направлением
        if (abs(diff.x) == 1 && diff.y == 1) 
        {
            // ѕроверка, что на целевой клетке стоит фигура противоположного цвета
            if (board.GetCageArray()[to.x][to.y].unit != nullptr &&
                board.GetCageArray()[to.x][to.y].unit->GetColor() != GetColor()) 
            {
                return true;
            }
        }

        // ѕешка может двигатьс€ на две клетки вперед при первом ходе
        if (!hasMoved && diff.x == 2 * forwardDirection && diff.y == 0) {
            // ѕроверка, что целевые клетки пусты
            if (board.GetCageArray()[to.x][to.y].unit == nullptr && board.GetCageArray()[from.x + forwardDirection][from.y].unit == nullptr) 
            {
                ((Pawn*)board.GetCageArray()[to.x][to.y].unit)->hasMoved = 1;
                return true;
            }
        }

        return false;
}
