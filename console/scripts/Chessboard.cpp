#include "Chessboard.h"

Chessboard::Chessboard(int edgeLength, int maxChessPiecesValue) : _edgeLength{edgeLength}, _maxChessPiecesValue{maxChessPiecesValue}
{
    _wcharChessboard.resize(_edgeLength * _edgeLength, ' ');
}

Chessboard::~Chessboard()
{
    std::wcout << L"Chessboard was destroyed" << std::endl;
}

std::vector<ChessPiece*>& Chessboard::GetWhiteChessPieces()
{
    return _whiteChessPieces;
}

std::vector<ChessPiece*>& Chessboard::GetBlackChessPieces()
{
    return _blackChessPieces;
}

void Chessboard::AddChessPiece(ChessPiece* newChessPiece)
{
    bool isWhitePiece = newChessPiece->GetIsWhitePiece();
    int chessPieceValue = newChessPiece->GetChessPieceValue();
    int& curChessPiecesValue = isWhitePiece? _whiteChessPiecesValue : _blackChessPiecesValue;

    if (curChessPiecesValue + chessPieceValue > _maxChessPiecesValue)
    {
        std::wcout<< newChessPiece->GetWcharChessPiece() << " piece is superfluous" << std::endl;
        return;
    }

    curChessPiecesValue += chessPieceValue;

    int pieceIndex;
    std::vector<ChessPiece*>& curChessPieces = isWhitePiece ? _whiteChessPieces : _blackChessPieces;
    int curChessPieceVectorSize = curChessPieces.size();

    if (isWhitePiece)
        pieceIndex = curChessPieceVectorSize == 0 ? 0 : curChessPieces[curChessPieceVectorSize - 1]->GetIndexInChessboard() + 1;
    else
        pieceIndex = curChessPieceVectorSize == 0 ? _wcharChessboard.size() - 1 : curChessPieces[curChessPieceVectorSize - 1]->GetIndexInChessboard() - 1;

    if (pieceIndex < 0 || pieceIndex > _wcharChessboard.size() || _wcharChessboard[pieceIndex] != ' ')
    {
        std::wcout << L"Too many pieces on the chessboard" << std::endl;
        return;
    }

    newChessPiece->SetIndexInChessboard(pieceIndex);
    curChessPieces.push_back(newChessPiece);
    _wcharChessboard[pieceIndex] = newChessPiece->GetWcharChessPiece();
}

void Chessboard::RemoveChessPiece(ChessPiece* removingChessPiece)
{
    bool isWhitePiece = removingChessPiece->GetIsWhitePiece();
    std::vector<ChessPiece*>& curChessPieces = isWhitePiece ? _whiteChessPieces : _blackChessPieces;
    // std::vector<ChessPiece*>::iterator necessaryPiece = std::find(curChessPieces.begin(), curChessPieces.end(), &removingChessPiece);
    std::vector<ChessPiece*>::iterator newEnd = std::remove(curChessPieces.begin(), curChessPieces.end(), removingChessPiece);
    if (newEnd == curChessPieces.end())
    {
        std::wcout << "That piece don't exist on the chessboard" << std::endl;
        return;
    }
    curChessPieces.erase(newEnd, curChessPieces.end());
}

void Chessboard::Update()
{
    PrintChessboard();
}

void Chessboard::PrintChessboard() const
{
	std::wcout << Parts::TOP_LEFT_CORNER;
	std::wcout << std::wstring(_edgeLength, Parts::HORIZONTAL_BORDER);
	std::wcout << Parts::TOP_RIGHT_CORNER << std::endl;

	for (std::size_t i = 0; i < _edgeLength; ++i)
	{
		std::wcout << Parts::VERTICAL_BORDER;
		std::copy(_wcharChessboard.begin() + i * _edgeLength, _wcharChessboard.begin() + (i + 1) * _edgeLength, std::ostream_iterator<wchar_t, wchar_t>(std::wcout));
		std::wcout << Parts::VERTICAL_BORDER << std::endl;
	}

	std::wcout << Parts::BOTTOM_LEFT_CORNER;
	std::wcout << std::wstring(_edgeLength, Parts::HORIZONTAL_BORDER);
	std::wcout << Parts::BOTTOM_RIGHT_CORNER << std::flush;
}