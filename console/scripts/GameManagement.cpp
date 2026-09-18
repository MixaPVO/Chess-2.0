#include "GameManagement.h"
GameManagement::GameManagement()
{
	_chessboard = new Chessboard(8);
}

GameManagement::~GameManagement()
{
	delete _chessboard;
}

void GameManagement::Update()
{
	while (_isGameRunning)
	{
	   ClearConsole();
	   _chessboard->Update();
	   std::this_thread::sleep_for(std::chrono::milliseconds(_FRAME_DELAY_MIL_SEC));

		PickUpInput();
	}
}

void GameManagement::ClearConsole()
{
	std::wcout << "\033[3J\033[1;1H" << std::flush;
}

void GameManagement::PickUpInput()
{
	if (_kbhit())
	{
		if (_getch() == 27)
			_isGameRunning = false;
	}
}