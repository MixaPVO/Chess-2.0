#include "GameManagement.h"

void GameManagement::ClearConsole()
{
	std::wcout << L"\033[2J\033[3J\033[1;1H" << std::flush;
}
