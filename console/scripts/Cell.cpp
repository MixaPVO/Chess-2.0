#include "Cell.h"
#include "CellboardParts.h"

Cell::Cell(int positionX, int positionY, bool isFigureOnCell) : _positionX{positionX}, _positionY{positionY}
{
    BuildCell();
}

void Cell::BuildCell()
{
    _cell.resize(3, std::vector<wchar_t>(3, L' '));
}

void Cell::DrawCell(int index)
{
    int width = Cell::_width - 2;
    index %= width;
    if (index == 0) {
        std::wcout << CellboardParts::TOP_LEFT_CORNER;
        for (int i = 0; i < width; ++i) {
            std::wcout << CellboardParts::HORIZONTAL_BORDER;
        }   
	    std::wcout << CellboardParts::TOP_RIGHT_CORNER << ' ';
    }
    else if (0 < index && index < width - 1) {
        std::wcout << CellboardParts::VERTICAL_BORDER;
        for (int i = 0; i < width; ++i) {
            std::wcout << std::wstring(1, 'P');
        }
        std::wcout << CellboardParts::VERTICAL_BORDER  << ' ';
    }
    else if (index == width - 1) {
        std::wcout << CellboardParts::BOTTOM_LEFT_CORNER;
        for (int i = 0; i < width; ++i) {
            std::wcout << CellboardParts::HORIZONTAL_BORDER;
        }
        std::wcout << CellboardParts::BOTTOM_RIGHT_CORNER  << ' ';
    }
}