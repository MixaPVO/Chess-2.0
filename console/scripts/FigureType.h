#pragma once

#include "Figure.h"

class Pawn : public Figure
{
public:
    Pawn(Fraction fraction) 
    : Figure(true, L'P', fraction)
    {}
};

class Rook : public Figure
{
public:
    Rook(Fraction fraction) 
    : Figure(true, L'R', fraction)
    {}
};