/* 
Game.h
Nelly BARRET - 11507461
Monica LISACEK - 11507550
Hanna PARSHUTO - 11512677
*/

#ifndef _GAME_H
#define _GAME_H

/*!
 * \author      Nelly BARRET, Monica LISACEK, Hanna PARSHUTO
 * \version     1.0
 * \date        26/03/2017
 * \brief       This class manage the game.
 * \details     Constructor, destructor and specific functions.
 */

#include <stdio.h>
#include <string>
#include "Grid.h"

/*!
 * \class           Game
 * \brief           This class contains the grid and the loop to play.
 *                  This class manage the creation of a new game, the game and the end of the game.
 */
class Game
{
	private:
		Grid grid;
		bool new_game;
		bool timer_over;

	public:
		/*!
		 * \brief       Default constructor.
		 */
		Game();

		/*!
		 * \brief       Destructor.
		 */
		~Game();

		/*!
		 * \brief       Procedure.
		 * 			    The main menu to start a new game.
		 */
		void game_begin();	

		/*!
		 * \brief       Procedure.
		 *			    The main loop to play a complete game.
		 * \param[in]   mode values 1 if you choose Classic (without time) and 2 if you choose Action (with time).
		 */
		void game_loop(unsigned int mode);
};

#endif