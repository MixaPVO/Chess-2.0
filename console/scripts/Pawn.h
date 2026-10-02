#pragma once

#include "ChessPiece.h"

class Pawn : public ChessPiece
{
public:
    Pawn(bool fraction) 
    : ChessPiece(true, L'P', fraction)
    {}
};