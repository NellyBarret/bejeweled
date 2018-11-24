/* 
Game.cpp
Nelly BARRET - 11507461
Monica LISACEK - 11507550
Hanna PARSHUTO - 11512677
*/

#include <stdio.h>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "SDL_image.h"

#include "GameWindow.h"
#include "Game.h"

using namespace std;


Game::Game()
{
    new_game = false;
    end_game = false;
    timer_over = false;
    cout << "A game has been created." << endl;
    cout << "Here are the dimensions of gamewin:" << endl;
    cout << gamewin.get_xdim_gamewin() << " " << gamewin.get_ydim_gamewin() << endl;
}

Game::~Game()
{
    new_game = false;
    end_game = true;
    timer_over = false;
    cout << "The game has been deleted." << endl;
}

void Game::game_loop()
{ 
    /*------------------------VARIABLES--------------------------*/
    
    //creating the grid
    Grid grid(8,8);
    
    //to check what kind of alignments we have
    int alignR3, alignR4, alignR5, alignC3, alignC4, alignC5;
 
    //the number representing the mode the user chooses when clicking
    int chosen_mode;

    int i, j;
    
    int width = 80; //the width of (the rect around) the jewel
    int margin_x = 520; //margin between the SDL window border and the first jewel, x axis
    int margin_y = 230; //margin between the SDL window border and the first jewel, y axis
    int add_x;
    int add_y;
    
    //coordinates of the click
    //maths cordinates
    int xA = 0; //x=column
    int yA = 0; //y=line
    int xB = 0;
    int yB = 0;
    
    //coordinates of the click (> 0 and < grid size) convert into grid coordinates (> 0 and < 8)
    //WARNING!!!
    //table C++ : x=line,y=column
    int xA_grid = 0;
    int yA_grid = 0;
    int xB_grid = 0;
    int yB_grid = 0;

    //true if the movement is impossible, else false
    bool display_text_imp = false;

    //variables used to format textures
    int texW = 0;
    int texH = 0;
    
    //if true, quit the game
    bool quit = false;

    //true when the user clicks on a game mode (classic or action)
    bool display_jewels = false;

    //true when the user clicks on the question mark at the top left of the window
    bool display_rules = false;

    //to detect if the user clicks several times on the buttons
    bool click1 = false;
    bool click2 = false;

    bool clickLevel = false;
    
    //timer part
    int time_left = -1;

    //to get the time
    Uint32 previous_time = SDL_GetTicks();
    Uint32 next_time;

    //SDL part
    SDL_Event event;
    SDL_Init(SDL_INIT_VIDEO); //initilisation of SDL
    TTF_Init(); //intialisation of TTF (to display text)


    /*------------------------CREATING THE MAIN WINDOW--------------------------*/

    //we use the dimensions of "gamewin" which is the game window in which the grid will be smaller
    SDL_Window * window = SDL_CreateWindow("BEJEWELED", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, gamewin.get_xdim_gamewin(), gamewin.get_ydim_gamewin(), 0);
    
    //we create a renderer, a surface and texture so that the background of the window is the image bg2
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Surface * image = SDL_LoadBMP("../data/bg2.bmp");
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);


    /*------------------------CREATING TEXT PROPERTIES--------------------------*/

    TTF_Font * font_arimo = TTF_OpenFont("../data/Arimo-Bold.ttf", 25); //create the font from the file
    SDL_Color color_black = { 0, 0, 0, 0 }; //black color

    TTF_Font * font_busorama = TTF_OpenFont("../data/busorama.ttf", 30); //create the font from the file
    SDL_Color color_white = { 225, 225, 225, 0 }; //white color
    

    /*------------------------WRITING TEXT AND CONVERTING IT--------------------------*/

    //score
    string text_score; //convert the score (int) to a string
    string concat_text; //concatenate strings
    char const * final_text_score; //to get a char * version of the text so that it can be used by the next function
    
    SDL_Surface * sur_score;
    SDL_Texture * tex_score;
    
    SDL_Rect rect_score; //we create the rectangle containing the text
    

    //impossible movement
    string text_imp_mov = "Your movement is impossible!";
    char const * final_text_imp_mov = text_imp_mov.c_str();

    SDL_Surface * sur_imp_mov;
    SDL_Texture * tex_imp_mov;

    SDL_Rect rect_imp_mov;


    //end
    string text_end = "Good game!";
    char const * final_text_end = text_end.c_str();
    
    SDL_Surface * sur_gg;
    SDL_Texture * tex_gg;

    SDL_Rect rect_gg;


    //timer
    string text_timer;
    char const * final_text_timer;

    SDL_Surface * sur_timer;
    SDL_Texture * tex_timer;
    
    SDL_Rect rect_timer;


    //level 1
    string text_lv1;
    string concat_text_lv1;
    char const * final_text_lv1;

    SDL_Surface * sur_lv1;
    SDL_Texture * tex_lv1;
    
    SDL_Rect rect_lv1;

    //level 2
    string text_lv2;
    string concat_text_lv2;
    char const * final_text_lv2;

    SDL_Surface * sur_lv2;
    SDL_Texture * tex_lv2;
    
    SDL_Rect rect_lv2;

    //level 3
    string text_lv3;
    string concat_text_lv3;
    char const * final_text_lv3;

    SDL_Surface * sur_lv3;
    SDL_Texture * tex_lv3;
    
    SDL_Rect rect_lv3;

    //level 4
    string text_lv4;
    string concat_text_lv4;
    char const * final_text_lv4;

    SDL_Surface * sur_lv4;
    SDL_Texture * tex_lv4;
    
    SDL_Rect rect_lv4;

    
    /*------------------------CREATING RULES--------------------------*/

    string text_rules = "The goal? Combine at least 3 jewels of the same kind that are on the same column or line. When they form an alignment they disappear.";
    char const * final_text_rules = text_rules.c_str();

    //TTF_RenderText_Blended_Wrapped to have a multi-line text
    SDL_Surface * sur_rules = TTF_RenderText_Blended_Wrapped(font_arimo, final_text_rules, color_black, 320); //320 = with of the text
    SDL_Texture * tex_rules = SDL_CreateTextureFromSurface(renderer, sur_rules);
    
    SDL_QueryTexture(tex_rules, NULL, NULL, &texW, &texH); //to format the texture tex
    SDL_Rect rect_rules = { 70, 20, texW, texH };
    SDL_RenderCopy(renderer, tex_rules, NULL, &rect_rules); //adding to the renderer

    string text_rules_null = " ";
    char const * final_text_rules_null = text_rules_null.c_str();

    SDL_Surface * sur_rules_null = TTF_RenderText_Solid(font_arimo, final_text_rules_null, color_black);
    SDL_Texture * tex_rules_null = SDL_CreateTextureFromSurface(renderer, sur_rules_null);
    
    SDL_QueryTexture(tex_rules_null, NULL, NULL, &texW, &texH); //to format the texture tex
    SDL_Rect rect_rules_null = { 70, 20, texW, texH };
    SDL_RenderCopy(renderer, tex_rules_null, NULL, &rect_rules_null); //adding to the renderer

    /*------------------------GAME LOOP--------------------------*/
    
    while (!quit)
    {
        //SDL_PollEvent is a non-blocking function compared to SDL_WaitEvent
        SDL_PollEvent(&event);
        
        /*------------------------EVENTS--------------------------*/
        
        //the margin between the border of the SDL window and the first jewel
        add_x = margin_x;
        add_y = margin_y;

        if(event.type == SDL_QUIT)
        {
            quit = true;
        }

        //a click
        if(event.type == SDL_MOUSEBUTTONDOWN)
        {
            //click on Classic
            if(event.button.x >= 150 && event.button.x <= 400 && event.button.y >= 200 && event.button.y <= 270)
            {
                cout << "Classic mode" << endl;
                chosen_mode = 1;
                display_jewels = true;
                click1 = true;
            }

            //click on Quit
            if(event.button.x >= 150 && event.button.x <= 400 && event.button.y >= 570 && event.button.y <= 710)
            {
                cout << "Quit" << endl;
                quit = true;
            }
            
            //click on ?
            if(event.button.x >= 20 && event.button.x <= 55 && event.button.y >= 20 && event.button.y <= 55)
            {
                display_rules = true;
            }

            //click on Action
            if(event.button.x >= 130 && event.button.x <= 420 && event.button.y >= 350 && event.button.y <= 420)
            {
                cout << "Action mode" << endl;
                chosen_mode = 2;
                click2 = true;
                clickLevel = true;
            }

            //click on an hourglass
            if(clickLevel == true)
            {
                if(event.button.x >= 60 && event.button.x <= 85 && event.button.y >= 430 && event.button.y <= 490)
                {
                    time_left = 30;
                }

                if(event.button.x >= 160 && event.button.x <= 185 && event.button.y >= 430 && event.button.y <= 490)
                {
                    time_left = 60;
                }

                if(event.button.x >= 260 && event.button.x <= 285 && event.button.y >= 430 && event.button.y <= 490)
                {
                    time_left = 90;
                }

                if(event.button.x >= 360 && event.button.x <= 385 && event.button.y >= 430 && event.button.y <= 490)
                {
                    time_left = 120;
                }

                display_jewels = true;
                end_game = false;
            }

            //the user can click on jewels only if it's not the end of the game (score is < 100 or the time isn't over)
            if(end_game == false)
            {
                //click on a jewel
                if(event.button.x >= margin_x && event.button.x <= margin_x+(8*width) && event.button.y >= margin_y && event.button.y <= margin_y+(8*width))
                {
                    //the first jewel : if its coordinates are null, we fill it with the position of the click
                    if(xA == 0 && yA == 0)
                    {
                        xA = int(event.button.x); // x= column
                        yA = int(event.button.y); // y = line

                        //formula : xA_grid = (xA-520)/80  and yA_grid = (yA-230)/80 to transform mouse coordinates to grid coordinates
                        //+1 to have the "user coordinates"
                        xA_grid = (yA-margin_y)/width; //x_grid=y=line
                        yA_grid = (xA-margin_x)/width; //y_grid=x=column

                        cout << "xA_grid = " << xA_grid << endl;
                        cout << "yA_grid = " << yA_grid << endl;
                    }

                    //the second jewel : if its coordinates are null (-> the first jewel is full), we fill it with the position of the click
                    else if(xB == 0 && yB == 0)
                    {
                        xB = int(event.button.x);
                        yB = int(event.button.y);

                        //formula : xB_grid = (xB-520)/80  and yB_grid = (yB-230)/80 to transform mouse coordinates to grid coordinates
                        //+1 to have the "user coordinates"
                        xB_grid = (yB-margin_y)/width;
                        yB_grid = (xB-margin_x)/width;

                        cout << "xB_grid = " << xB_grid << endl;
                        cout << "yB_grid = " << yB_grid << endl;

                        //swap_jewel swaps the 2 jewels if the coordinates are OK, else nothing is done
                        //display_text_imp is true when swap returns false (wrong coordinates or impossible movement)
                        display_text_imp = !grid.swap_jewel(xA_grid, yA_grid, xB_grid, yB_grid);
                        grid.display_grid();

                        //we re-intialize to 0 in order to fill xA and yA after the swap
                        xA = 0;
                        yA = 0;
                        xB = 0;
                        yB = 0;
                    }
                }
            }
        }
 
        if(quit != true)
        {
            //adding the background to the renderer
            SDL_RenderCopy(renderer, texture, NULL, NULL); //the two NULL mean that the image fits the size of the window
            
            //the user clicked on ?
            if(display_rules == true)
            {
                SDL_RenderCopy(renderer, tex_rules, NULL, &rect_rules);
            }

            //the user clicked on the button "clasic game" or "action game" + on an hourglass (for action) -> new game
            if(click1 == true || (click2 == true && clickLevel == true))
            {
                //fill the grid
                grid.fill_grid_jewel();
                grid.alignment_verification(alignR3, alignR4, alignR5, alignC3, alignC4, alignC5);

                //data must be reset before the new game
                if(click1 == true)
                {
                    click1 = false;
                }

                else if(click2 == true)
                {
                    click2 = false;
                }

                end_game = false;

                grid.set_score(0);

                grid.display_grid();
            }

            //click on "Action" -> display hourglasses + times
            if(clickLevel == true)
            {
                //display the hourglasses
                string path_hourglass = "../data/hourglass.bmp";
                const char * path_string_hourglass = path_hourglass.c_str(); //convert string to const char *
                        
                SDL_Surface * surf_hourglass = SDL_LoadBMP(path_string_hourglass);
                SDL_Texture * tex_hourglass = SDL_CreateTextureFromSurface(renderer, surf_hourglass);
                

                /*------------------------LEVEL 1--------------------------*/

                SDL_QueryTexture(tex_hourglass, NULL, NULL, &texW, &texH); //to format the texture tex
                SDL_Rect rect_hourglass = { 60, 450, texW, texH }; //we create the rectangle containing the text   
                SDL_RenderCopy(renderer, tex_hourglass, NULL, &rect_hourglass);

                text_lv1 = "30\"";
                final_text_lv1 = text_lv1.c_str(); //to get a char * version of the text so that it can be used by the next function
                
                sur_lv1 = TTF_RenderText_Solid(font_busorama, final_text_lv1, color_black);
                tex_lv1 = SDL_CreateTextureFromSurface(renderer, sur_lv1);
                 
                SDL_QueryTexture(tex_lv1, NULL, NULL, &texW, &texH); //to format the texture tex
                rect_lv1 = { 100, 470, texW, texH }; //we create the rectangle containing the text
                SDL_RenderCopy(renderer, tex_lv1, NULL, &rect_lv1);


                /*------------------------LEVEL 2--------------------------*/

                SDL_QueryTexture(tex_hourglass, NULL, NULL, &texW, &texH);
                rect_hourglass = { 160, 450, texW, texH };
                SDL_RenderCopy(renderer, tex_hourglass, NULL, &rect_hourglass);

                text_lv2 = "60\"";
                final_text_lv2 = text_lv2.c_str();
                
                sur_lv2 = TTF_RenderText_Solid(font_busorama, final_text_lv2, color_black);
                tex_lv2 = SDL_CreateTextureFromSurface(renderer, sur_lv2);
                 
                SDL_QueryTexture(tex_lv2, NULL, NULL, &texW, &texH); 
                rect_lv2 = { 200, 470, texW, texH }; 
                SDL_RenderCopy(renderer, tex_lv2, NULL, &rect_lv2);


                /*------------------------LEVEL 3--------------------------*/

                SDL_QueryTexture(tex_hourglass, NULL, NULL, &texW, &texH);
                rect_hourglass = { 260, 450, texW, texH }; 
                SDL_RenderCopy(renderer, tex_hourglass, NULL, &rect_hourglass);


                text_lv3 = "90\"";
                final_text_lv3 = text_lv3.c_str();
                
                sur_lv3 = TTF_RenderText_Solid(font_busorama, final_text_lv3, color_black);
                tex_lv3 = SDL_CreateTextureFromSurface(renderer, sur_lv3);
                 
                SDL_QueryTexture(tex_lv3, NULL, NULL, &texW, &texH); 
                rect_lv3 = { 300, 470, texW, texH };
                SDL_RenderCopy(renderer, tex_lv3, NULL, &rect_lv3);


                /*------------------------LEVEL 4--------------------------*/

                SDL_QueryTexture(tex_hourglass, NULL, NULL, &texW, &texH); 
                rect_hourglass = { 360, 450, texW, texH }; 
                SDL_RenderCopy(renderer, tex_hourglass, NULL, &rect_hourglass);


                text_lv4 = "120\"";
                final_text_lv4 = text_lv4.c_str(); 
                
                sur_lv4 = TTF_RenderText_Solid(font_busorama, final_text_lv4, color_black);
                tex_lv4 = SDL_CreateTextureFromSurface(renderer, sur_lv4);
                 
                SDL_QueryTexture(tex_lv4, NULL, NULL, &texW, &texH); //to format the texture tex
                rect_lv4 = { 400, 470, texW, texH }; //we create the rectangle containing the text
                SDL_RenderCopy(renderer, tex_lv4, NULL, &rect_lv4);

                /*------------------------CLEAR TEXTURES AND SURFACES--------------------------*/

                SDL_DestroyTexture(tex_lv1);
                SDL_FreeSurface(sur_lv1);
                SDL_DestroyTexture(tex_lv2);
                SDL_FreeSurface(sur_lv2);
                SDL_DestroyTexture(tex_lv3);
                SDL_FreeSurface(sur_lv3);
                SDL_DestroyTexture(tex_lv4);
                SDL_FreeSurface(sur_lv4);
                SDL_DestroyTexture(tex_hourglass);
                SDL_FreeSurface(surf_hourglass);
            }

            /*------------------------DISPLAY THE GAME--------------------------*/
        
            //the game isn't finished -> display jewels
            if(display_jewels == true)
            {
                //add jewels to the grid
                for(i = 0; i < grid.get_xdim() ; i++)
                {
                    for(j = 0; j < grid.get_ydim() ; j++)
                    {
                        //we create a rectangle
                        SDL_Rect dstrect = {add_x, add_y, width, width}; //line, column, dimensions
                        
                        //we create the surface and texture for the jewel
                        string path = grid.get_jewel(j,i).get_bmp();
                        const char * path_string = path.c_str(); //convert the char * to a string
                        
                        SDL_Surface * surf_jewel = SDL_LoadBMP(path_string);
                        SDL_Texture * text_jewel = SDL_CreateTextureFromSurface(renderer, surf_jewel);
                        SDL_RenderCopy(renderer, text_jewel, NULL, &dstrect);
                        //here there is no second NULL, the jewel will be of the size of the rectangle we created earlier
                        
                        SDL_DestroyTexture(text_jewel);
                        SDL_FreeSurface(surf_jewel);

                        add_y = add_y + width;
                    }

                    add_x = add_x + width;
                    add_y = margin_y;
                }

                //display the score only if it's not the end of the game
                if(end_game == false)
                {
                    text_score = to_string(grid.get_score()); 
                    final_text_score = text_score.c_str(); 

                    sur_score = TTF_RenderText_Solid(font_busorama, final_text_score, color_white);
                    tex_score = SDL_CreateTextureFromSurface(renderer, sur_score);
                     
                    SDL_QueryTexture(tex_score, NULL, NULL, &texW, &texH); 
                    rect_score = { 250, 735, texW, texH }; 
                    SDL_RenderCopy(renderer, tex_score, NULL, &rect_score);

                    SDL_DestroyTexture(tex_score);
                    SDL_FreeSurface(sur_score);
                }
                
                //impossible movement
                //false -> the swap has been not execute
                if(display_text_imp == true)
                {
                    SDL_Surface * sur_imp_mov = TTF_RenderText_Solid(font_arimo, final_text_imp_mov, color_black);
                    SDL_Texture * tex_imp_mov = SDL_CreateTextureFromSurface(renderer, sur_imp_mov);

                    SDL_QueryTexture(tex_imp_mov, NULL, NULL, &texW, &texH);
                    rect_imp_mov = { 800, 200, texW, texH };
                    SDL_RenderCopy(renderer, tex_imp_mov, NULL, &rect_imp_mov);
                    
                    SDL_DestroyTexture(tex_imp_mov);
                    SDL_FreeSurface(sur_imp_mov);
                }

                //click on "action" + on an hourglass -> display timer
                if(clickLevel == true)
                {
                    if(time_left > 0)
                    {
                        /*------------------------DISPLAY TIMER--------------------------*/
        
                        //display the time
                        text_timer = to_string(time_left); 
                        final_text_timer = text_timer.c_str(); 
                        
                        sur_timer = TTF_RenderText_Solid(font_busorama, final_text_timer, color_black);
                        tex_timer = SDL_CreateTextureFromSurface(renderer, sur_timer);
                        
                        SDL_QueryTexture(tex_timer, NULL, NULL, &texW, &texH); 
                        rect_timer = { 140, 820, texW, texH }; 
                        SDL_RenderCopy(renderer, tex_timer, NULL, &rect_timer);
                        
                        //display the hourglass
                        string path_hourglass = "../data/hourglass.bmp";
                        const char * path_string_hourglass = path_hourglass.c_str(); 
                                
                        SDL_Surface * surf_hourglass = SDL_LoadBMP(path_string_hourglass);
                        SDL_Texture * text_hourglass = SDL_CreateTextureFromSurface(renderer, surf_hourglass);
                        
                        SDL_QueryTexture(text_hourglass, NULL, NULL, &texW, &texH); 
                        SDL_Rect rect_hourglass = { 100, 800, texW, texH }; 
                        SDL_RenderCopy(renderer, text_hourglass, NULL, &rect_hourglass); 

                        /*------------------------COUNT TIMER--------------------------*/
                        next_time = SDL_GetTicks();
                        
                        //1000 milliseconds
                        if (next_time-previous_time > 1000 && time_left > 0)
                        {
                            time_left --;
                            previous_time = next_time;
                        }
                    }
                }
                
                //end game
                if((chosen_mode == 1 && grid.get_score() >= 100) || (chosen_mode == 2 && time_left == 0))
                {
                    end_game = true;

                    sur_gg = TTF_RenderText_Solid(font_arimo, final_text_end, color_black);
                    tex_gg = SDL_CreateTextureFromSurface(renderer, sur_gg);

                    SDL_QueryTexture(tex_gg, NULL, NULL, &texW, &texH); 
                    rect_gg = { 800, 200, texW, texH }; 
                    SDL_RenderCopy(renderer, tex_gg, NULL, &rect_gg);

                    SDL_DestroyTexture(tex_gg);
                    SDL_FreeSurface(sur_gg);
                }
            }
            
            SDL_RenderPresent(renderer); //render the image
        }
    }
 
    /*------------------------FREE MEMORY--------------------------*/

    TTF_CloseFont(font_arimo);
    TTF_CloseFont(font_busorama);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(image);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    
    TTF_Quit();

    SDL_Quit();
}

GameWindow Game::get_gamewin() const
{
    return gamewin;
}

Grid Game::get_grid() const
{
    return grid;
}
