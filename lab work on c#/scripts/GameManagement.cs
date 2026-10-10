using System.Threading;

class GameManagement
{
    private const int _FRAME_DELAY_MIL_SEC = 1000;
    private bool _isGameRunning = true;
    public Chessboard MainChessboard { get; private set; }
    public GameManagement(int edgeLength, int maxChessPiecesValue)
    {
        MainChessboard = new Chessboard(edgeLength, maxChessPiecesValue);
    }
    public void Update()
    {
        while (_isGameRunning)
        {
            Console.Clear();
            MainChessboard.Update();
            Thread.Sleep(_FRAME_DELAY_MIL_SEC);

            PickUpInput();
        }
        Console.WriteLine();
    }
    private void PickUpInput()
    {
        if (Console.KeyAvailable)
        {
            ConsoleKeyInfo keyInfo = Console.ReadKey(true);
            if (keyInfo.Key == ConsoleKey.Escape)
                _isGameRunning = false;
        }
    }
};