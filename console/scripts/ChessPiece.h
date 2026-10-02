#pragma once

#include "ConsoleColor.h"

class ChessPiece
{
public: 
    bool isAlive;

protected:
    RGB _figureColor;
    wchar_t _type;
    bool _fraction;
    int _positionX;
    int _positionY;
    
public:
    ChessPiece(
        bool isAlive, 
        wchar_t _type,
        bool _fraction
    );
    
    wchar_t getType() const;
    bool getFraction() const;
    RGB getColor() const;
    void setPosition(int x, int y);
};