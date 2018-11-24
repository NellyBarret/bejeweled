/* 
GameWindow.h
Nelly BARRET - 11507461
Monica LISACEK - 11507550
Hanna PARSHUTO - 11512677
*/

#ifndef _GAMEWINDOW_H
#define _GAMEWINDOW_H

/*!
 * \author      Nelly BARRET, Monica LISACEK, Hanna PARSHUTO
 * \version     1.0
 * \date        26/03/2017
 * \brief       This class manages the window.
 * \details     
 */

#include <stdio.h>
#include <string>

#include <SDL2/SDL.h>
#include "SDL_image.h"

/*!
 * \class           GameWindow
 * \brief           This class contains the graphic game.
 *                  This class manages the creation of a new window and the graphic game.
 */
class GameWindow
{
	private:
		int xdim; //width of the window
		int ydim; //height of the window
	
	public:
		/*!
		 * \brief       Default constructor.
		 *				Initialize the dimensions of the window to 1200*900
		 */
		GameWindow();

		/*!
		 * \brief       Destructor.
		 */
		~GameWindow();
	
		/*!
		 * \brief       Accessor.
		 *			    Get the width of the grid.
		 * \return      The width of the game window.
         */
		int get_xdim_gamewin() const;
	
		/*!
		 * \brief       Accessor.
		 *			    Get the height of the grid.
		 * \return      The height of the game window.
         */
		int get_ydim_gamewin() const;
};

#endif