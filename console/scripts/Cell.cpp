#include "Cell.h"

Cell::Cell(ChessPiece* chessPiece, bool isPieceOnCell) : isPieceOnCell{isPieceOnCell}, _piece{chessPiece}
{
    BuildCell();
}

void Cell::BuildCell()
{
}

void Cell::DrawCell(int line)
{
    if (line == 0)
    {
        std::wcout << BP::CellboardParts::TOP_LEFT_CORNER;
        std::wcout << std::wstring(Cell::WIDTH - 2, BP::CellboardParts::HORIZONTAL_BORDER);
        std::wcout << BP::CellboardParts::TOP_RIGHT_CORNER << L' ';
    }
    
    else if (line == Cell::HEIGHT - 1)
    {
        std::wcout << BP::CellboardParts::BOTTOM_LEFT_CORNER;
        std::wcout << std::wstring(Cell::WIDTH - 2, BP::CellboardParts::HORIZONTAL_BORDER);
        std::wcout << BP::CellboardParts::BOTTOM_RIGHT_CORNER << L' ';
    }
    else
    {
        std::wcout << BP::CellboardParts::VERTICAL_BORDER;
        
        if (this->isPieceOnCell) 
        {
            std::wcout << L' ' << _piece->getType() << L' ';
        }
        else
            std::wcout << L' ' << L' ' << L' ';

        std::wcout << BP::CellboardParts::VERTICAL_BORDER << L' ';
    }
    std::wcout << std::flush;
}

void Cell::SetPieceOnCell(
    ChessPiece* fig
) 
{
    _piece = fig;
    isPieceOnCell = true;
}

RGB Cell::GetPieceColor() const
{
    if (isPieceOnCell && _piece != nullptr)
    {
        return _piece->getColor();
    }
    else
    {
        return Color::WHITE;
    }
}