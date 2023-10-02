#include "Board.h"


void Board::FillFigures(Unit* figuresArray[], Cage** cageArray)
{
	for (int i = 0; i < FIGURES_COUNT; i++)
	{
		switch (Unit::figuresInitCount)
		{
		case 0:
			cageArray[0][0].unit = figuresArray[i];
		case 1:
			cageArray[0][7].unit = figuresArray[i];
		case 16:
		case 17:
			figuresArray[i] = new Rooks;
			figuresArray[i]->SetFigureType(ROOKS);
			break;

		case 2:
		case 3:
		case 18:
		case 19:
			figuresArray[i] = new Knight;
			figuresArray[i]->SetFigureType(KNIGHT);
			break;

		case 4:
		case 5:
		case 20:
		case 21:
			figuresArray[i] = new Bishop;
			figuresArray[i]->SetFigureType(BISHOP);
			break;

		case 6:
		case 22:
			figuresArray[i] = new Queen;
			figuresArray[i]->SetFigureType(QUEEN);
			break;

		case 7:
		case 23:
			figuresArray[i] = new King;
			figuresArray[i]->SetFigureType(KING);
			break;

		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
		case 24:
		case 25:
		case 26:
		case 27:
		case 28:
		case 29:
		case 30:
		case 31:
			figuresArray[i] = new Pawn;
			figuresArray[i]->SetFigureType(PAWN);
			break;
		}
	}
}

//хранит указательна фигуру которая на ней стоит
Board::Board(const std::string& path)
{
	cageArray = new Cage* [COLUMN_COUNT];
	for (int i = 0; i < COLUMN_COUNT; i++)
		cageArray[i] = new Cage[ROW_COUNT];

	FillFigures(figuresArray, cageArray);

	texture = new Texture;
	sprite = new Sprite;

	texture->loadFromFile(path);
	sprite->setTexture(*texture);

}

Board::~Board()
{
	for (int i = 0; i < COLUMN_COUNT; i++)
		delete[] cageArray[i];
	delete[] cageArray;

	for (int i = 0; i < FIGURES_COUNT; i++)
	{
		switch (figuresArray[i]->GetFigureType())
		{
		case QUEEN:
			delete (Queen*)figuresArray[i];
			break;

		case PAWN:
			delete (Pawn*)figuresArray[i];
			break;

		case KING:
			delete (King*)figuresArray[i];
			break;

		case BISHOP:
			delete (Bishop*)figuresArray[i];
			break;

		case KNIGHT:
			delete (Knight*)figuresArray[i];
			break;

		case ROOKS:
			delete (Rooks*)figuresArray[i];
			break;

		}
	}

	delete texture;
	delete sprite;
}

void Board::Draw(RenderWindow* win)
{
	auto winSize = win->getSize();
	auto texSize = texture->getSize();

	sprite->setPosition(int(winSize.x / 2 - texSize.x / 2), int(winSize.y / 2 - texSize.y / 2));
	win->draw(*sprite);
}



