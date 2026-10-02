#include "Chessboard.h"
#include "ConsoleColor.h"
#include "Cell.h"

Chessboard::Chessboard(int boardSize, bool isActive): _chessBoardSize{boardSize}, isActive{isActive}
{
	BuildChessboard();

	_totalWidth = _chessBoardSize * (Cell::WIDTH+1) + 1;
	_totalHeight = _chessBoardSize * Cell::HEIGHT;
}

void Chessboard::Update()
{
	if (isActive)
	{
		PrintChessboard();
	}
}

void Chessboard::BuildChessboard()
{
	_cells.resize(_chessBoardSize*_chessBoardSize);

	for (int i = 0; i < _chessBoardSize; ++i)
	{
	    for (int j = 0; j < _chessBoardSize; ++j)
	    {
	        _cells[i*_chessBoardSize+j] = std::make_unique<Cell>();
	    }
	}
}

void Chessboard::PrintChessboard() const
{
	ColorChanger::SetTextColor(Color::WHITE);
	ColorChanger::SetBGColor(Color::GRAY);

	std::wcout << BP::ChessboardParts::TOP_LEFT_CORNER;
	std::wcout << std::wstring(_totalWidth, BP::ChessboardParts::TOP_BORDER);
	std::wcout << BP::ChessboardParts::TOP_RIGHT_CORNER << std::endl;

	for (std::size_t cellRow = 0; cellRow < _chessBoardSize; ++cellRow)
	{
	    for (std::size_t cellLine = 0; cellLine < Cell::HEIGHT; ++cellLine)
	    {
	        std::wcout << BP::ChessboardParts::LEFT_BORDER;
	        std::wcout << L' ';
		
	        for (std::size_t j = 0; j < _chessBoardSize; ++j)
	        {
	            std::size_t cellIndex = cellRow * _chessBoardSize + j;
			
	            ColorChanger::SetTextColor(
	                _cells[cellIndex]->GetPieceColor()
	            );
			
	            _cells[cellIndex]->DrawCell(cellLine);
	        }
		
	        ColorChanger::SetTextColor(Color::WHITE);
		
	        std::wcout << BP::ChessboardParts::RIGHT_BORDER << std::endl;
	    }
	}

	std::wcout << BP::ChessboardParts::BOTTOM_LEFT_CORNER;
	std::wcout << std::wstring(_totalWidth, BP::ChessboardParts::BOTTOM_BORDER);
	std::wcout << BP::ChessboardParts::BOTTOM_RIGHT_CORNER << std::flush;
	ColorChanger::ResetConsoleColor();
}