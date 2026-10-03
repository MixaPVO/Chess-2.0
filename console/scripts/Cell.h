#pragma once

#include <vector>
#include <iostream>
#include <memory>

#include "ChessPiece.h"
#include "ConsoleColor.h"

using Color = ColorChanger::Color;
using RGB = ColorChanger::RGB;

class Cell
{
private:
    bool isPieceOnCell;
    ChessPiece* _piece = nullptr;
    const RGB* _cellColor;

public:
    static inline constexpr int WIDTH = 5;  
    static inline constexpr int HEIGHT = 3;

private:
    static inline constexpr int LAST_LINE = HEIGHT - 1;
    static inline constexpr int HORIZONTAL_WIDTH = WIDTH - 2;

public:
    Cell(
        const RGB* _cellColor = &Color::WHITE,
        bool isPieceOnCell = false
    );
    void DrawCell(int index) const;
    void SetPieceOnCell(
        ChessPiece* _piece
    );
    const RGB* GetPieceColor() const;
    const RGB* GetCellColor() const;

private:
    struct CellboardParts 
    {
        static inline constexpr wchar_t HORIZONTAL_BORDER = L'\u2500';
        static inline constexpr wchar_t VERTICAL_BORDER = L'\u2502';
        static inline constexpr wchar_t TOP_LEFT_CORNER = L'\u250C';
        static inline constexpr wchar_t TOP_RIGHT_CORNER = L'\u2510';
        static inline constexpr wchar_t BOTTOM_LEFT_CORNER = L'\u2514';
        static inline constexpr wchar_t BOTTOM_RIGHT_CORNER = L'\u2518';
    };
};