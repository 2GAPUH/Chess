#include "GameCore.h"

bool GameCore::IsMoveValid(const Vector2i& from, const Vector2i& to, Unit* selectedUnit)
{
	if (selectedUnit && !board.GetCageArray()[to.x][to.y].unit)
	{
		int figureType = selectedUnit->GetFigureType();
		int figureColor = selectedUnit->GetFigureColor(); // �������� ���� ������

		// ���������, �������� �� ������ ������
		if (figureType == PAWN)
		{
			int deltaX = to.x - from.x; // ������� �� �����������

			// ��� ������ ����� (���� == BLACK), �������� ���� ������ (���������� ���������� X)
			// ��� ����� ����� (���� == WHITE), �������� ���� ����� (���������� ���������� X)
			int validDirection = (figureColor == BLACK) ? 1 : -1;

			// ������� �������� �����
			if (deltaX == validDirection) // ������ �� ���� ������
			{
				// �������� �� ��������� ������
				if (!board.GetCageArray()[to.x][to.y].unit)
				{
					return true;
				}
			}
			else if (deltaX == validDirection * 2 && from.x == 6 && figureColor == WHITE) // ��� ���������� ���� ����� �����
			{
				// �������� �� ������� ���
				if (!board.GetCageArray()[to.x][to.y].unit && !board.GetCageArray()[to.x - validDirection][to.y].unit)
				{
					return true;
				}
			}
		}

		// ������ ������� �������� ��� ������ �����

		return false;
	}

	return false;
}




void GameCore::draw()
{
	win->clear();

	//������ �� ��� ��� �����
	board.Draw(win);

	

	win->display();
}

void GameCore::update()
{
	Event ev;
	while (win->pollEvent(ev))
	{
		//��������� � ������������ ������
		switch (ev.type)
		{
		case Event::Closed:
			win->close();
			break;

		case Event::MouseButtonPressed:
			if (ev.mouseButton.button == Mouse::Left)
			{
				board.CheckClick(Mouse::getPosition(*win));
				// Alex
				Vector2i clickedPosition = board.GetLstClick();
				Unit* clickedUnit = board.GetCageArray()[clickedPosition.x][clickedPosition.y].unit;
				if (clickedUnit)
				{
					//������� ��������� � ���������� ��������� ������
					if (selectedPiecePosition.x != -1)
					{
						board.GetCageArray()[selectedPiecePosition.x][selectedPiecePosition.y].unit->SetSelected(false);
					}

					// ������������� ����� ��������� ������
					selectedPiecePosition = clickedPosition;
					clickedUnit->SetSelected(true);

				}
			}
			break;
		case Event::MouseButtonReleased:
			if (ev.mouseButton.button == Mouse::Left)
			{
				if (selectedPiecePosition.x != -1)
				{
					//board.Swap(Vector2i(0, 0),board.GetLstClick());
					//board.RefreshPosition();
					Vector2i releasedPosition = board.GetLstClick();
					Unit* selectedUnit = board.GetCageArray()[selectedPiecePosition.x][selectedPiecePosition.y].unit;

					// ���������, �������� �� ��� ���������� �������� �������� ������
					if (IsMoveValid(selectedPiecePosition, releasedPosition, selectedUnit))
					{
						// �������� ��������� �����
						board.GetCageArray()[selectedPiecePosition.x][selectedPiecePosition.y].unit = nullptr;
						board.GetCageArray()[releasedPosition.x][releasedPosition.y].unit = selectedUnit;
						selectedUnit->SetFigurePosition(releasedPosition);
					}

					// ������� ��������� � ��������� ������
					selectedUnit->SetSelected(false);
					selectedPiecePosition = { 0, 0 };
				}
			}
			break;

		case Event::KeyPressed:
			if (ev.key.code == Keyboard::Escape)
				;
			//alex
		}
	}
}

		
void GameCore::start()
{
	//�� �������
	while (win->isOpen())
	{
		update();

		draw();
	}

}

GameCore::GameCore(int w, int h, const string& board_file) :
	board(board_file)
{
	win = new RenderWindow(VideoMode(w, h), "Chess", sf::Style::Titlebar | sf::Style::Close);

}

GameCore::GameCore(): GameCore(DEFAULT_WIN_W, DEFAULT_WIN_H, "1.png")
{
}

GameCore::~GameCore()
{
	delete win;
}
