#include "GameCore.h"




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
				if (board.select)
				{
					board.SwapFigures(board.GetPrevClick(), board.GetLstClick());
				}
				board.FigureSelect();
				board.RefreshFigures();
			}
			else if (ev.mouseButton.button == Mouse::Right)
			{
				board.CheckClick(Mouse::getPosition(*win));
				board.select = 0;
			}
			break;
		case Event::MouseButtonReleased:
			if (ev.mouseButton.button == Mouse::Left)
			{
				if (selectedPiecePosition.x != -1)
				{
					Vector2i releasedPosition = board.GetLstClick();
				}
			}
			break;
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
