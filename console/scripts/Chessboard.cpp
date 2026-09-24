#include "Chessboard.h"
#include "ConsoleColor.h"
#include "FigureType.h"
#include "Cell.h"

Chessboard::Chessboard(int fieldSize, bool isActive): _fieldSize{fieldSize}, isActive{isActive}
{
	BuildChessboard(fieldSize);
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
	// DEBUG
	for (int i = 0; i < fieldSize; ++i)
	{
	    for (int j = 0; j < fieldSize; ++j)
	    {
	        auto cell = std::make_unique<Cell>(i, j);

	        if (i == 1)
	        {
	            cell->SetFigureOnCell(
	                PieceType::PAWN,
	                Fraction::WHITE
	            );
	        } 
			else if (i == 0 && (j == 0 || j == 7))
			{
				cell->SetFigureOnCell(
	                PieceType::ROOK,
	                Fraction::WHITE
	            );
			}
			else if (i == 6)
			{
				cell->SetFigureOnCell(
	                PieceType::PAWN,
	                Fraction::BLACK
	            );
			}
			else if (i == 7 && (j == 0 || j == 7))
			{
				cell->SetFigureOnCell(
	                PieceType::ROOK,
	                Fraction::BLACK
	            );
			}

	        _cells.push_back(std::move(cell));
	    }
	}
}

void Chessboard::PrintChessboard()
{
	int totalWidth = _fieldSize * (Cell::width+1) + 1;
	int totalHeight = _fieldSize * Cell::height;

	ColorChanger::SetConsoleColor(ColorsText::WHITE);

	std::wcout << ChessboardParts::TOP_LEFT_CORNER;
	std::wcout << std::wstring(totalWidth, ChessboardParts::HORIZONTAL_TOP_BORDER);
	std::wcout << ChessboardParts::TOP_RIGHT_CORNER << std::endl;

	for (std::size_t i = 0; i < totalHeight; ++i)
	{
		std::wcout << ChessboardParts::VERTICAL_LEFT_BORDER;

		ColorChanger::SetConsoleColor(ColorsText::WHITE, ColorsBackground::GRAY);
		std::wcout << L' ';

		std::size_t cellRow = i / Cell::height;
		std::size_t cellLine = i % Cell::height;

		for (std::size_t j = 0; j < _fieldSize; ++j)
		{
			std::size_t cellIndex = cellRow * _fieldSize + j;

			_cells[cellIndex]->DrawCell(cellLine);
		}
		ColorChanger::SetConsoleColor(ColorsText::WHITE);

		std::wcout << ChessboardParts::VERTICAL_RIGHT_BORDER << std::endl;
	}

	std::wcout << ChessboardParts::BOTTOM_LEFT_CORNER;
	std::wcout << std::wstring(totalWidth, ChessboardParts::HORIZONTAL_BOTTOM_BORDER);
	std::wcout << ChessboardParts::BOTTOM_RIGHT_CORNER << std::flush;
}