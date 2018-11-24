/* 
Game.cpp
Nelly BARRET - 11507461
Monica LISACEK - 11507550
Hanna PARSHUTO - 11512677
*/

#include <stdio.h>
#include <string>
#include <thread>

#include "Timer.h"
#include "Game.h"

using namespace std;

Game::Game()
{
	new_game = false;
    timer_over = false;
    
    cout << "A game has been created." << endl;    
}

Game::~Game()
{
	new_game = false;
    timer_over = false;
    
    cout << "The game has been deleted." << endl;
}

void Game::game_begin()
{
    //begin choice (classic mode, action mode or quit)
    int choice, rules;

    cout << endl << endl;
    cout << " _____   _____       _   _____   _          __  _____   _       _____   _____ " << endl;
    cout << "|  _  | | ____|     | | | ____| | |        / / | ____| | |     | ____| |  _  |" << endl;
    cout << "| |_| | | |__       | | | |__   | |  __   / /  | |__   | |     | |__   | | | |" << endl;
    cout << "|  _  | |  __|   _  | | |  __|  | | /  | / /   |  __|  | |     |  __|  | | | |" << endl;
    cout << "| |_| | | |___  | |_| | | |___  | |/   |/ /    | |___  | |___  | |___  | |_| |" << endl;
    cout << "|_____/ |_____| |_____/ |_____| |___/|___/     |_____| |_____| |_____| |_____/" << endl;

    cout << endl << endl << endl;
    cout << "    ------------------------------------------------ " << endl;
    cout << "   |    MENU :  Enter your choice and valid         |" << endl;
    cout << "   |                                                |" << endl;
    cout << "   |     1 : New Classic Game                       |" << endl;
    cout << "   |     2 : New Action Game                        |" << endl;
    cout << "   |     3 : Quit                                   |" << endl;
    cout << "    ------------------------------------------------ " << endl << endl;
    
    do
    {
        cout << "Your choice : ";
        cin >> choice;
    }while(choice < 1 || choice > 3);

    if(choice == 3)
    {
        cout << "Goodbye ! " << endl;
        exit(EXIT_SUCCESS);
    }

    do
    {
        cout << "Do you want to read the rules ?" << endl << "Yes : 1, No : 0" << endl;
        cin >> rules;
    }while(rules < 0 || rules > 1);

    if(rules == 1)
    {
        cout << "\t\t\t\t\tHow to play Bejeweled ?" << endl << endl;

        cout << "The goal is to combine at least 3 jewels which have the same color. When they form an alignment they disappear." << endl;
        cout << "If you decide to play with the Action mode, your time is count and it depends on the level you play. Be fast !" << endl;
        cout << "Your score is count in function of the alignement you find. Bigger is the alignment, bigger is the score !" << endl << endl << endl;
    }

    if(choice == 1)
    {
        //classic game (without time)
        new_game = true;

        do
        {
            game_loop(1);

            do
            {
                cout << "Do you want to start a new game ? Yes = 1, No = 0" << endl << "My choice : ";
                cin >> new_game;
            }while(new_game < 0 || new_game > 1);

            if(new_game == 0)
            {
                new_game = false;
            }

        }while(new_game == true);
    }

    else if (choice == 2)
    {
        //action game (with time)

        cout<<"You have 2 minutes ! Be fast !"<<endl;

        //launch the thread for timer
        std::thread t1(Timer:: timer_count,3);

        timer_over = false;
        
        //main process - the game starts
        game_loop(2);

        //interruption of the game because of the fact that time is out
        t1.join();

        terminate();
    }
}

void Game::game_loop(unsigned int mode)
{   
    //first, we create a new grid 8*8 and initialize it with 'A'
    int sizeX = 8;
    int sizeY = 8;
	
    Grid grid(sizeX, sizeY);
    grid.initialize_grid('A');
    grid.set_score(0);

    //won is false while the player hasn't finish its game
    bool won = false;
    
    //coordinates of the swaped jewels
    int xA, yA;
    int xB, yB;
    
    //variables for alignment verification
    int alignR3;
    int alignR4;
    int alignR5;
    int alignC3;
    int alignC4;
    int alignC5; 
    
    grid.fill_grid_jewel();
    grid.alignment_verification(alignR3, alignR4, alignR5, alignC3, alignC4, alignC5);
    
    grid.display_grid();
    
    //while the score is too small or the timer is not finished, the player swaps jewels
    while(won == false)
    {
        //swap two jewels
        do
        {  
            cout << "line 1   = ";
            cin >> xA;
            cout << "column 1 = ";
            cin >> yA;
            cout << "line 2   = ";
            cin >> xB;
            cout << "column 2 = ";
            cin >> yB;
        }while(grid.swap_jewel(xA, yA, xB, yB) != true);   

        grid.display_grid(); 

        //if the score is higher than 100, the game is finished
        if(mode == 1)
        {
            if(grid.get_score() >= 100)
            {
                won = true;
                cout << "Your score is " << grid.get_score() << "points." << endl;
                cout << "Good game !" << endl;
            }
        }

        else if (mode == 2)
        {
            //if the timer is over, game is finished
            if(timer_over == true)
            {
	            won = true;  
	          	cout << "Your score is " << grid.get_score() << "points." << endl;
	            cout << "Good game !" << endl;
	        }
        }
    }

    cin.get();
}