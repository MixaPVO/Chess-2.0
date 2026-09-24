#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <iterator>

#include "IUpdatable.h"
#include "ChessboardParts.h"
#include "Cell.h"

class Chessboard : public IUpdatable
{
public:
	bool isActive;
private:
	std::vector<std::unique_ptr<Cell>> _cells;
	int _fieldSize;

public:
	Chessboard(int fieldSize, bool isActive = true);

	void Update() override;

private: 
	void BuildChessboard(int fieldSize);
	void PrintChessboard();
};