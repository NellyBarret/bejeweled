/* 
Grid.h
Nelly BARRET - 11507461
Monica LISACEK - 11507550
Hanna PARSHUTO - 11512677
*/

#ifndef _GRID_H
#define _GRID_H

/*!
 * \author      Nelly BARRET, Monica LISACEK, Hanna PARSHUTO
 * \version     1.0
 * \date        26/03/2017
 * \brief       This class manages the grid.
 * \details     Constructors, destructor and specific functions.
 */

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

/*!
 * \class           Grid
 * \brief           This class manages the grid and all the functions which deals with the grid.
 */
class Grid
{
    private:
        char ** table;
        int xdim; //column
        int ydim; //row
        int score;

    public:
        /*!
         * \brief       Default constructor.
         *              Initialize the dimensions of the grid to 0.
         */
        Grid ();

        /*!
         * \brief       Constructor.
         *              Build a new grid dynamically.
         * \param[in]   dimensionX : width of the grid
         * \param[in]   dimensionY : height of the grid
         */
        Grid (int dimensionX, int dimensionY);

        /*!
         *  \brief      Destructor.
         */
        ~Grid ();

        /*!
         * \brief       Procedure.
         *              Initialize the grid with a character.
         * \param[in]   carac : the caracter wich initialize the grid
         */
        void initialize_grid (const char carac);

        /*!
         * \fn          char random_jewel ()
         * \brief       Function.
         *              Create a new random jewel which is a letter between A and G.
         * \param[in]   min : the min value of the range
         * \param[in]   max : the max value of the range
         * \return      The character which corresponds to a jewel.
         */
        char random_jewel (int min, int max);

        /*!
         * \brief       Procedure.
         *              Display the grid to the screen.
         */
        void display_grid ();

        /*!
         * \brief       Procedure.
         *              Fill the grid with the random jewels.
         */
        void fill_grid_jewel ();

        /*!
         * \brief       Procedure.
         *              Check and count the number of alignments in the grid (3 to 8 jewels aligned).
         * \param[in,out]   nbAlignR3 : count the number of 3 aligned jewels in a row
         * \param[in,out]   nbAlignR4 : count the number of 4 aligned jewels in a row
         * \param[in,out]   nbAlignR5 : count the number of 5 aligned jewels in a row
         * \param[in,out]   nbAlignC3 : count the number of 3 aligned jewels in a column
         * \param[in,out]   nbAlignC4 : count the number of 4 aligned jewels in a column
         * \param[in,out]   nbAlignC5 : count the number of 5 aligned jewels in a column
         */
        void alignment_verification (int &nbAlignR3, int &nbAlignR4, int &nbAlignR5, int &nbAlignC3, int &nbAlignC4, int &nbAlignC5);

        /*!
         * \fn          bool swap_jewel ()
         * \brief       Function.
         *              Swap two jewels to make an alignment.
         * \param[in]   x1 : x-axis of the first jewel to swap
         * \param[in]   y1 : y-axis of the first jewel to swap
         * \param[in]   x2 : x-axis of the second jewel to swap
         * \param[in]   y2 : y-axis of the second jewel to swap
         * \return      A boolean which values true if the swap has been made, false else.
         */
        bool swap_jewel (int x1, int y1, int x2, int y2);

        /*!
         * \brief       Procedure.
         *              Count the score in function of the alignments.
         * \param[in,out]   nbAlignR3 : count the number of 3 aligned jewels in a row
         * \param[in,out]   nbAlignR4 : count the number of 4 aligned jewels in a row
         * \param[in,out]   nbAlignR5 : count the number of 5 aligned jewels in a row
         * \param[in,out]   nbAlignC3 : count the number of 3 aligned jewels in a column
         * \param[in,out]   nbAlignC4 : count the number of 4 aligned jewels in a column
         * \param[in,out]   nbAlignC5 : count the number of 5 aligned jewels in a column
         */
        void count_score (int nbAlignR3, int nbAlignR4, int nbAlignR5, int nbAlignC3, int nbAlignC4, int nbAlignC5);

        /*!
         * \brief       Mutator.
         *              Give a value to the score.
         * \param[in]   points : the new value of the score
         */
        void set_score (int points);

        /*!
         * \brief       Accessor.
         *              Take the score of the grid.
         * \return      The score.
         */
        int get_score ();    
};

#endif