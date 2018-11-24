/* 
Timer.cpp
Nelly BARRET - 11507461
Monica LISACEK - 11507550
Hanna PARSHUTO - 11512677
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cassert>
#include <unistd.h> //unsigned int sleep(unsigned int seconds);

#include "Timer.h"

using namespace std;

Timer::Timer()
{
    //remove hour because it seems to be unused
    minute = 0;
    second = 30;

    cout << "The timer of 2 minutes has been created for level 1." << endl;
}

Timer::~Timer()
{
    
    minute = 0;
    second = 0;

    cout << "Time is over" << endl;
    cout << "The timer has been deleted." << endl;
}

void Timer::timer_count(const int level)
{
    int m, s;

    if(level == 1) //2 min
    {
        for(m = 1 ; m >= 0 ; m--)
        {
            for(s = 59 ; s >= 0 ; s--)
            {
                if(s == 0 && m == 0)
                {cout << endl;
				cout << "+-+-+-+-+ +-+-+ +-+-+-+-+" << endl;
				cout << "|T|i|m|e| |i|s| |o|v|e|r|" << endl;
				cout << "+-+-+-+-+ +-+-+ +-+-+-+-+" << endl;exit(EXIT_SUCCESS);
                }

                sleep(1);
            }
        }
    }

    else if(level == 2) // 1 min 30 sec
    {
        for(m = 1 ; m >= 0 ; m--)
        {
            for(s = 29 ; s >= 0 ; s--)
            {
                if(s == 0 && m == 0)
                {
                	cout << endl;
				cout << "+-+-+-+-+ +-+-+ +-+-+-+-+" << endl;
				cout << "|T|i|m|e| |i|s| |o|v|e|r|" << endl;
				cout << "+-+-+-+-+ +-+-+ +-+-+-+-+" << endl;exit(EXIT_SUCCESS);
                }

                sleep(1);
            }
        }
    }

    else if(level == 3) // 1 min
    {
        for(m = 0 ; m >= 0 ; m--)
        {
            for(s = 59 ; s >= 0 ; s--)
            {
                if(s == 0 && m == 0)
                {
                	cout << endl;
				cout << "+-+-+-+-+ +-+-+ +-+-+-+-+" << endl;
				cout << "|T|i|m|e| |i|s| |o|v|e|r|" << endl;
				cout << "+-+-+-+-+ +-+-+ +-+-+-+-+" << endl;exit(EXIT_SUCCESS);
                }

                sleep(1);
            }
        }
    }

    else if(level == 4) // 30 sec
    {
        for(m = 0 ; m >= 0 ; m--)
        {
            for(s = 10 ; s >= 0 ; s--)
            {
                if(s == 0 && m == 0)
                {
                	cout << endl;
				cout << "+-+-+-+-+ +-+-+ +-+-+-+-+" << endl;
				cout << "|T|i|m|e| |i|s| |o|v|e|r|" << endl;
				cout << "+-+-+-+-+ +-+-+ +-+-+-+-+" << endl;exit(EXIT_SUCCESS);
                }

                sleep(1);
            }
        }
    }

    else
    {
        cout << "Error for the level";
    }
}
