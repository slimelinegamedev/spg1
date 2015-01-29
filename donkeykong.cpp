/**************************************************
 *
 * Super Mega Awesome Donkey Kong
 * a.k.a. Dankey Kang
 * a.k.a. Dunkey Kung
 * a.k.a. Kunkey Dung
 *
 * Developed by:    Zack Golden
 *                  Matthew Page
 *                  Dan Shadeck
 *
 *************************************************/
//Using SDL, SDL_image, standard IO, math, and strings
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Loads individual image as texture
SDL_Texture* loadTexture( std::string path );

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Nothing to load
	return success;
}

void close()
{
	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}

int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{	
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
				}

				//Clear screen
				SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0x00 );
				SDL_RenderClear( gRenderer );

				//Donkey Kong Floors and Ladders
				SDL_Rect Floor1 = { 20, 440, 600, 10 };
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );		
				SDL_RenderFillRect( gRenderer, &Floor1 );

				SDL_Rect Ladder1_2 = { 560, 340, 20, 100 };
				SDL_SetRenderDrawColor( gRenderer, 0x55, 0xDD, 0xFF, 0xFF );		
				SDL_RenderFillRect( gRenderer, &Ladder1_2 );

				SDL_Rect Floor2 = { 20, 340, 600, 10 };
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );		
				SDL_RenderFillRect( gRenderer, &Floor2 );

				SDL_Rect Ladder2_3 = { 60, 240, 20, 100 };
				SDL_SetRenderDrawColor( gRenderer, 0x55, 0xDD, 0xFF, 0xFF );		
				SDL_RenderFillRect( gRenderer, &Ladder2_3 );

				SDL_Rect Floor3 = { 20, 240, 600, 10 };
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );		
				SDL_RenderFillRect( gRenderer, &Floor3 );
                
				SDL_Rect Ladder3_4 = { 560, 140, 20, 100 };
				SDL_SetRenderDrawColor( gRenderer, 0x55, 0xDD, 0xFF, 0xFF );		
				SDL_RenderFillRect( gRenderer, &Ladder3_4 );

				SDL_Rect Floor4 = { 20, 140, 600, 10 };
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );		
				SDL_RenderFillRect( gRenderer, &Floor4 );

				SDL_Rect Ladder4_5 = { 240, 60, 20, 80 };
				SDL_SetRenderDrawColor( gRenderer, 0x55, 0xDD, 0xFF, 0xFF );		
				SDL_RenderFillRect( gRenderer, &Ladder4_5 );

				SDL_Rect Floor5 = { 200, 60, 100, 10 };
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );		
				SDL_RenderFillRect( gRenderer, &Floor5 );

                //Mario block
				SDL_Rect Mario = { 310, 405, 20, 35 };
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );		
				SDL_RenderFillRect( gRenderer, &Mario );
               
                //Donkey Kong himself
				SDL_Rect Donkey = { 60, 40, 60, 100 };
				SDL_SetRenderDrawColor( gRenderer, 0xDD, 0x51, 0x00, 0xFF );		
				SDL_RenderFillRect( gRenderer, &Donkey );

                //Princess Peach (win condition)
				SDL_Rect Peach = { 210, 25, 20, 35 };
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xAA, 0xDD, 0xFF );		
				SDL_RenderFillRect( gRenderer, &Peach );

				//Update screen
				SDL_RenderPresent( gRenderer );
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}
