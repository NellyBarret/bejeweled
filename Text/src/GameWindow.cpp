/* 
GameWindow.cpp
Nelly BARRET - 11507461
Monica LISACEK - 11507550
Hanna PARSHUTO - 11512677
*/

#include <stdio.h>
#include <string>
#include "GameWindow.h"
#include <SDL2/SDL.h>
#include "SDL_image.h"


GameWindow::GameWindow()
{
	xdim = 700;
	ydim = 700;
}

GameWindow::~GameWindow()
{
	xdim=0;
	ydim=0;
}

void GameWindow::draw_window() 
{
		bool quit = false;
	xdim = 700;
	ydim = 700;
    SDL_Event event;
 
    SDL_Init(SDL_INIT_VIDEO);
 
    SDL_Window * window = SDL_CreateWindow("SDL2 Displaying Image",
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, xdim, ydim, 0);
 
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Surface * image = SDL_LoadBMP("../data/bg.bmp");
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);
 
    while (!quit)
    {
        SDL_WaitEvent(&event);
 
        switch (event.type)
        {
            case SDL_QUIT:
                quit = true;
                break;
        }

        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }
 
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(image);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
 
    SDL_Quit();
}
