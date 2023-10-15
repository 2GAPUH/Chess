#include "Board.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Rooks.h"
#include "King.h"
#include "Queen.h"
#include "Knight.h"



void Board::FillFigures()
{
	int FigureOrder[ROW_COUNT][COLUMN_COUNT] =
	{
		{ROOK, KNIG, BISH, QUEN, KING, BISH, KNIG, ROOK},
		{PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN},
		{   0,    0,    0,    0,    0,    0,    0,    0},
		{   0,    0,    0,    0,    0,    0,    0,    0},
		{   0,    0,    0,    0,    0,    0,    0,    0},
		{   0,    0,    0,    0,    0,    0,    0,    0},
		{PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN},
		{ROOK, KNIG, BISH, QUEN, KING, BISH, KNIG, ROOK}
	};

	Vector2i pos = { 0, 0 };
	for(int i = 0; i < ROW_COUNT; i++)
		for (int j = 0; j < COLUMN_COUNT; j++)
		{
			pos = { i, j };
			switch (FigureOrder[i][j])
			{
			case ROOK:
				figuresArray[Unit::figuresInitCount] = new Rooks(pos);
				break;

			case KNIG:
				figuresArray[Unit::figuresInitCount] = new Knight(pos);
				break;

			case BISH:
				figuresArray[Unit::figuresInitCount] = new Bishop(pos);
				break;

			case QUEN:
				figuresArray[Unit::figuresInitCount] = new Queen(pos);
				break;

			case KING:
				figuresArray[Unit::figuresInitCount] = new King(pos);
				break;

			case PAWN:
				figuresArray[Unit::figuresInitCount] = new Pawn(pos);
				break;

			case 0:
				continue;
			}
			cageArray[i][j].unit = figuresArray[Unit::figuresInitCount];
		}

	//Убрать setfiguretype
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
		case QUEN:
			delete (Queen*)figuresArray[i];
			break;

		case PAWN:
			delete (Pawn*)figuresArray[i];
			break;

		case KING:
			delete (King*)figuresArray[i];
			break;

		case BISH:
			delete (Bishop*)figuresArray[i];
			break;

		case KNIG:
			delete (Knight*)figuresArray[i];
			break;

		case ROOK:
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
		//auto figurePosition = figuresArray[i]->GetFigurePosition(); //Alex
		//cageArray[figurePosition.x][figurePosition.y].unit = figuresArray[i]; // Alex
		figuresArray[i]->Draw(win, scale);
	}
}

void Board::CheckClick(Vector2i mousePos)
{
	auto textSize = texture->getSize();

	if (lastClick.x != -1)
		prevClick = lastClick;
	lastClick.x = (mousePos.x - BOARD_FRAME * scale.x)  / (((textSize.x - BOARD_FRAME * 2) * scale.x) / 8);
	lastClick.y = (mousePos.y - BOARD_FRAME * scale.y) / (((textSize.y - BOARD_FRAME * 2) * scale.y) / 8);
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

void Board::FigureSelect()
{
	if (cageArray[lastClick.x][lastClick.y].unit && select !=1)
		select = 1;
	else
		select = 0;
}

void Board::SwapFigures(Vector2i pos1, Vector2i pos2)
{
	cageArray[pos2.x][pos2.y].unit = cageArray[pos1.x][pos1.y].unit;
	cageArray[pos1.x][pos1.y].unit = NULL;
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

Cage** Board::GetCageArray() {
	return cageArray;
}
Vector2f Board::GetScale()
{
	return scale;
}

Vector2i Board::GetLstClick()
{
	return lastClick;
}

Vector2i Board::GetPrevClick()
{
	return prevClick;
}



void Board::ClearCircArray()
{
	for (int i = 0; i < COLUMN_COUNT; i++)
		for (int j = 0; j < ROW_COUNT; j++)
			circArray[i][j].SetState(0);
}

void Board::SetColor(bool i)
{
	color = i;
}

bool Board::GetColor()
{
	return color;
}

SelectCirc** Board::GetCircArray()
{
	return circArray;
}

bool Board::CheckEndGame()
{
	for (int i = 0; i < FIGURES_COUNT;i++)
		if (figuresArray[i]->GetFigureType() == KING && figuresArray[i]->GetFigurePosition().x < 0)
			return 1;
	return 0;

}


