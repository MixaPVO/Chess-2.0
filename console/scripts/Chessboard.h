#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <iterator>

#include "IUpdatable.h"
#include "Cell.h"

class Chessboard : public IUpdatable
{
public:
	bool isActive;
private:
	std::vector<std::unique_ptr<Cell>> _cells;
	int _chessBoardSize;

protected:
	int _totalWidth;
	int _totalHeight;

public:
	Chessboard(int chessBoardSize, bool isActive = true);

	void Update() override;

private: 
	void BuildChessboard();
	void PrintChessboard() const;

	struct ChessboardParts
    {
        static inline constexpr wchar_t TOP_BORDER = L'\u2580';  
        static inline constexpr wchar_t BOTTOM_BORDER = L'\u2584';  
        static inline constexpr wchar_t RIGHT_BORDER = L'\u2590';  
        static inline constexpr wchar_t LEFT_BORDER = L'\u258C';  
        static inline constexpr wchar_t TOP_LEFT_CORNER = L'\u259B';  
        static inline constexpr wchar_t TOP_RIGHT_CORNER = L'\u259C';  
        static inline constexpr wchar_t BOTTOM_LEFT_CORNER = L'\u2599';  
        static inline constexpr wchar_t BOTTOM_RIGHT_CORNER = L'\u259F'; 
    };
};