#include "Cell.h"

Cell::CellboardParts::~CellboardParts() = default;

Cell::Cell() = default;

Cell::Cell(const RGB* cellColor) : _cellColor{cellColor}
{
}

Cell::Cell(const RGB* cellColor, ChessPiece* piece) : Cell(cellColor) 
{
    SetPieceOnCell(piece);
}


void Cell::DrawCell(int line) const
{
    Console::SetTextColor(_cellColor);
    if (line == 0)
    {
        std::wcout << CellboardParts::TOP_LEFT_CORNER;
        std::wcout << std::wstring(_HORIZONTAL_WIDTH, CellboardParts::HORIZONTAL_BORDER);
        std::wcout << CellboardParts::TOP_RIGHT_CORNER << L' ';
    }
    
    else if (line == _LAST_LINE)
    {
        std::wcout << CellboardParts::BOTTOM_LEFT_CORNER;
        std::wcout << std::wstring(_HORIZONTAL_WIDTH, CellboardParts::HORIZONTAL_BORDER);
        std::wcout << CellboardParts::BOTTOM_RIGHT_CORNER << L' ';
    }
    else
    {
        std::wcout << CellboardParts::VERTICAL_BORDER;
        
        if (_isPieceOnCell) 
        {
            _piece->DrawPiece();
            Console::SetTextColor(_cellColor);
        }
        else
            std::wcout << L' ' << L' ' << L' ';

        std::wcout << CellboardParts::VERTICAL_BORDER << L' ';
    }
}

void Cell::SetPieceOnCell(
    ChessPiece* piece
) 
{
    _piece = piece;
    _isPieceOnCell = true;
}

const RGB* Cell::GetPieceColor() const
{
    if (_isPieceOnCell)
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