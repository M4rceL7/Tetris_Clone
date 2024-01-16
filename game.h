#ifndef TETRIS_CLONE_GAME_H
#define TETRIS_CLONE_GAME_H

#include "board.h"
#include "pieces.h"
#include "IO.h"
#include <time.h>

#define WAIT_TIME 700 //Number of milliseconds that the piece remains before going 1 block down

// ——————————————————————————–
// Game
// ——————————————————————————–

class game {
public:

    game (board *pBoard, Pieces *pPieces, IO *pIO, int pScreenHeight);

    void DrawScene ();
    void CreateNewPiece ();

    int mPosX, mPosY; // Position of the piece that is falling down
    int mPiece, mRotation; // Kind and rotation of the piece that is falling down

private:

    int mScreenHeight; // Screen height in pixels
    int mNextPosX, mNextPosY; // Position of the next piece
    int mNextPiece, mNextRotation; // Kind and rotation of the next piece

    board *mBoard;
    Pieces *mPieces;
    IO *mIO;

    int GetRand (int pA, int pB);
    void InitGame();
    void DrawPiece (int pX, int pY, int pPiece, int pRotation);
    void DrawBoard ();
};

#endif //TETRIS_CLONE_GAME_H
