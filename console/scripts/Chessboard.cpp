#include "Chessboard.h"

Chessboard::Chessboard(int edgeLength, bool isActive): _edgeLength{edgeLength}, isActive{isActive}
{
	BuildChessboard(edgeLength);
}

void Chessboard::Update()
{
	if (isActive)
	{
		PrintChessboard();
	}
}

void Chessboard::BuildChessboard(int edgeLength)
{
	_chessboard.resize(edgeLength, std::vector<wchar_t>(edgeLength, ' '));
}


void Chessboard::PrintChessboard()
{
	std::wcout << ChessboardParts::TOP_LEFT_CORNER;
	std::wcout << std::wstring(_edgeLength, ChessboardParts::HORIZONTAL_BORDER);
	std::wcout << ChessboardParts::TOP_RIGHT_CORNER << std::endl;

	for (std::size_t i = 0; i < _edgeLength; ++i)
	{
		std::wcout << ChessboardParts::VERTICAL_BORDER;
		std::copy(_chessboard[i].begin(), _chessboard[i].end(), std::ostream_iterator<wchar_t, wchar_t>(std::wcout));
		std::wcout << ChessboardParts::VERTICAL_BORDER << std::endl;
	}

	std::wcout << ChessboardParts::BOTTOM_LEFT_CORNER;
	std::wcout << std::wstring(_edgeLength, ChessboardParts::HORIZONTAL_BORDER);
	std::wcout << ChessboardParts::BOTTOM_RIGHT_CORNER << std::flush;
}