/************************************************************
 *
 * Super Mega Awesome Donkey Kong
 * a.k.a. Dankey Kang
 * a.k.a. Dunkey Kung
 * a.k.a. Kunkey Dung
 *
 * Developers:      Zack Golden
 *                  Matthew Page me@matthewjpage.com
 *                  Dan Shadeck
 *
 ***********************************************************/

#include <SDL2/SDL.h>

int main(int argc, char ** argv)
{
    bool quit = false;
    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window * window = SDL_CreateWindow("Super Mega Awesome Donkey Kong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);

    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);

    while (!quit)
    {
        SDL_WaitEvent(&event);

        switch(event.type)
        {
        case SDL_QUIT:
            quit = true;
            break;
        }

                //Clear screen
                SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0x00, 0x00 );
                SDL_RenderClear( renderer );

                //Donkey Kong Floors and Ladders
                SDL_Rect Floor1 = { 20, 440, 600, 10 };
                SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderFillRect( renderer, &Floor1 );

                SDL_Rect Ladder1_2 = { 560, 340, 20, 100 };
                SDL_SetRenderDrawColor( renderer, 0x55, 0xDD, 0xFF, 0xFF );
                SDL_RenderFillRect( renderer, &Ladder1_2 );

                SDL_Rect Floor2 = { 20, 340, 600, 10 };
                SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderFillRect( renderer, &Floor2 );

                SDL_Rect Ladder2_3 = { 60, 240, 20, 100 };
                SDL_SetRenderDrawColor( renderer, 0x55, 0xDD, 0xFF, 0xFF );
                SDL_RenderFillRect( renderer, &Ladder2_3 );

                SDL_Rect Floor3 = { 20, 240, 600, 10 };
                SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderFillRect( renderer, &Floor3 );

                SDL_Rect Ladder3_4 = { 560, 140, 20, 100 };
                SDL_SetRenderDrawColor( renderer, 0x55, 0xDD, 0xFF, 0xFF );
                SDL_RenderFillRect( renderer, &Ladder3_4 );

                SDL_Rect Floor4 = { 20, 140, 600, 10 };
                SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderFillRect( renderer, &Floor4 );

                SDL_Rect Ladder4_5 = { 240, 60, 20, 80 };
                SDL_SetRenderDrawColor( renderer, 0x55, 0xDD, 0xFF, 0xFF );
                SDL_RenderFillRect( renderer, &Ladder4_5 );

                SDL_Rect Floor5 = { 200, 60, 100, 10 };
                SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderFillRect( renderer, &Floor5 );

                //Mario block
                SDL_Rect Mario = { 310, 405, 20, 35 };
                SDL_SetRenderDrawColor( renderer, 0xFF, 0x00, 0x00, 0xFF );
                SDL_RenderFillRect( renderer, &Mario );

                //Donkey Kong himself
                SDL_Rect Donkey = { 60, 40, 60, 100 };
                SDL_SetRenderDrawColor( renderer, 0xDD, 0x51, 0x00, 0xFF );
                SDL_RenderFillRect( renderer, &Donkey );

                //Princess Peach (win condition)
                SDL_Rect Peach = { 210, 25, 20, 35 };
                SDL_SetRenderDrawColor( renderer, 0xFF, 0xAA, 0xDD, 0xFF );
                SDL_RenderFillRect( renderer, &Peach );

                //Update screen
                SDL_RenderPresent( renderer ); 

    }

    SDL_RenderPresent(renderer);

    SDL_Quit();
    
    SDL_DestroyRenderer(renderer);  
    SDL_DestroyWindow(window);

    return 0;
}