#include "Cell.h"

Cell::Cell(const RGB* cellColor, bool isPieceOnCell) 
    : _cellColor{cellColor}, 
    isPieceOnCell{isPieceOnCell}
{
}


void Cell::DrawCell(int line) const
{
    ColorChanger::SetTextColor(_cellColor);
    if (line == 0)
    {
        std::wcout << CellboardParts::TOP_LEFT_CORNER;
        std::wcout << std::wstring(HORIZONTAL_WIDTH, CellboardParts::HORIZONTAL_BORDER);
        std::wcout << CellboardParts::TOP_RIGHT_CORNER << L' ';
    }
    
    else if (line == LAST_LINE)
    {
        std::wcout << CellboardParts::BOTTOM_LEFT_CORNER;
        std::wcout << std::wstring(HORIZONTAL_WIDTH, CellboardParts::HORIZONTAL_BORDER);
        std::wcout << CellboardParts::BOTTOM_RIGHT_CORNER << L' ';
    }
    else
    {
        std::wcout << CellboardParts::VERTICAL_BORDER;
        
        if (isPieceOnCell) 
        {
            _piece->DrawPiece();
            ColorChanger::SetTextColor(_cellColor);
        }
        else
            std::wcout << L' ' << L' ' << L' ';

        std::wcout << CellboardParts::VERTICAL_BORDER << L' ';
    }
    std::wcout << std::flush;
}

void Cell::SetPieceOnCell(
    ChessPiece* piece
) 
{
    _piece = piece;
    isPieceOnCell = true;
}

const RGB* Cell::GetPieceColor() const
{
    if (isPieceOnCell)
    {
        return _piece->GetColor();
    }
    else
    {
        return nullptr;
    }
}

const RGB* Cell::GetCellColor() const
{
    return _cellColor;
}