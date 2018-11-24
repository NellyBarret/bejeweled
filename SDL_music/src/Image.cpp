/* 
Image.cpp
Nelly BARRET - 11507461
Monica LISACEK - 11507550
Hanna PARSHUTO - 11512677
*/

#include <cassert>
#include <time.h>
#include <stdlib.h>
#include <iostream>

#include "Image.h"

using namespace std;

Image::Image ()
{
    surface = NULL;
}

Image::~Image ()
{
    surface = NULL;
}


SDL_Surface* Image::get_surface() const
{
	return surface;
}


void Image::set_surface(SDL_Surface* newsurface)
{
	surface = newsurface;
	SDL_FreeSurface(newsurface);
}