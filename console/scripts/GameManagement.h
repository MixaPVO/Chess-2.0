#ifndef GAME_MANAGEMENT_H
#define GAME_MANAGEMENT_H

#include <iostream>
#include <thread>

#include "IUpdatable.h"
#include "Chessboard.h"

class GameManagement : public IUpdatable
{
private:
    bool _isGameRunning = true;

    //DEBUG
    Chessboard* _chessboard;
public:
    GameManagement();
    ~GameManagement();
    
	void Update() override;
private:
    void ClearConsole();
};

#endif