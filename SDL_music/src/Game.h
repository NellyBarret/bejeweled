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
 * \brief       This class manages the game.
 * \details     Constructor, destructor and specific functions.
 */

#include <stdio.h>
#include <string>

#include <SDL2/SDL.h>
#include "SDL_image.h"

#include "GameWindow.h"
#include "Grid.h"


/*!
 * \class           Game
 * \brief           This class contains the grid and the loop to play.
 *                  This class manages the creation of a new game, the game and the end of the game.
 */
class Game
{
	private:
		Grid grid;
		GameWindow gamewin; //the game's window
		bool new_game;
		bool end_game;
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
		 *			    The main loop to play a complete game.
		 */
		void game_loop();
		
		/*!
		 * \brief       Accessor.
		 *			    Get the current game window.
		 * \return      the game window.
         */
		GameWindow get_gamewin() const;
		
		/*!
		 * \brief       Accessor.
		 *			    Get the grid.
		 * \return      The grid.
         */
		Grid get_grid()const;
};

#endif/* 
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
 * \brief       This class manages the game.
 * \details     Constructor, destructor and specific functions.
 */

#include <stdio.h>
#include <string>

#include <SDL2/SDL.h>
#include "SDL_image.h"

#include "GameWindow.h"
#include "Grid.h"


/*!
 * \class           Game
 * \brief           This class contains the grid and the loop to play.
 *                  This class manages the creation of a new game, the game and the end of the game.
 */
class Game
{
	private:
		Grid grid;
		GameWindow gamewin; //the game's window
		bool new_game;
		bool end_game;
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
		 *			    The main loop to play a complete game.
		 */
		void game_loop();
		
		/*!
		 * \brief       Accessor.
		 *			    Get the current game window.
		 * \return      the game window.
         */
		GameWindow get_gamewin() const;
		
		/*!
		 * \brief       Accessor.
		 *			    Get the grid.
		 * \return      The grid.
         */
		Grid get_grid()const;
};

#endif