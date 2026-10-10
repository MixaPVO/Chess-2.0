using System.Runtime.CompilerServices;

Console.OutputEncoding = System.Text.Encoding.UTF8;

[MethodImpl(MethodImplOptions.NoInlining)]
WeakReference<ChessPiece> CreateTemporary()
{
    var temp = new ChessPiece('T', 10, true);
    return new WeakReference<ChessPiece>(temp);
}

[MethodImpl(MethodImplOptions.NoInlining)]
void CheckWeakReference(WeakReference<ChessPiece> weakReference)
{
    Console.WriteLine("A chess piece is exist in the weak pointer: " + weakReference.TryGetTarget(out _));
}

using IssueLog log = new IssueLog("LOG");
IssueLog refLog = log;
refLog.testNumber = 10;
Console.WriteLine("IssueLog: test number — " + log.testNumber);

var pweak = CreateTemporary();
CheckWeakReference(pweak);
GC.Collect();
GC.WaitForPendingFinalizers();
CheckWeakReference(pweak);

List<ChessPiece> wchp = new List<ChessPiece>{new ChessPiece('P', 1, true), new ChessPiece('Q', 8, true), new ChessPiece('E', 3, true)};
List<ChessPiece> bchp = new List<ChessPiece>{new ChessPiece('P', 1, false), new ChessPiece('E', 3, false), new ChessPiece('L', 5, false)};
GameManagement gm = new GameManagement(8, 10);

foreach (var chp in wchp)
{
    gm.MainChessboard.AddChessPiece(chp);
}

foreach (var chp in bchp)  
{
    gm.MainChessboard.AddChessPiece(chp);
}

Console.WriteLine("Press any key to continue.");
Console.ReadKey(true);
gm.Update();

log.Write("Program end");