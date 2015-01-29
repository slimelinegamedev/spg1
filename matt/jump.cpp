/**************************************************
 *
 * Matthew Page
 * 01/27/2015
 * CSCS2730
 *
 * jump.cpp -   testing jumping for Dankey Kang.
 *
 **************************************************/

//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main( int argc, char* args[] )
{
    //The window we'll be rendering to
    SDL_Window* window = NULL;

    //The surface contained by the window
    SDL_Surface* screenSurface = NULL;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        //Create window
        window = SDL_CreateWindow( "Jump Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN ); 
        if( window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }
        else
        {
            //Get window surface
            screenSurface = SDL_GetWindowSurface( window );

            //Fill the surface white
            SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0x00, 0x00, 0x00 ) );

            //Update the surface
            SDL_UpdateWindowSurface( window );

            //Wait two seconds 
            SDL_Delay( 2000 );
            

            //Main loop flag 
            bool quit = false; 

            //Event handler 
            SDL_Event e;   

            //While application is running 
            while( !quit ) {
         
                //Handle events on queue 
                while( SDL_PollEvent( &e ) != 0 )
                { 
                    //User requests quit 
                    if( e.type == SDL_QUIT ) 
                    { 
                        quit = true;
                    }
                }

                //Apply the image 
                //SDL_BlitSurface( gXOut, NULL, gScreenSurface, NULL ); 
                
                //Update the surface 
                //SDL_UpdateWindowSurface( gWindow );
            } 

        }
    }
   
    /*
    //Main loop flag 
    bool quit = false; 

    //Event handler 
    SDL_Event e;   

    //While application is running 
    while( !quit ) {
 
        //Handle events on queue 
        while( SDL_PollEvent( &e ) != 0 )
        { 
            //User requests quit 
            if( e.type == SDL_QUIT ) 
            { 
                quit = true;
            }
        }

        //Apply the image 
        //SDL_BlitSurface( gXOut, NULL, gScreenSurface, NULL ); 
        
        //Update the surface 
        //SDL_UpdateWindowSurface( gWindow );
 
    } 
    */

    //Destroy window
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}
