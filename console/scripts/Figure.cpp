#include "Figure.h"

Figure::Figure(
    bool isAlive, 
    wchar_t type, 
    Fraction fraction
) : isAlive{isAlive}
{
    this->_type = type;
    this->_fraction = fraction;
    
    if (fraction == Fraction::WHITE) 
    {
        this->_figureColor = ColorsText::WHITE;
    }
    else 
    {
        this->_figureColor = ColorsText::BLACK;
    }
}

wchar_t Figure::getType() const
{
    return _type;
}

Fraction Figure::getFraction() const
{
    return _fraction;
}

WORD Figure::getColor() const
{
    return _figureColor;
}

