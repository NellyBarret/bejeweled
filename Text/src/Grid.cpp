/* 
Grid.cpp
Nelly BARRET - 11507461
Monica LISACEK - 11507550
Hanna PARSHUTO - 11512677
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cassert>
#include <time.h>

#include "Grid.h"

using namespace std;


Grid::Grid ()
{
    xdim = 0;
    ydim = 0;
    score = 0;
    
    table = new char*[0];
    table[0] = new char[0];

    cout << "A grid of size " << xdim << "*" << ydim << " has been created." << endl << endl;
}

Grid::Grid (int dimensionX, int dimensionY)
{ 
    int i;
    xdim = dimensionX;
    ydim = dimensionY;
    score = 0;
    
    table = new char*[xdim];
    
    //for each row, we create ydim columns.
    for(i = 0; i < xdim; ++i)
    {
        table[i] = new char[ydim];
    }

    cout << "A grid of size " << xdim << "*" << ydim << " has been created." << endl;
}

Grid::~Grid ()
{
    int i;

    for (i = 0 ; i < xdim ; ++i)
    {
        delete [] table[i];
    }

    delete [] table;
    
    xdim = 0; //column
    ydim = 0; //row
    
    cout << "The grid has been deleted." << endl << endl;
}


void Grid::initialize_grid (const char carac)
{
    for(int i = 0 ; i < xdim ; i++)
    {
        for(int j = 0 ; j < ydim ; j++)
        {
            table[i][j] = carac;
        }
    }
}

char Grid::random_jewel (int min, int max)
{
    int range = max - min + 1;
    
    //we generate a character bewteen 65 ('A') and 71 ('G') (7 jewels)
    //this calculation is like rand()%7+65 but it will be valid even if the size of grid changes
    
    return (rand()%(range) + min);
}

void Grid::display_grid ()
{
    int i, j;

    cout << "  +---+---+---+---+---+---+---+---+" << endl;
    
    for (i = 0 ; i <  xdim ; i++)
    {
        cout << i << " ";

        for (j = 0 ; j < ydim ; j++)
        {
            cout << "| " << table[i][j] << " ";
        }

        cout << "|" << endl;
        cout << "  +---+---+---+---+---+---+---+---+" << endl;
    }

    cout << "    0   1   2   3   4   5   6   7" << endl << endl;
}

void Grid::fill_grid_jewel ()
{
    int i, j;
    
    //in order to have pseudo-random jewels
    srand (time(NULL));

    for (i = 0 ; i < xdim ; i++)
    {
        for (j = 0 ; j < ydim ; j++)
        {
            table[i][j] = random_jewel(65,71);
        }
    }
}

void Grid::alignment_verification (int &nbAlignR3, int &nbAlignR4, int &nbAlignR5, int &nbAlignC3, int &nbAlignC4, int &nbAlignC5)
{
    int i, j;
    int k;
    bool align_OK; //if one alignment is found
    int nb_verif; //from 5 to 3
    int max; //the last verified jewel
    bool last_verif = false; //true if there is no alignment after the swap
    bool random_done = false;
    
    //number of alignments per row 
    nbAlignR3 = 0;
    nbAlignR4 = 0;
    nbAlignR5 = 0;

    //number of alignments per column
    nbAlignC3 = 0;
    nbAlignC4 = 0;
    nbAlignC5 = 0;
    
    //if there is a good combination, we replace the jewels by others.
    //first with 5 then 4 then 3 in order to delete 5 in first (otherwise we delete 3 in an alignment of 5)
       
    while(last_verif == false)
    {
        //by default, this is the last verification
        last_verif = true;    
        
        //the length of alignment
        for(nb_verif = 5 ; nb_verif >= 3 ; nb_verif--)
        {
            max = nb_verif;

            //going through the table vertically
            for(i = 0 ; i < xdim ; i++)
            {
                //going through the table horizontally
                for(j = 0 ; j < ydim ; j++)
                {
                    //the max value must be inferior to the grid length
                    if(j+(max-1) < ydim)
                    {
                        //as soon as a cell is not equal to the first, the alignment will never exist
                        align_OK = true;

                        for(k = 0 ; k < max ; k++)
                        {
                            if(table[i][j] != table[i][j+k])
                            {
                                align_OK = false;
                            }
                        }

                        //we increment the variable for the corresponding length
                        if(align_OK == true)
                        {
                            //we have found an alignement -> this is not the last verification
                            last_verif = false;
                            
                            if(random_done == false)
                            {
                                switch(nb_verif)
                                {
                                    case 3:
                                    {
                                        nbAlignR3++;
                                        break;
                                    }

                                    case 4:
                                    {
                                        nbAlignR4++;
                                        break;
                                    }

                                    case 5:
                                    {
                                        nbAlignR5++;
                                        break;
                                    }
                                }
                            }

                            //for each cell of the alignment, we replace it with an new random jewel
                            for(k = 0 ; k < max ; k++)
                            {
                                table[i][j+k] = random_jewel(65,71);
                            }

                            random_done = true;

                            //if an alignment of 5 is found, no alignment of 4 or 3 is possible -> break the for
                            nb_verif = 2;
                        }
                    }
                }
            }
        }

        //the length of alignment
        for(nb_verif = 5 ; nb_verif >= 3 ; nb_verif--)
        {
            max = nb_verif;

            //going through the table vertically
            for(i = 0 ; i < xdim ; i++)
            {
                //going through the table horizontally
                for(j = 0 ; j < ydim ; j++)
                {
                    //the max value must be inferior the the grid length
                    if(i+(max-1) < xdim)
                    {
                        //as soon as a cell is not equal to the first, the alignment will never exist
                        align_OK = true;

                        for(k = 0 ; k < max ; k++)
                        {
                            if(table[i][j] != table[i+k][j])
                            {
                                align_OK = false;
                            }
                        }

                        //we increment the variable for the corresponding length
                        if(align_OK == true)
                        {
                            //we have found an alignement -> this is not the last verification
                            last_verif = false;
                            
                            if(random_done == false)
                            {
                                switch(nb_verif)
                                {
                                    case 3:
                                    {
                                        nbAlignC3++;
                                        break;
                                    }

                                    case 4:
                                    {
                                        nbAlignC4++;
                                        break;
                                    }

                                    case 5:
                                    {
                                        nbAlignC5++;
                                        break;
                                    }
                                }
                            }

                            //for each cell of the alignment, we repalce it with an new random jewel
                            for(k = 0 ; k < max ; k++)
                            {
                                table[i+k][j] = random_jewel(65,71);
                            }

                            random_done = true;

                            //if an alignment of 5 is found, no alignment of 4 or 3 is possible -> break the for
                            nb_verif = 2;
                        }
                    }
                }
            }
        }
    }

/*
    //3 jewels aligned - row
    for(i = 0 ; i < xdim ; i++)
    {
        for(j = 0 ; j < ydim ; j++)
        {
            if(j+1 < ydim && j+2 < ydim)
            {
                if(table[i][j] == table[i][j+1] && table[i][j] == table[i][j+2])
                {
                    nbAlignR3++;
                    table[i][j] = random_jewel(65,71);
                    table[i][j+1] = random_jewel(65,71);
                    table[i][j+2] = random_jewel(65,71);
                }
            }
        }
    }
*/

