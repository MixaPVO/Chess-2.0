#pragma once

#include "ConsoleColor.h"

using Color = ColorChanger::Color;
using RGB = ColorChanger::RGB;

class ChessPiece
{
private:
    bool isAlive;

protected:
    const RGB* _figureColor;
    wchar_t _type;
    bool _isWhite;
    int _positionCol;
    int _positionRow;
    
public:
    ChessPiece(
        bool _isWhite,
        wchar_t _type
    );

    virtual ~ChessPiece() = 0;
    
    wchar_t GetType() const;
    bool GetisWhite() const;
    const RGB* GetColor() const;
    void SetPosition(int col, int row);
    void DrawPiece() const;
};