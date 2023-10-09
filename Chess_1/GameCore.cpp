#include "GameCore.h"

bool GameCore::IsMoveValid(const Vector2i& from, const Vector2i& to, Unit* selectedUnit)
{
	if (selectedUnit && !board.GetCageArray()[to.x][to.y].unit)
	{
		int figureType = selectedUnit->GetFigureType();
		int figureColor = selectedUnit->GetFigureColor(); // Получаем цвет фигуры

		// Проверяем, является ли фигура пешкой
		if (figureType == PAWN)
		{
			int deltaX = to.x - from.x; // Разница по горизонтали

			// Для черных пешек (цвет == BLACK), движение идет вправо (увеличение координаты X)
			// Для белых пешек (цвет == WHITE), движение идет влево (уменьшение координаты X)
			int validDirection = (figureColor == BLACK) ? 1 : -1;

			// Правила движения пешек
			if (deltaX == validDirection) // Вперед на одну клетку
			{
				// Проверка на свободную клетку
				if (!board.GetCageArray()[to.x][to.y].unit)
				{
					return true;
				}
			}
			else if (deltaX == validDirection * 2 && from.x == 6 && figureColor == WHITE) // Для начального хода белой пешки
			{
				// Проверка на двойной ход
				if (!board.GetCageArray()[to.x][to.y].unit && !board.GetCageArray()[to.x - validDirection][to.y].unit)
				{
					return true;
				}
			}
		}

		// Другие правила движения для других фигур

		return false;
	}

	return false;
}




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
				// Alex
				Vector2i clickedPosition = board.GetLstClick();
				Unit* clickedUnit = board.GetCageArray()[clickedPosition.x][clickedPosition.y].unit;
				if (clickedUnit)
				{
					//Снимаем выделение с предыдущей выбранной фигуры
					if (selectedPiecePosition.x != -1)
					{
						board.GetCageArray()[selectedPiecePosition.x][selectedPiecePosition.y].unit->SetSelected(false);
					}

					// Устанавливаем новую выбранную фигуру
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

					// Проверьте, является ли ход допустимым согласно правилам шахмат
					if (IsMoveValid(selectedPiecePosition, releasedPosition, selectedUnit))
					{
						// Обновите состояние доски
						board.GetCageArray()[selectedPiecePosition.x][selectedPiecePosition.y].unit = nullptr;
						board.GetCageArray()[releasedPosition.x][releasedPosition.y].unit = selectedUnit;
						selectedUnit->SetFigurePosition(releasedPosition);
					}

					// Снимаем выделение с выбранной фигуры
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
