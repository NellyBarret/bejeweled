/* 
Timer.h
Nelly BARRET - 11507461
Monica LISACEK - 11507550
Hanna PARSHUTO - 11512677
*/

#ifndef _TIMER_H
#define _TIMER_H


#include "Grid.h"

/*!
 * \author      Nelly BARRET, Monica LISACEK, Hanna PARSHUTO
 * \version     1.0
 * \date        26/03/2017
 * \brief       This class manage the timer.
 * \details     Constructor, destructor and specific functions.
 */

#include <iostream>
#include <unistd.h> //unsigned int sleep(unsigned int seconds);

using namespace std;




/*!
 * \class           Timer
 * \brief           This class contains the timer and specific functions.
 *                  This class manage the creation of the timer and its usage.
 */
class Timer
{
	private:
		unsigned int minute;
		unsigned int second;

	public:
		/*!
		* \brief       Default constructor.
		*/
		Timer();

		/*!
		* \brief       Destructor.
		*/
		~Timer();

		/*!
		* \brief       Procedure.
		*			   Count the time in function of the level
		* \param[in]   level values 1 (2 min), 2 (1 min 30) or 3 (1 min).
		*/
		static void timer_count(const int level);
};

#endif
