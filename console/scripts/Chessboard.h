#pragma once
#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <stdexcept>
#include <vector>
#include "ChessPiece.h"

class Chessboard
{
private:
    struct Parts
    {
        static inline constexpr wchar_t HORIZONTAL_BORDER = L'\u2550';
        static inline constexpr wchar_t VERTICAL_BORDER = L'\u2551';
        static inline constexpr wchar_t TOP_LEFT_CORNER = L'\u2554';
        static inline constexpr wchar_t TOP_RIGHT_CORNER = L'\u2557';
        static inline constexpr wchar_t BOTTOM_LEFT_CORNER = L'\u255A';
        static inline constexpr wchar_t BOTTOM_RIGHT_CORNER = L'\u255D';
    };

    int _edgeLength;

    int _maxChessPiecesValue;
    int _whiteChessPiecesValue = 0;
    int _blackChessPiecesValue = 0;

    std::vector<std::weak_ptr<ChessPiece>> _whiteChessPieces;
    std::vector<std::weak_ptr<ChessPiece>> _blackChessPieces;
    std::vector<wchar_t> _wcharChessboard;

public:
    Chessboard(int edgeLength, int maxChessPiecesValue);
    ~Chessboard();
    std::vector<std::weak_ptr<ChessPiece>> GetWhiteChessPieces();
    std::vector<std::weak_ptr<ChessPiece>> GetBlackChessPieces();
    void AddChessPiece(std::weak_ptr<ChessPiece> ChessPiece);
    void RemoveChessPiece(std::weak_ptr<ChessPiece> removingChessPiece);
    void Update();
private:
    void PrintChessboard() const;
};