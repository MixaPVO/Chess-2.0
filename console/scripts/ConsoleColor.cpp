#include "ConsoleColor.h"

ColorChanger::RGB::RGB(int r, int g, int b) : r{r}, g{g}, b{b}
{
}

ColorChanger::RGB::RGB(const RGB& other) = default;
ColorChanger::RGB::RGB(RGB&& other) = default;

ColorChanger::Color::~Color() = default;

void ColorChanger::SetTextColor(const RGB* color)
{
    if (color != nullptr)
    {
        std::wcout
                << L"\x1b[38;2;"
                << color->r << L';'
                << color->g << L';'
                << color->b << L'm';
    }
}

void ColorChanger::SetBGColor(const RGB* color)
{
    if (color != nullptr)
    {
        std::wcout
            << L"\x1b[48;2;"
            << color->r << L';'
            << color->g << L';'
            << color->b << L'm';
    }
}

void ColorChanger::ResetConsoleColor()
{
    std::wcout << "\x1b[0m";
}