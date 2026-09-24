#include "Cell.h"

Cell::Cell(int positionX, int positionY, bool isFigureOnCell) : _positionX{positionX}, _positionY{positionY}, isFigureOnCell{isFigureOnCell}
{
    BuildCell();
}

void Cell::BuildCell()
{
    _cell.resize(Cell::height, std::vector<wchar_t>(Cell::width, L' '));
}

void Cell::DrawCell(int line)
{
    if (line == 0)
    {
        std::wcout << CellboardParts::TOP_LEFT_CORNER;
        std::wcout << std::wstring(Cell::width - 2, CellboardParts::HORIZONTAL_BORDER);
        std::wcout << CellboardParts::TOP_RIGHT_CORNER << L' ';
    }
    
    else if (line == Cell::height - 1)
    {
        std::wcout << CellboardParts::BOTTOM_LEFT_CORNER;
        std::wcout << std::wstring(Cell::width - 2, CellboardParts::HORIZONTAL_BORDER);
        std::wcout << CellboardParts::BOTTOM_RIGHT_CORNER << L' ';
    }
    else
    {
        std::wcout << CellboardParts::VERTICAL_BORDER;

        if (this->isFigureOnCell) 
        {
            ColorChanger::SetConsoleColor(this->_figure->getColor(), ColorsBackground::GRAY);

            std::wcout << L' ' << this->_figure->getType() << L' ';
            
            ColorChanger::SetConsoleColor(ColorsText::WHITE, ColorsBackground::GRAY);
        }
        else
            std::wcout << L' ' << L' ' << L' ';

        std::wcout << CellboardParts::VERTICAL_BORDER << L' ';
    }
}

void Cell::SetFigureOnCell(
    PieceType type,
    Fraction frac
) 
{
    switch (type) {
        case PieceType::PAWN:
            _figure = std::make_unique<Pawn>(frac);
            break;
        case PieceType::ROOK:
            _figure = std::make_unique<Rook>(frac);
            break;
    }

    this->isFigureOnCell = true;
}