#pragma once

#include "ConsoleColor.h"

enum class PieceType
{
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING
};

enum class Fraction
{
    WHITE,
    BLACK
};

class Figure
{
public: 
    bool isAlive;

protected:
    WORD _figureColor;
    wchar_t _type;
    Fraction _fraction;
    
public:
    Figure(
        bool isAlive, 
        wchar_t _type,
        Fraction _fraction
    );
    
    wchar_t getType() const;
    Fraction getFraction() const;
    WORD getColor() const;
};