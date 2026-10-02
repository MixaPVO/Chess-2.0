#pragma once

#include "ChessPiece.h"

class Rook : public ChessPiece
{
public:
    Rook(bool fraction)
    : ChessPiece(true, L'R', fraction)
    {}
};