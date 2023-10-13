#include "Knight.h"
#include "Board.h"

bool Knight::IsMoveValid(const Vector2i& from, const Vector2i& to, Board& board) 
{
    // �������� ������� � �������� ����� ��������� � �������� ��������.
    Vector2i diff = to - from;
    int knightColor = board.GetCageArray()[from.x][from.y].unit->GetColor();

    // ��������, ��� ���� ��������� � ����� ����� "L"
    if ((abs(diff.x) == 2 && abs(diff.y) == 1) || (abs(diff.x) == 1 && abs(diff.y) == 2)) 
    {
        // ��������, ��� ������� ������ ����� ��� �������� ������ ���������������� �����
        if (board.GetCageArray()[to.x][to.y].unit == nullptr || board.GetCageArray()[to.x][to.y].unit->GetColor() != knightColor) 
        {
            // ����������� ������ �� ������� ������, ���� ��� ��� ����
            if (board.GetCageArray()[to.x][to.y].unit != nullptr) {
                board.GetCageArray()[to.x][to.y].unit->SetFigurePosition(Vector2i(-1, -1));
            }
            return true;
        }
    }

    return false;
}
