#include "IO.h"

static SDL_Surface *mScreen;
static Uint32 mColors [COLOR_MAX] = {0x000000ff, 0xff0000ff, 0x00ff00ff, 0x0000ffff,
                                     0x00ffffff, 0xff00ffff, 0xffff00ff, 0xffffffff};

/*
======================================
Init
======================================
*/

IO::IO() noexcept {
    InitGraph();
}

/*
======================================
Clear the screen to black
======================================
*/

void IO::ClearScreen() {
    boxColor(mScreen, 0, 0, mScreen, 0, 0)
}

void IO::boxColor(SDL_Surface *pSurface, int i, int i1, SDL_Surface *pSurface1, int i2, Uint32 i3) {

}

/*
======================================
Draw a rectangle of a given color

Parameters:
>> pX1, pY1: 		Upper left corner of the rectangle
>> pX2, pY2: 		Lower right corner of the rectangle
>> pC				Rectangle color
======================================
*/

void IO::DrawRectangle(int pX1, int pY1, int pX2, int pY2, enum color pC) {
    boxColor(mScreen, pX1, pY1, reinterpret_cast<SDL_Surface *>(pX2), pY2 - 1, mColors[pC]);
}

/*
======================================
Return the screen height
======================================
*/

int IO::GetScreenHeight() {
    return mScreen -> h;
}

/*
======================================
Update screen
======================================
*/

void IO::UpdateScreen() {
    SDL_RendererFlip (mScreen);
}

/*
======================================
Keyboard Input
======================================
*/

int IO::Pollkey() {
    SDL_Event event;
    while (SDL_PollEvent(&event)){
        switch (event.type) {
            case SDL_KEYDOWN:
                return event.key.keysym.sym;
            case SDL_QUIT:
                exit(3);

        }
    }
    return -1;
}

/*
======================================
Keyboard Input
======================================
*/

int IO::GetKey(){
    SDL_Event event;
    while (true) {
        SDL_WaitEvent(&event);
        if ( event.type == SDL_KEYDOWN)
            break;
        if (event.type == SDL_QUIT)
        exit(3);
    };
    return event.key.keysym.sym;
}

/*
======================================
Keyboard Input
======================================
*/

int IO::IsKeyDown(int pKey) {
    int *mKeytable;
    int mNumkeys;
    SDL_PumpEvents();
    mKeytable = (int *) SDL_GetKeyboardState(&mNumkeys);
    return mKeytable[pKey];
}

/*
======================================
SDL Graphical Initialization
======================================
*/

int IO::InitGraph() {
    const SDL_VideoInfo *info;
    Uint8 video_bpp;
    Uint32 videoflags;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf(reinterpret_cast<const char *>(stderr), "Couldn't initialize SDL: %s\n", SDL_GetError());
        return 1;
    }
    atexit(SDL_Quit);

    //Alpha blending doesn't work well at 8-bit color
    info = SDL_GetVideoInfo();
    if ( info -> vfmt -> BitsPerPixel > 8 ) {
        video_bpp = info -> vfmt -> BitsPerPixel;
    }else {
        video_bpp = 16;
    }
    videoflags = SDL_SWSURFACE | SDL_DOUBLEBUF;

    //Set 640x480 video mode
    if ((mScreen = SDL_SetVideoMode(640,480,video_bpp,videoflags))==NULL) {
        printf(reinterpret_cast<const char *>(stderr), "Couldnt set %ix%i video mode: %s\n" , 640, 480, SDL_GetError());
        return 2;
    }
    return 0;
}