/*
    //3 jewels aligned - column
    for(i = 0 ; i < xdim ; i++)
    {
        for(j = 0 ; j < ydim ; j++)
        {
            if(i+1 < xdim && i+2 < xdim)
            {
                if(table[i][j] == table[i+1][j] && table[i][j] == table[i+2][j])
                {
                    nbAlignC3++;
                    table[i][j] = random_jewel(65,71);
                    table[i+1][j] = random_jewel(65,71);
                    table[i+2][j] = random_jewel(65,71);
                }
            }
        }
    }
*/ 
}

bool Grid::swap_jewel (int x1, int y1, int x2, int y2)
{
    int alignR3, alignR4, alignR5, alignC3, alignC4, alignC5;
    
    bool ok = true; //values false when coordinates are false
    char temp; //to save the first cell for the swap, like a buffer variable
    
    //coordinates are in the grid, are different and no too far
    if (x1 < 0 ||  x1 >= xdim)
    {
        cout << "Error while entering x1" << endl;
        ok = false;
    }

    if (x2 < 0 || x2 >= xdim)
    {
        cout << "Error while entering x2" << endl;
        ok = false;
    }

    if (y1 < 0 ||  y1 >= ydim)
    {
        cout << "Error while entering y1" << endl;
        ok = false;
    }

    if (y2 < 0 || y2 >= ydim)
    {
        cout << "Error while entering y2" << endl;
        ok = false;
    }

    if (x1 == x2 && y1 == y2)
    {
        cout << "Coordinates are the same" << endl;
        ok = false;
    }
    
    if (((x2 == x1-1 && y2 == y1) || (x2 == x1 && y2 == y1-1) || (x2 == x1+1 && y2 == y1) || (x2 == x1 && y2 == y1+1)) == false)
    {
        cout << "Coordinates are too far away" << endl;
        ok = false;
    }    
    
    if (ok == true)
    {    
        //make the swap  
        //-1 is required because the table is 0 to 7, not 1 to 8 (player)   
        temp = table[x1][y1]; //save the first cell in order to not loose it between the swap
        table[x1][y1] = table[x2][y2];
        table[x2][y2] = temp;
        
        //verifing that the swap will make an alignment
        alignment_verification(alignR3, alignR4, alignR5, alignC3, alignC4, alignC5);

        //if the swap doesn't make a alignment we re-swap the jewels in order to have the previous grid
        if(alignR3 == 0 && alignR4 == 0 && alignR5 == 0 && alignC3 == 0 && alignC4 == 0 && alignC5 == 0)
        {
            cout << "This movement doesn't form an alignment. Try another !" << endl;

            temp = table[x1][y1];
            table[x1][y1] = table[x2][y2];
            table[x2][y2] = temp;

            ok = false;
        }

        //else, everything is ok and we increase the score in function of the size of the alignment
        else
        {
            cout << "Mouvement OK !" << endl;
            count_score(alignR3, alignR4, alignR5, alignC3, alignC4, alignC5);
        }
    }

    return ok;
}

void Grid::count_score (int nbAlignR3, int nbAlignR4, int nbAlignR5, int nbAlignC3, int nbAlignC4, int nbAlignC5)
{
    score = score + 10*nbAlignR3 + 10*nbAlignC3
                  + 20*nbAlignR4 + 20*nbAlignC4
                  + 30*nbAlignR5 + 30*nbAlignC5;
                
    cout << "Your score is " << score << " points" << endl;
}

void Grid::set_score (int points)
{
    score = points;
}

int Grid::get_score ()
{
    return score;
}