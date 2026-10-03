#include "ChessPiece.h"

ChessPiece::ChessPiece(
    bool isWhite, 
    wchar_t type
) : _type{type}, _isWhite{isWhite}, isAlive{true}
{
    if (isWhite == true) 
    {
        _figureColor = &Color::WHITE;
    }
    else 
    {
        _figureColor = &Color::BLACK;
    }
}

ChessPiece::~ChessPiece()
{
}

wchar_t ChessPiece::GetType() const
{
    return _type;
}

bool ChessPiece::GetisWhite() const
{
    return _isWhite;
}

const RGB* ChessPiece::GetColor() const
{
    return _figureColor;
}

void ChessPiece::SetPosition(int col, int row)
{
    _positionCol = col;
    _positionRow = row;
}

void ChessPiece::DrawPiece() const
{
    ColorChanger::SetTextColor(GetColor());
    std::wcout << L' ' << GetType() << L' ';
}

