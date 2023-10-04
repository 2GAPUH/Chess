#include "GameCore.h"


void GameCore::draw()
{
	win->clear();

	//Рисуем то что вам нужно
	board.Draw(win);

	

	win->display();
}

void GameCore::update()
{
	Event ev;
	while (win->pollEvent(ev))
	{
		//Добавляем и обрабатываем ивенты
		switch (ev.type)
		{
		case Event::Closed:
			win->close();
			break;

		case Event::MouseButtonPressed:
			if (ev.mouseButton.button == Mouse::Left)
			{
				board.CheckClick(Mouse::getPosition(*win));
			}
			break;
		}
	}

}

void GameCore::start()
{
	//Не трогать
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

