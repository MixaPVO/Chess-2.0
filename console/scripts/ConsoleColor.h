#pragma once

#include <iostream>

struct RGB
{
    int r;
    int g;
    int b;
};

class ColorChanger
{
public:
    static void SetTextColor(const RGB& Color);
    static void SetBGColor(const RGB& Color);

    static void ResetConsoleColor();

    struct Color
    {
        static inline constexpr RGB BLACK = {0, 0, 0};
        static inline constexpr RGB BLUE = {0, 0, 255};
        static inline constexpr RGB GREEN = {0, 255, 0};
        static inline constexpr RGB CYAN = {0, 255, 255};
        static inline constexpr RGB RED = {255, 0, 0};
        static inline constexpr RGB MAGENTA = {255, 0, 255};
        static inline constexpr RGB YELLOW = {255, 255, 0};
        static inline constexpr RGB WHITE = {255, 255, 255};
        static inline constexpr RGB GRAY = {128, 128, 128};
        static inline constexpr RGB LIGHT_BLUE = {173, 216, 230};
        static inline constexpr RGB LIGHT_GREEN = {144, 238, 144};
        static inline constexpr RGB LIGHT_CYAN = {224, 255, 255};
        static inline constexpr RGB LIGHT_RED = {255, 182, 193};
        static inline constexpr RGB LIGHT_MAGENTA = {255, 182, 255};
        static inline constexpr RGB LIGHT_YELLOW = {255, 255, 182};
    };
};

using Color = ColorChanger::Color;