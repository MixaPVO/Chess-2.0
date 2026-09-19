#include "Chessboard.h"
#include "Cell.h"

Chessboard::Chessboard(int fieldSize, bool isActive): _fieldSize{fieldSize}, isActive{isActive}
{
	BuildChessboard(fieldSize);
}

Chessboard::~Chessboard()
{
	for (Cell* cell : _cells)
	{
		delete cell;
	}
}

void Chessboard::Update()
{
	if (isActive)
	{
		PrintChessboard();
	}
}

void Chessboard::BuildChessboard(int fieldSize)
{
	_chessboard.resize(fieldSize, std::vector<wchar_t>(fieldSize, ' '));
	for (int i = 0; i < fieldSize; ++i)
	{
		for (int j = 0; j < fieldSize; ++j)
		{
			Cell* cell = new Cell(i, j);
			_cells.push_back(cell);
		}
	}
}

void Chessboard::PrintChessboard()
{
	int totalWidth = _fieldSize * (Cell::_width+1) + 1;
	int totalHeight = _fieldSize * Cell::_height;

	std::wcout << ChessboardParts::TOP_LEFT_CORNER;
	std::wcout << std::wstring(totalWidth, ChessboardParts::HORIZONTAL_BORDER);
	std::wcout << ChessboardParts::TOP_RIGHT_CORNER << std::endl;

	for (std::size_t i = 0; i < totalHeight; ++i)
	{
		std::wcout << ChessboardParts::VERTICAL_BORDER << L' ';
		for (std::size_t j = 0; j < _fieldSize; ++j)
		{
			_cells[i]->DrawCell(i);
		}
		std::wcout << ChessboardParts::VERTICAL_BORDER << std::endl;
	}

	std::wcout << ChessboardParts::BOTTOM_LEFT_CORNER;
	std::wcout << std::wstring(totalWidth, ChessboardParts::HORIZONTAL_BORDER);
	std::wcout << ChessboardParts::BOTTOM_RIGHT_CORNER << std::flush;
}