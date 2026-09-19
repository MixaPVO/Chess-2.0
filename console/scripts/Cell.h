#ifndef CELL_H
#define CELL_H

#include <vector>
#include <iostream>

class Cell
{
public:
    bool isFigureOnCell;

private:
    std::vector<std::vector<wchar_t>> _cell;
    int _positionX;
    int _positionY;

public:
    static const int _width = 5;
    static const int _height = 3;

public:
    Cell(int positionX, int positionY, bool isFigureOnCell = false);
    void DrawCell(int index);

private:
    void BuildCell();
};

#endif