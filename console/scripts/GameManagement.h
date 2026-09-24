#pragma once

#include <iostream>
#include <thread>
#include <conio.h>

#include "IUpdatable.h"
#include "Chessboard.h"

class GameManagement : public IUpdatable
{
private:
    bool _isGameRunning = true;
    static constexpr int _FRAME_DELAY_MIL_SEC = 100;

    //DEBUG
    Chessboard* _chessboard;
public:
    GameManagement();
    ~GameManagement();
    
	void Update() override;
private:
    void ClearConsole();
    void PickUpInput();
};