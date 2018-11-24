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
 * \brief       This class manage the window.
 * \details     
 */

#include <stdio.h>
#include <string>

/*!
 * \class           GameWindow
 * \brief           This class contains the graphic game.
 *                  This class manage the creation of a new window and the graphic game.
 */
class GameWindow
{
	private:
	
	int xdim; //width of the window
	int ydim; //height of the window
	
	public:
	
	GameWindow();
	~GameWindow();
	void draw_window() ;

	
};

#endif