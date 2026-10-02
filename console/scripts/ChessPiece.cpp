#include "ChessPiece.h"

ChessPiece::ChessPiece(
    bool isAlive, 
    wchar_t type, 
    bool fraction
) : isAlive{isAlive}
{
    _type = type;
    _fraction = fraction;
    
    if (fraction == 0) 
    {
        _figureColor = Color::WHITE;
    }
    else 
    {
        _figureColor = Color::BLACK;
    }
}

wchar_t ChessPiece::getType() const
{
    return _type;
}

bool ChessPiece::getFraction() const
{
    return _fraction;
}

RGB ChessPiece::getColor() const
{
    return _figureColor;
}

void ChessPiece::setPosition(int x, int y)
{
    _positionX = x;
    _positionY = y;
}

