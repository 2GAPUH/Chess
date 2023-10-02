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
	win = new RenderWindow(VideoMode(w, h), "Chess");
}

GameCore::GameCore(): GameCore(DEFAULT_WIN_W, DEFAULT_WIN_H, "1.png")
{
}

GameCore::~GameCore()
{
	delete win;
}
