/* 
Image.h
Nelly BARRET - 11507461
Monica LISACEK - 11507550
Hanna PARSHUTO - 11512677
*/

#ifndef _IMAGE_H
#define _IMAGE_H

/*!
 * \author      Nelly BARRET, Monica LISACEK, Hanna PARSHUTO
 * \version     1.0
 * \date        26/03/2017
 * \brief       This class manages the image.
 * \details     Constructors, load from file and specific functions.
 */

#include <stdio.h>
#include <string>

#include <SDL2/SDL.h>
#include "SDL_image.h"


/*!
 * \class           Image
 * \brief           This class contains SDL graphics.
 *                  This class manages the creation of images and their usage.
 */
class Image
{
	private:
	    SDL_Surface * surface;
	    SDL_Texture * texture;
	    bool has_changed;

	public:
		/*!
		 * \brief       Default constructor.
		 */
	    Image ();

	    /*!
		 * \brief       Destructor.
		 */
	    ~Image ();

		/*!
		 * \brief       Accessor.
		 * 			    Get a surface.
		 * \return		A SDL surface
		 */
	    SDL_Surface* get_surface() const;
		
		/*!
		 * \brief       Mutator.
		 * 			    Set the current surface with newsurface.
		 * \param[in]   newsurface : a SDL surface wich will replace the current SDL surface
		 */
	    void set_surface(SDL_Surface* newsurface);
};

#endif