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
#include <SDL2/SDL_image.h>

//map() function declaration
void map(SDL_Renderer * renderer)
{
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
    //SDL_Rect Mario = { 310, 405, 20, 35 };
    //SDL_SetRenderDrawColor( renderer, 0xFF, 0x00, 0x00, 0xFF );
    //SDL_RenderFillRect( renderer, &Mario );

    //Donkey Kong himself
    //SDL_Rect Donkey = { 60, 40, 60, 100 };
    //SDL_SetRenderDrawColor( renderer, 0xDD, 0x51, 0x00, 0xFF );
    //SDL_RenderFillRect( renderer, &Donkey );

    //Princess Peach (win condition)
    SDL_Rect Peach = { 210, 25, 20, 35 };
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xAA, 0xDD, 0xFF );
    SDL_RenderFillRect( renderer, &Peach );

    //Update screen
    SDL_RenderPresent( renderer ); 
}

int main(int argc, char ** argv)
{
    //variables
    bool quit = false;
    SDL_Event event;
    int x = 40;
    int y = 405;

    //initialize SDL
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

    SDL_Window * window = SDL_CreateWindow("Super Mega Awesome Donkey Kong",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Surface * image = IMG_Load ("mario.png");
    SDL_Surface * image2 = IMG_Load ("donkey.png");
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_Texture * texture2 = SDL_CreateTextureFromSurface(renderer, image2);
    SDL_FreeSurface(image);
    SDL_FreeSurface(image2);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    
    map(renderer);

    //main game loop
    while (!quit)
    {
        SDL_WaitEvent(&event);

        switch(event.type)
        {
        case SDL_QUIT:
            quit = true;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_LEFT:  x=x-5; break;
            case SDLK_RIGHT: x=x+5; break;
            //case SDLK_UP:    y=y-2; break;
            //case SDLK_DOWN:  y=y+2; break;
            }
            map(renderer);
            break;
        }
       

        SDL_Rect dstrect = { x, y, 20, 35 };
        SDL_Rect dstrect2 = { 60, 40, 60, 100 };

        //SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, &dstrect);
        SDL_RenderCopy(renderer, texture2, NULL, &dstrect2);
        SDL_RenderPresent(renderer);
                
    }

    //cleanup SDL
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);  
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();


    return 0;
}
