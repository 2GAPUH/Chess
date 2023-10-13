#include "King.h"
#include "Board.h"


bool King::IsMoveValid(const Vector2i& from, const Vector2i& to, Board& board)
{
    // �������� ������� � �������� ����� ��������� � �������� ��������.
    Vector2i diff = to - from;
    int kingColor = board.GetCageArray()[from.x][from.y].unit->GetColor();

    // ��������, ��� ������ ��������� �� ���� ������ � ����� �����������
    if (abs(diff.x) <= 1 && abs(diff.y) <= 1) 
    {
        // ��������, ��� ������� ������ ����� ��� �������� ������ ���������������� �����
        if (board.GetCageArray()[to.x][to.y].unit == nullptr || board.GetCageArray()[to.x][to.y].unit->GetColor() != kingColor) {
            // ����������� ������ �� ������� ������, ���� ��� ��� ����
            if (board.GetCageArray()[to.x][to.y].unit != nullptr) {
                board.GetCageArray()[to.x][to.y].unit->SetFigurePosition(Vector2i(-1, -1));
            }
            return true;
        }
    }

    return false;
}