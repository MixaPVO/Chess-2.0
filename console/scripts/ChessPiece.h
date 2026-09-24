#pragma once
#include <iostream>

class ChessPiece
{
private:   
    wchar_t _wcharChessPiece;
    int _chessPieceValue;
    int _indexInChessboard;
    bool _isWhitePiece;
public:
    ChessPiece(wchar_t wcharChessPiece, int chessPieceValue, bool isWhitePiece);
    ~ChessPiece();
    wchar_t GetWcharChessPiece();
    int GetChessPieceValue();
    int GetIndexInChessboard();
    bool GetIsWhitePiece();
    void SetIndexInChessboard(int newIndexInChessboard);
};