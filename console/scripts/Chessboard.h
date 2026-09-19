#ifndef CHESSBOARD_H
#define CHESSBOARD_H

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
	std::vector<std::vector<wchar_t>> _chessboard;
	std::vector<Cell*> _cells;
	int _fieldSize;

public:
	Chessboard(int fieldSize, bool isActive = true);
	~Chessboard();

	void Update() override;

private: 
	void BuildChessboard(int fieldSize);
	void PrintChessboard();
};

#endif