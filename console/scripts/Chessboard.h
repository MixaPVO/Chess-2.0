#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <iterator>

#include "IUpdatable.h"
#include "BoardParts.h"
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
};