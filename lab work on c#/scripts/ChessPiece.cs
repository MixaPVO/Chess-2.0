public class ChessPiece
{
    public int indexInChessboard;
    public char CharChessPiece { get; private set; }
    public int ChessPieceValue { get; private set; }
    public bool IsWhitePiece { get; private set; }
    public ChessPiece(char charChessPiece, int chessPieceValue, bool isWhitePiece)
    {
        CharChessPiece = charChessPiece; 
        ChessPieceValue = chessPieceValue; 
        IsWhitePiece = isWhitePiece;
    }

    public override string ToString() => $"Chess piece: {CharChessPiece}, its value = {ChessPieceValue}, is white = {IsWhitePiece}, its index in chessboard = {indexInChessboard}";
};