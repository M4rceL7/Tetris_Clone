#ifndef TETRIS_CLONE_IO_H
#define TETRIS_CLONE_IO_H

#include <cstdio>
#include "SDL.h"
#pragma comment (lib, "SDL/lib/SDL.lib")
#pragma comment (lib, "SDL/SDL_GfxPrimitives/SDL_GfxPrimitives_Static.lib")

enum color {BLACK, RED, GREEN, BLUE, CYAN, MAGENTA, YELLOW, WHITE, COLOR_MAX};

class IO {
public:

    void DrawRectangle (int pX1, int pY1, int pX2, int pY2, enum color pC);
    void ClearScreen ();
    int GetScreenHeight ();
    int InitGraph ();
    int Pollkey ();
    int IsKeyDown (int pKey);
    int GetKey ();
    void UpdateScreen ();

    void boxColor(SDL_Surface *pSurface, int i, int i1, SDL_Surface *pSurface1, int i2, Uint32 i3);
};

#endif //TETRIS_CLONE_IO_H
