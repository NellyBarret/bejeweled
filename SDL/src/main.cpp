/* 
main.cpp
Nelly BARRET - 11507461
Monica LISACEK - 11507550
Hanna PARSHUTO - 11512677
*/

#include <iostream>
#include <stdlib.h>
#include <cassert>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "Grid.h"
#include "Game.h"
#include "GameWindow.h"

using namespace std;


int main()
{
	Game g;
	g.game_loop();

	//using this code if you want to execute regression fonction
	//Grid g;
	//g.grid_regression();
	
	return 0;
}