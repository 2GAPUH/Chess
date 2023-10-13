#include "Bishop.h"
#include "Board.h"


bool Bishop::IsMoveValid(const Vector2i& from, const Vector2i& to, Board& board)
{
    Vector2i diff = to - from;
    int bishopColor = board.GetCageArray()[from.x][from.y].unit->GetColor();

    // ���������, ��� ���� ��������� �� ��������� (���������� �������� x ����� ����������� �������� y)
    if (abs(diff.x) != abs(diff.y)) {
        return false; // ���� ����� ��������� ������ �� ���������
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
        // ���������, ��� �� ���� ��� �����
        if (board.GetCageArray()[current.x][current.y].unit != nullptr)
        {
            return false; // �������� �� ����
        }
        current += Vector2i(stepX, stepY);
    }

    // ���������, ��� �������� ������ �����

    if (board.GetCageArray()[to.x][to.y].unit != nullptr) {
        if (board.GetCageArray()[to.x][to.y].unit->GetColor() == bishopColor) {
            return false; // ���� �� ����� ����� �� ������ � ������� ���� �� �����
        }
        else {
            // ���������� ��������� ������
            board.GetCageArray()[to.x][to.y].unit->SetFigurePosition(Vector2i(-1, -1));
        }
    }

    // ���� ��� �������� ������ �������, ��� ��������
    return true;
}

