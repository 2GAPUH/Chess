#include "Queen.h"
#include "Board.h"

bool Queen::IsMoveValid(const Vector2i& from, const Vector2i& to, Board& board) {
    // ѕолучаем разницу в позици€х между начальной и конечной клетками.
    Vector2i diff = to - from;
    int queenColor = board.GetCageArray()[from.x][from.y].unit->GetColor();

    // ѕроверка, что королева двигаетс€ либо как ладь€, либо как слон

    // ƒвижение как ладь€
    if (diff.x == 0 && diff.y != 0) {
        int stepY = (diff.y > 0) ? 1 : -1;

        for (int y = from.y + stepY; y != to.y; y += stepY) {
            if (board.GetCageArray()[from.x][y].unit != nullptr) {
                return false;
            }
        }

        if (board.GetCageArray()[to.x][to.y].unit == nullptr || board.GetCageArray()[to.x][to.y].unit->GetColor() != queenColor) {
            if (board.GetCageArray()[to.x][to.y].unit != nullptr) {
                board.GetCageArray()[to.x][to.y].unit->SetFigurePosition(Vector2i(-1, -1));
            }
            return true;
        }
    }
    else if (diff.y == 0 && diff.x != 0) {
        int stepX = (diff.x > 0) ? 1 : -1;

        for (int x = from.x + stepX; x != to.x; x += stepX) {
            if (board.GetCageArray()[x][from.y].unit != nullptr) {
                return false;
            }
        }

        if (board.GetCageArray()[to.x][to.y].unit == nullptr || board.GetCageArray()[to.x][to.y].unit->GetColor() != queenColor) {
            if (board.GetCageArray()[to.x][to.y].unit != nullptr) {
                board.GetCageArray()[to.x][to.y].unit->SetFigurePosition(Vector2i(-1, -1));
            }
            return true;
        }
    }

    // ƒвижение как слон
    if (abs(diff.x) == abs(diff.y)) 
    {
        int stepX = 0, stepY = 0;

        if (from.x != to.x || from.y != from.y)
        {
            stepX = (diff.x > 0) ? 1 : -1;
            stepY = (diff.y > 0) ? 1 : -1;
        }

        for (int x = from.x + stepX, y = from.y + stepY; x != to.x || y != to.y; x += stepX, y += stepY) {
            if (board.GetCageArray()[x][y].unit != nullptr) {
                return false;
            }
        }

        if (board.GetCageArray()[to.x][to.y].unit == nullptr || board.GetCageArray()[to.x][to.y].unit->GetColor() != queenColor) {
            if (board.GetCageArray()[to.x][to.y].unit != nullptr) {
                board.GetCageArray()[to.x][to.y].unit->SetFigurePosition(Vector2i(-1, -1));
            }
            return true;
        }
    }

    return false;
}

Queen::Queen(Vector2i& pos)
{
    figureType = QUEN;
    position = pos;
    if (pos.x > ROW_COUNT/2)
    {
        LoadTexture("Sprites\\Chess_WQuen.png");
        color = WHITE;
    }
    else
    {
        LoadTexture("Sprites\\Chess_BQuen.png");
        color = BLACK;
    }
}
