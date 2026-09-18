#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <vector>
#include <wchar.h>
#include <iostream>
#include <string>
#include <iterator>

#include "IUpdatable.h"
#include "ChessboardParts.h"

class Chessboard : public IUpdatable
{
public:
	bool isActive;
private:
	std::vector<std::vector<wchar_t>> _chessboard;
	int _edgeLength;

public:
	Chessboard(int edgeLength, bool isActive = true);

	void Update() override;

private: 
	void BuildChessboard(int edgeLength);
	void PrintChessboard();
};

#endif