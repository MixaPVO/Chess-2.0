#include "ChessPiece.h"

ChessPiece::ChessPiece(wchar_t wcharChessPiece, int chessPieceValue, bool isWhitePiece): 
_wcharChessPiece{wcharChessPiece}, _chessPieceValue{chessPieceValue}, _isWhitePiece{isWhitePiece}
{
    std::wcout << "ChessPiece " << _wcharChessPiece << " was created, _isWhitePeace = " << _isWhitePiece << std::endl;
}

ChessPiece::~ChessPiece()
{
    std::wcout << "ChessPiece " << _wcharChessPiece << " was destroyed, _isWhitePeace = " << _isWhitePiece << std::endl;
}

wchar_t ChessPiece::GetWcharChessPiece() 
{
    return _wcharChessPiece;
}

int ChessPiece::GetChessPieceValue()
{
    return _chessPieceValue;
}

int ChessPiece::GetIndexInChessboard()
{
    return _indexInChessboard;
}

bool ChessPiece::GetIsWhitePiece()
{
    return _isWhitePiece;
}

void ChessPiece::SetIndexInChessboard(int newIndexInChessboard)
{
    _indexInChessboard = newIndexInChessboard;
}