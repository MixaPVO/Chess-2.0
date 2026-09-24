#include <conio.h>
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include "GameManagement.h"

int main()
{
    _setmode(_fileno(stdout), _O_U16TEXT);

    ChessPiece* wchpOne = new ChessPiece('P', 1, true);
    ChessPiece* wchpMany = new ChessPiece[] { ChessPiece('Q', 8, true),  ChessPiece('S', 3, true) };
    ChessPiece* bchpMany[2] = {new ChessPiece('P', 1, false), new ChessPiece('L', 5, false) };
    static ChessPiece bchpLast = ChessPiece('S', 3, false);

    {
        GameManagement gameManagement(8, 10);

        Chessboard& gameChessboard = gameManagement.GetChessboard();
        gameChessboard.AddChessPiece(wchpOne);
        for (std::size_t i = 0; i < 2; ++i)
            gameChessboard.AddChessPiece(wchpMany + i);
        
        for (std::size_t i = 0; i < 2; ++i)
            gameChessboard.AddChessPiece(*(bchpMany + i));
        gameChessboard.AddChessPiece(&bchpLast);
        gameChessboard.RemoveChessPiece(*bchpMany);

        std::wcout<<L"-------TEST------"<<std::endl;
        std::wcout << gameChessboard.GetBlackChessPieces()[0]->GetChessPieceValue() << L" — value of the first black piece" << std::endl; 

        std::wcout << L"Info: press ESC to exit after running the chessboard" << std::endl;
            std::wcout<<"Press any key to continue" << std::endl;
        _getch();
        gameManagement.Update();
    }

    std::wcout<<"Press any key to check and delete remaining objects" << std::endl;
    _getch();

    std::wcout<<L"-------TEST------"<<std::endl;
    std::wcout << wchpOne->GetChessPieceValue() << L" — value of the first white piece" << std::endl; 

    delete wchpOne;
    delete[] wchpMany;

    for (int i = 0; i < 2; ++i)
        delete bchpMany[i];

    return 0;
}