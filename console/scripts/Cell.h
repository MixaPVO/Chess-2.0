#pragma once

#include <vector>
#include <iostream>
#include <memory>

#include "FigureType.h"
#include "CellboardParts.h"

class Cell
{
public:
    bool isFigureOnCell;

private:
    std::vector<std::vector<wchar_t>> _cell;
    std::unique_ptr<Figure> _figure;
    int _positionX;
    int _positionY;

public:
    static const int width = 5;
    static const int height = 3;

public:
    Cell(int positionX, int positionY, bool isFigureOnCell = false);
    void DrawCell(int index);
    void SetFigureOnCell(
        PieceType type,
        Fraction frac
    );

private:
    void BuildCell();
};