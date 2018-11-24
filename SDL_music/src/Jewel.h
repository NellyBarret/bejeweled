/* 
Jewel.h
Nelly BARRET - 11507461
Monica LISACEK - 11507550
Hanna PARSHUTO - 11512677
*/

#ifndef _JEWEL_H
#define _JEWEL_H

/*!
 * \author      Nelly BARRET, Monica LISACEK, Hanna PARSHUTO
 * \version     1.0
 * \date        26/03/2017
 * \brief       This class manages jewels.
 * \details     Constructor, mutators and accessors.
 */

#include <stdio.h>
#include <string>

#include <SDL2/SDL.h>
#include "SDL_image.h"

#include "Image.h"

using namespace std;


/*!
 * \class           Jewel
 * \brief           This class contains jewels and their position.
 *                  This class manages the creation of a new jewel and its coordinates.
 */
class Jewel
{
	private:
		Image rock;
		char type;
		int xdim;
		int ydim;
	
	public:
		/*!
		* \brief       Default constructor.
		*/
		Jewel();

		/*!
		* \brief       Destructor.
		*/
		~Jewel();

		/*!
		 * \brief       Accessor.
		 *              Pick the value of x-axis.
		 * \return      The x value.
		 */
		int get_xdim() const;

		/*!
		 * \brief       Accessor.
		 *              Pick the value of y-axis.
		 * \return      The y value.
		 */
		int get_ydim() const;

		/*!
		 * \brief       Mutator.
		 *              Give a value to the x-axis.
		 * \param[in]   x : the value of x-axis
		 */
		void set_xdim(int x);

		/*!
		 * \brief       Mutator.
		 *              Give a value to the y-axis.
		 * \param[in]   y : the value of y-axis
		 */
		void set_ydim(int y);
		
		/*!
	     * \brief       Accessor.
	     *              Pick the type of the jewel.
		 * \return      The type of the jewel.
	     */
		char get_type() const;

		/*!
	     * \brief       Mutator.
	     *              Give a letter to the jewel.
	     * \param[in]   letter : the value of the jewel
	     */
		void set_type(char letter);

		/*!
	     * \brief       Mutator.
	     *              Give an image to the rock.
	     * \param[in]   im : the image
	     */
		void set_rock(Image im);
		
		/*!
		 * \brief       Accessor.
	     *              Pick the value of the rock.
		 * \return      The image.
	     */
		Image get_rock() const;		
		
		/*!
	     * \brief       Accessor.
	     *              get the path of the jewel's image, for example "../data/Aj.bmp".
		 * \return      The path (string).
	     */
		string get_bmp();
};

#endif