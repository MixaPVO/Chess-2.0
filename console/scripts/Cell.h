#pragma once

#include <vector>
#include <iostream>
#include <memory>

#include "AllChessPieces.h"
#include "BoardParts.h"
#include "ConsoleColor.h"

class Cell
{
public:
    bool isPieceOnCell;

private:
    std::vector<std::vector<wchar_t>> _cell;
    ChessPiece* _piece;

public:
    static inline constexpr int WIDTH = 5;  
    static inline constexpr int HEIGHT = 3;  

public:
    Cell(
        ChessPiece* _piece = nullptr, 
        bool isPieceOnCell = false
    );
    void DrawCell(int index);
    void SetPieceOnCell(
        ChessPiece* _piece
    );
    RGB GetPieceColor() const;

private:
    void BuildCell();
};