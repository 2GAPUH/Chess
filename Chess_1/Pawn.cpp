#include "Pawn.h"
#include "Board.h"

bool Pawn::IsMoveValid(const Vector2i& from, const Vector2i& to, Board& board) {
    // �������� ������� � �������� ����� ��������� � �������� ��������.
         Vector2i diff = to - from;
        int pawnColor = GetColor();
        int forwardDirection;
        if (GetColor() == WHITE) {
            forwardDirection = -1; // ��� ����� ����� �������� ������
        }
        else {
            forwardDirection = 1; // ��� ������ ����� �������� ������
        }

        // ����� ����� ��������� �� ���� ������ ������ � ������������ � ������������
        if (diff.x == forwardDirection && diff.y == 0) 
        {
            // ��������, ��� ������� ������ �����
            if (board.GetCageArray()[to.x][to.y].unit == nullptr)
            {
                return true;
            }
        }

        // ����� ����� ��������� �� ��������� � ������������ � ������������
        if (abs(diff.x) == 1 && diff.y == 1) 
        {
            // ��������, ��� �� ������� ������ ����� ������ ���������������� �����
            if (board.GetCageArray()[to.x][to.y].unit != nullptr &&
                board.GetCageArray()[to.x][to.y].unit->GetColor() != GetColor()) 
            {
                return true;
            }
        }

        // ����� ����� ��������� �� ��� ������ ������ ��� ������ ����
        if (!hasMoved && diff.x == 2 * forwardDirection && diff.y == 0) {
            // ��������, ��� ������� ������ �����
            if (board.GetCageArray()[to.x][to.y].unit == nullptr && board.GetCageArray()[from.x + forwardDirection][from.y].unit == nullptr) 
            {
                ((Pawn*)board.GetCageArray()[to.x][to.y].unit)->hasMoved = 1;
                return true;
            }
        }

        return false;
}
