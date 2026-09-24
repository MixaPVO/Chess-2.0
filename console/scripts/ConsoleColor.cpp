#include "ConsoleColor.h"

void ColorChanger::SetConsoleColor(
    WORD textColor, 
    WORD backgroundColor)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, textColor | backgroundColor);
}