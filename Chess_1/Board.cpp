#include "Board.h"


void Board::FillFigures()
{
	for (int i = 0; i < FIGURES_COUNT; i++)
	{
		switch (Unit::figuresInitCount)
		{
		case 0:
			figuresArray[i] = new Rooks;
			figuresArray[i]->SetFigureType(ROOKS);
			cageArray[0][0].unit = figuresArray[i];
			figuresArray[i]->SetFigurePosition(Vector2i(0, 0));
			break;
		case 1:
			figuresArray[i] = new Rooks;
			figuresArray[i]->SetFigureType(ROOKS);
			cageArray[0][7].unit = figuresArray[i];
				figuresArray[i]->SetFigurePosition(Vector2i(0, 7));
			break;
		case 16:
			figuresArray[i] = new Rooks;
			figuresArray[i]->SetFigureType(ROOKS);
			cageArray[7][7].unit = figuresArray[i];
			figuresArray[i]->SetFigurePosition(Vector2i(7, 7));
			break;
		case 17:
			figuresArray[i] = new Rooks;
			figuresArray[i]->SetFigureType(ROOKS);
			cageArray[7][0].unit = figuresArray[i];
			figuresArray[i]->SetFigurePosition(Vector2i(7, 0));
			break;


		case 2:
			figuresArray[i] = new Knight;
			figuresArray[i]->SetFigureType(KNIGHT);
			cageArray[0][1].unit = figuresArray[i];
			figuresArray[i]->SetFigurePosition(Vector2i(0, 1));
			break;
		case 3:
			figuresArray[i] = new Knight;
			figuresArray[i]->SetFigureType(KNIGHT);
			cageArray[0][6].unit = figuresArray[i];
			figuresArray[i]->SetFigurePosition(Vector2i(0, 6));
			break;
		case 18:
			figuresArray[i] = new Knight;
			figuresArray[i]->SetFigureType(KNIGHT);
			cageArray[7][1].unit = figuresArray[i];
			figuresArray[i]->SetFigurePosition(Vector2i(7, 1));
			break;
		case 19:
			figuresArray[i] = new Knight;
			figuresArray[i]->SetFigureType(KNIGHT);
			cageArray[7][6].unit = figuresArray[i];
			figuresArray[i]->SetFigurePosition(Vector2i(7, 6));
			break;

		case 4:
			figuresArray[i] = new Bishop;
			figuresArray[i]->SetFigureType(BISHOP);
			cageArray[0][2].unit = figuresArray[i];
			figuresArray[i]->SetFigurePosition(Vector2i(0, 2));
			break;
		case 5:
			figuresArray[i] = new Bishop;
			figuresArray[i]->SetFigureType(BISHOP);
			cageArray[0][5].unit = figuresArray[i];
			figuresArray[i]->SetFigurePosition(Vector2i(0, 5));
			break;
		case 20:
			figuresArray[i] = new Bishop;
			figuresArray[i]->SetFigureType(BISHOP);
			cageArray[7][2].unit = figuresArray[i];
			figuresArray[i]->SetFigurePosition(Vector2i(7, 2));
			break;
		case 21:
			figuresArray[i] = new Bishop;
			figuresArray[i]->SetFigureType(BISHOP);
			cageArray[7][5].unit = figuresArray[i];
			figuresArray[i]->SetFigurePosition(Vector2i(7, 5));
			break;

		case 6:
			figuresArray[i] = new Queen;
			figuresArray[i]->SetFigureType(QUEEN);
			cageArray[0][4].unit = figuresArray[i];
			figuresArray[i]->SetFigurePosition(Vector2i(0, 4));
			break;
		case 22:
			figuresArray[i] = new Queen;
			figuresArray[i]->SetFigureType(QUEEN);
			cageArray[7][4].unit = figuresArray[i];
			figuresArray[i]->SetFigurePosition(Vector2i(7, 4));
			break;

		case 7:
			figuresArray[i] = new King;
			figuresArray[i]->SetFigureType(KING);
			cageArray[0][3].unit = figuresArray[i];
			figuresArray[i]->SetFigurePosition(Vector2i(0, 3));
			break;
		case 23:
			figuresArray[i] = new King;
			figuresArray[i]->SetFigureType(KING);
			cageArray[7][3].unit = figuresArray[i];
			figuresArray[i]->SetFigurePosition(Vector2i(7, 3));
			break;

		case 8:
			figuresArray[i] = new Pawn;
			figuresArray[i]->SetFigureType(PAWN);
			cageArray[1][0].unit = figuresArray[i];
			figuresArray[i]->SetFigurePosition(Vector2i(1, 0));
			break;
		case 9:
			figuresArray[i] = new Pawn;
			figuresArray[i]->SetFigureType(PAWN);
			cageArray[1][1].unit = figuresArray[i];
			figuresArray[i]->SetFigurePosition(Vector2i(1, 1));
			break;
		case 10:
			figuresArray[i] = new Pawn;
			figuresArray[i]->SetFigureType(PAWN);
			cageArray[1][2].unit = figuresArray[i];
			figuresArray[i]->SetFigurePosition(Vector2i(1, 2));
			break;
		case 11:
			figuresArray[i] = new Pawn;
			figuresArray[i]->SetFigureType(PAWN);
			cageArray[1][3].unit = figuresArray[i];
			figuresArray[i]->SetFigurePosition(Vector2i(1, 3));
			break;
		case 12:
			figuresArray[i] = new Pawn;
			figuresArray[i]->SetFigureType(PAWN);
			cageArray[1][4].unit = figuresArray[i];
			figuresArray[i]->SetFigurePosition(Vector2i(1, 4));
			break;
		case 13:
			figuresArray[i] = new Pawn;
			figuresArray[i]->SetFigureType(PAWN);
			cageArray[1][5].unit = figuresArray[i];
			figuresArray[i]->SetFigurePosition(Vector2i(1, 5));
			break;
		case 14:
			figuresArray[i] = new Pawn;
			figuresArray[i]->SetFigureType(PAWN);
			cageArray[1][6].unit = figuresArray[i];
			figuresArray[i]->SetFigurePosition(Vector2i(1, 6));
			break;
		case 15:
			figuresArray[i] = new Pawn;
			figuresArray[i]->SetFigureType(PAWN);
			cageArray[1][7].unit = figuresArray[i];
			figuresArray[i]->SetFigurePosition(Vector2i(1, 7));
			break;
		case 24:
			figuresArray[i] = new Pawn;
			figuresArray[i]->SetFigureType(PAWN);
			cageArray[6][0].unit = figuresArray[i];
			figuresArray[i]->SetFigurePosition(Vector2i(6, 0));
			break;
		case 25:
			figuresArray[i] = new Pawn;
			figuresArray[i]->SetFigureType(PAWN);
			cageArray[6][1].unit = figuresArray[i];
			figuresArray[i]->SetFigurePosition(Vector2i(6, 1));
			break;
		case 26:
			figuresArray[i] = new Pawn;
			figuresArray[i]->SetFigureType(PAWN);
			cageArray[6][2].unit = figuresArray[i];
			figuresArray[i]->SetFigurePosition(Vector2i(6, 2));
			break;
		case 27:
			figuresArray[i] = new Pawn;
			figuresArray[i]->SetFigureType(PAWN);
			cageArray[6][3].unit = figuresArray[i];
			figuresArray[i]->SetFigurePosition(Vector2i(6, 3));
			break;
		case 28:
			figuresArray[i] = new Pawn;
			figuresArray[i]->SetFigureType(PAWN);
			cageArray[6][4].unit = figuresArray[i];
			figuresArray[i]->SetFigurePosition(Vector2i(6, 4));
			break;
		case 29:
			figuresArray[i] = new Pawn;
			figuresArray[i]->SetFigureType(PAWN);
			cageArray[6][5].unit = figuresArray[i];
			figuresArray[i]->SetFigurePosition(Vector2i(6, 5));
			break;
		case 30:
			figuresArray[i] = new Pawn;
			figuresArray[i]->SetFigureType(PAWN);
			cageArray[6][6].unit = figuresArray[i];
			figuresArray[i]->SetFigurePosition(Vector2i(6, 6));
			break;
		case 31:
			figuresArray[i] = new Pawn;
			figuresArray[i]->SetFigureType(PAWN);
			cageArray[6][7].unit = figuresArray[i];
			figuresArray[i]->SetFigurePosition(Vector2i(6, 7));
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

	circArray = new SelectCirc * [COLUMN_COUNT];
	for (int i = 0; i < COLUMN_COUNT; i++)
		circArray[i] = new SelectCirc[ROW_COUNT];

	FillFigures();
	InitCircs();

	texture = new Texture;
	sprite = new Sprite;

	texture->loadFromFile(path);
	sprite->setTexture(*texture);
	sprite->setPosition(0, 0);
}

Board::~Board()
{
	for (int i = 0; i < COLUMN_COUNT; i++)
		delete[] cageArray[i];
	delete[] cageArray;

	for (int i = 0; i < COLUMN_COUNT; i++)
		delete[] circArray[i];
	delete[] circArray;

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

	scale = { winSize.x / 1.f / texSize.x, winSize.y / 1.f / texSize.y };
	sprite->setScale(scale);

	win->draw(*sprite);


	for (int i = 0; i < COLUMN_COUNT; i++)
		for (int j = 0; j < ROW_COUNT; j++)
			circArray[i][j].Draw(win, scale);

	for (int i = 0; i < FIGURES_COUNT; i++)
	{
		auto figurePosition = figuresArray[i]->GetFigurePosition(); //Alex
		cageArray[figurePosition.x][figurePosition.y].unit = figuresArray[i]; // Alex
		figuresArray[i]->Draw(win, scale);
	}
}

void Board::CheckClick(Vector2i mousePos)
{
	auto textSize = texture->getSize();

	lastClick.x = (mousePos.x - 23 * scale.x)  / (((textSize.x - 46) * scale.x) / 8);
	lastClick.y = (mousePos.y - 23 * scale.y) / (((textSize.y - 46) * scale.y) / 8);
	if (lastClick.x >= 8)
		lastClick.x = 7;
	if (lastClick.y >= 8)
		lastClick.y = 7;
	printf_s("%d %d\n", lastClick.x, lastClick.y);
}

void Board::InitCircs()
{
	for (int i = 0; i < COLUMN_COUNT; i++)
		for (int j = 0; j < ROW_COUNT; j++)
		{
			circArray[i][j].SetPosition(Vector2i(i, j));
		}
}

void Board::Swap(Vector2i pos1, Vector2i pos2)
{
	cageArray[pos2.x][pos2.y].unit = cageArray[pos1.x][pos1.y].unit;
}

void Board::RefreshFigures()
{
	for (int i = 0; i < COLUMN_COUNT; i++)
		for (int j = 0; j < ROW_COUNT; j++)
		{
			if (cageArray[i][j].unit)
				cageArray[i][j].unit->SetFigurePosition(Vector2i(i, j));
		}
}

Vector2f Board::GetScale()
{
	return scale;
}

Vector2i Board::GetLstClick()
{
	return lastClick;
}

