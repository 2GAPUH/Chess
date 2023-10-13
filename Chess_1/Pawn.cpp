#include "Pawn.h"
#include "Board.h"

bool Pawn::IsMoveValid(const Vector2i& from, const Vector2i& to, Board& board) {
    // �������� ������� � �������� ����� ��������� � �������� ��������.
         Vector2i diff = to - from;
        int pawnColor = board.GetCageArray()[from.x][from.y].unit->GetColor();
        int forwardDirection;
        if (pawnColor == WHITE) {
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
                ((Pawn*)board.GetCageArray()[from.x][from.y].unit)->hasMoved = 1;
                return true;
            }
        }

       // board.GetCircArray()[0][0].SetState(1);

        // ����� ����� ��������� �� ��������� � ������������ � ������������
        if (abs(diff.x) == 1 && (diff.y == 1 || diff.y == -1))
        {
            // ��������, ��� �� ������� ������ ����� ������ ���������������� �����
            if (board.GetCageArray()[to.x][to.y].unit != nullptr &&
                board.GetCageArray()[to.x][to.y].unit->GetColor() != pawnColor)
            {
                board.GetCageArray()[to.x][to.y].unit->SetFigurePosition(Vector2i(-1, -1));
                return true;
            }
        }

        // ����� ����� ��������� �� ��� ������ ������ ��� ������ ����
        if (!hasMoved && diff.x == 2 * forwardDirection && diff.y == 0) 
        {
            // ��������, ��� ������� ������ �����
            if (board.GetCageArray()[to.x][to.y].unit == nullptr && board.GetCageArray()[from.x + forwardDirection][from.y].unit == nullptr) 
            {
                ((Pawn*)board.GetCageArray()[from.x][from.y].unit)->hasMoved = 1;
                return true;
            }
        }

        return false;
}
