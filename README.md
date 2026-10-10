## Сборка и запуск (команды вводить в папке chess-2.0)
# Для c++
cd console/scripts
g++ main.cpp GameManagement.cpp Chessboard.cpp ChessPiece.cpp -o app
app.exe
# Для c#
dotnet publish "lab work on c#" -c Release -o publish
cd publish
ChessApp.exe