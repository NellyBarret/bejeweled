/* 
GameWindow.cpp
Nelly BARRET - 11507461
Monica LISACEK - 11507550
Hanna PARSHUTO - 11512677
*/

#include <stdio.h>
#include <string>

#include <SDL2/SDL.h>
#include "SDL_image.h"

#include "GameWindow.h"


GameWindow::GameWindow()
{
	xdim = 1200;
	ydim = 900;
}

GameWindow::~GameWindow()
{
	xdim = 0;
	ydim = 0;
}

int GameWindow::get_xdim_gamewin() const
{
	return xdim;
}

int GameWindow::get_ydim_gamewin() const
{
	return ydim;
}