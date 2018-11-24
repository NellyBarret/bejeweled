/* 
Jewel.cpp
Nelly BARRET - 11507461
Monica LISACEK - 11507550
Hanna PARSHUTO - 11512677
*/

#include <iostream>
#include <stdio.h>
#include <string>

#include <SDL2/SDL.h>
#include "SDL_image.h"

#include "Jewel.h"
#include "Image.h"

using namespace std;


Jewel::Jewel()
{
	rock = Image(); //initialize the image
	type = 'A'; //by default the jewel has type A
	xdim = 0;
	ydim = 0; //by default the jewel doesn't have a position
}

Jewel::~Jewel()
{
	type = '0';
	xdim = 0;
	ydim = 0;
}

int Jewel::get_xdim() const
{
	return xdim;
}
		
int Jewel::get_ydim() const
{
	return ydim;
}

void Jewel::set_xdim(int x) 
{
	xdim = x;
}

void Jewel::set_ydim(int y)
{
	ydim = y;
}	
	
char Jewel::get_type() const
{
	return type;
}

void Jewel::set_type(char lettre)
{
	type = lettre;
}

void Jewel::set_rock(Image im) 
{
	rock = im;
}

Image Jewel::get_rock() const
{
	return rock;
}

string Jewel::get_bmp() 
{	
	string path;
	
	switch (type) //we work out what the letter of the jewel is to get its image
	{
		case 'A':
		{
			path = "../data/Aj.bmp";
			break;
		}

		case 'B':
		{
			path = "../data/Bj.bmp";
			break;
		}

		case 'C':
		{
			path = "../data/Cj.bmp";
			break;
		}

		case 'D':
		{
			path = "../data/Dj.bmp";
			break;
		}

		case 'E':
		{
			path = "../data/Ej.bmp";
			break;
		}

		case 'F':
		{
			path = "../data/Fj.bmp";
			break;
		}

		case 'G':
		{
			path = "../data/Gj.bmp";
			break;
		}

        default:
        {
            // operator doesn't match any case 
            cout << "Error!";
            break;
        }
    }

	return path;
}