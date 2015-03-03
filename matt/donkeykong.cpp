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

//printlocation() function declaration
void printlocation(int x, int y, int ladderflag, int floorflag)
{
    printf("X: %d  Y: %d\n", x, y);
    printf("ladderflag: %d  arrayflag: %d\n", ladderflag, floorflag);
}

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
    //SDL_Rect Peach = { 210, 25, 20, 35 };
    //SDL_SetRenderDrawColor( renderer, 0xFF, 0xAA, 0xDD, 0xFF );
    //SDL_RenderFillRect( renderer, &Peach );

    //Update screen
    SDL_RenderPresent( renderer ); 
}

int main(int argc, char ** argv)
{
    //variables
    bool quit = false;
    SDL_Event event;
    int x = 40;     //real mario start
    int y = 405;    //real mario start
    //int x = 400;  //start mario testing
    //int y = 105;  //start mario testing
    int ladderflag = 0;  //restrict left/right movement while on ladder
    //int floorflag = 1;   //stating whether mario is on a floor, to be used in conjunction with ladderflag

    struct ladder {
        int xleft;
        int xright;
        int ytop;
        int ybottom;
        int ladderflag;
    };
    
    int i;
    struct ladder ladarr[2];    //laddar array

    ladarr[0].xleft=555;
    ladarr[0].xright=570;
    ladarr[0].ytop=305;
    ladarr[0].ybottom=415;
    ladarr[0].ladderflag=0;

    ladarr[1].xleft=40;
    ladarr[1].xright=65;
    ladarr[1].ytop=205;
    ladarr[1].ybottom=310;
    ladarr[1].ladderflag=0;

    //initialize SDL
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

    SDL_Window * window = SDL_CreateWindow("Super Mega Awesome Donkey Kong",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Surface * image = IMG_Load ("mario.png");
    SDL_Surface * image2 = IMG_Load ("donkey.png");
    SDL_Surface * image3 = IMG_Load ("princess.png");
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_Texture * texture2 = SDL_CreateTextureFromSurface(renderer, image2);
    SDL_Texture * texture3 = SDL_CreateTextureFromSurface(renderer, image3);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    
    map(renderer);

    //main game loop
    while (!quit)
    {
        SDL_WaitEvent(&event);

        map(renderer);

        /*
        if ((x<245) && (x>220))
        {
            if ((y>25) && (y<110))
            {            
                ladderflag=1;
            }
            else
            {
                ladderflag = 0;
            }
        }
        else
        {
            ladderflag=0;
        }
        */

        /*
        //floorflag check
        if ((y==405) ^ (y==305) ^ (y==205) ^ (y==105) ^ (y==25))
        {
            floorflag=1;
        }
        else
        {
            floorflag=0;
        }
        */

        //win condition
        if (y==25)
        {
            if (x==230)
            {
                quit = true;
            }
        }

        /*
        if ((x<570) && (x>555))
        {
            if ((y>105) && (y<210))
            {            
                ladderflag=1;
            }
            else
            {
                ladderflag = 0;
            }
        }
        else
        {
            ladderflag=0;
        }
        */

        /*
        if ((x<65) && (x>40))
        {
            if ((y>205) && (y<310))
            {            
                ladderflag=1;
            }
            else
            {
                ladderflag = 0;
            }
        }
        else
        {
            ladderflag=0;
        }
        */

        for(i=0;i<2;i++)
        {
            if (((x+5)<ladarr[i].xright) && ((x+5)>ladarr[i].xleft))
            {
                if ((y>ladarr[i].ytop) && (y<ladarr[i].ybottom))
                {            
                    ladarr[i].ladderflag=1;
                    printf("Ladder flag is affirmative!!!\n");
                    ladderflag=i;
                }
                else
                {
                    ladarr[i].ladderflag = 0;
                    ladderflag=-1;
                    printf("Broken!\n");
                }
            }
            else
            {
                ladarr[i].ladderflag=0;
                ladderflag=-1;
                printf("Broken!\n");
            }
        }

        //suicide prevention
        if (y==25)
        {   
            if (x>280)
            {
                x=280;   
            }
        }
        else
        {
            if (x<20)
            {
                x=20;
            }
            if (x>600)
            {
                x=600;
            }
        }

        switch(event.type)
        {
        case SDL_QUIT:
            quit = true;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_LEFT:
                if ((ladderflag != -1)) //&& (floorflag == 0))
                {
                    x=x;
                    break;
                }
                else
                {
                    x=x-5;
                }
                break;
            case SDLK_RIGHT:
                if ((ladderflag != -1)) // && (floorflag == 0))
                {
                    x=x;
                    break;
                }
                else
                {
                    x=x+5;
                }
                break;
            case SDLK_UP:
                        if (ladderflag != -1)
                        {
                            y=y-5;
                        }
                break;
            case SDLK_DOWN:  
                        if (ladderflag != -1)
                        {
                            y=y+5;
                        }
                break;
            }
            map(renderer);
            printlocation(x,y,ladderflag, ladarr[i].ladderflag);
            //break;

        }
       

        SDL_Rect dstrect = { x, y, 20, 35 };
        SDL_Rect dstrect2 = { 60, 40, 60, 100 };
        SDL_Rect dstrect3 = { 210, 25, 20, 35 };

        //SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, &dstrect);
        SDL_RenderCopy(renderer, texture2, NULL, &dstrect2);
        SDL_RenderCopy(renderer, texture3, NULL, &dstrect3);
        SDL_RenderPresent(renderer);
                
    }

    //cleanup parts not used for win message
    SDL_DestroyTexture(texture);
    SDL_DestroyTexture(texture2);
    SDL_DestroyTexture(texture3);
    SDL_DestroyRenderer(renderer); 
    SDL_FreeSurface(image);
    SDL_FreeSurface(image2);
    SDL_FreeSurface(image3);
/*
    //win message
    SDL_Renderer * renderer2 = SDL_CreateRenderer(window, -1, 0);
    SDL_Surface * imageend = SDL_LoadBMP("end.bmp");
    SDL_Texture * textureend = SDL_CreateTextureFromSurface(renderer2, imageend);
    SDL_RenderCopy(renderer2, textureend, NULL, NULL);
    SDL_RenderPresent(renderer2);

    SDL_Delay(2000);

    //cleanup SDL
    SDL_DestroyTexture(textureend);
    SDL_DestroyRenderer(renderer2);
    SDL_FreeSurface(imageend);
*/

/*
    //win message part 2
    SDL_Renderer * renderer3 = SDL_CreateRenderer(window, -1, 0);
    SDL_Surface * imagetest1 = SDL_LoadBMP("test1.bmp");
    SDL_Texture * texturetest1 = SDL_CreateTextureFromSurface(renderer3, imagetest1);
    SDL_RenderCopy(renderer3, texturetest1, NULL, NULL);
    SDL_RenderPresent(renderer3);
    SDL_Delay(2000);
    SDL_DestroyTexture(texturetest1);
    SDL_DestroyRenderer(renderer3);
    SDL_FreeSurface(imagetest1);

    //win message part 3
    SDL_Renderer * renderer4 = SDL_CreateRenderer(window, -1, 0);
    SDL_Surface * imagetest2 = SDL_LoadBMP("test2.bmp");
    SDL_Texture * texturetest2 = SDL_CreateTextureFromSurface(renderer4, imagetest2);
    SDL_RenderCopy(renderer4, texturetest2, NULL, NULL);
    SDL_RenderPresent(renderer2);
    SDL_Delay(2000);
    SDL_DestroyTexture(texturetest2);
    SDL_DestroyRenderer(renderer4);
    SDL_FreeSurface(imagetest2);

    //win message part 4 (occasionally skips)
    SDL_Renderer * renderer5 = SDL_CreateRenderer(window, -1, 0);
    SDL_Surface * imagetest3 = SDL_LoadBMP("test3.bmp");
    SDL_Texture * texturetest3 = SDL_CreateTextureFromSurface(renderer5, imagetest3);
    SDL_RenderCopy(renderer5, texturetest3, NULL, NULL);
    SDL_RenderPresent(renderer5);
    SDL_Delay(2000);
    SDL_DestroyTexture(texturetest3);
    SDL_DestroyRenderer(renderer5);
    SDL_FreeSurface(imagetest3);

    //win message part 5
    SDL_Renderer * renderer6 = SDL_CreateRenderer(window, -1, 0);
    SDL_Surface * imagetest4 = SDL_LoadBMP("test4.bmp");
    SDL_Texture * texturetest4 = SDL_CreateTextureFromSurface(renderer6, imagetest4);
    SDL_RenderCopy(renderer6, texturetest4, NULL, NULL);
    SDL_RenderPresent(renderer6);
    SDL_Delay(2000);
    SDL_DestroyTexture(texturetest4);
    SDL_DestroyRenderer(renderer6);
    SDL_FreeSurface(imagetest4);
*/

/*
    //mario gif sequence
    int counter = 0;
    int delay = 50;
    while (counter < 20)
    {
        //A sequence
        SDL_Renderer * rendererA = SDL_CreateRenderer(window, -1, 0);
        SDL_Surface * imageframe0 = IMG_Load ("marioframe/frame_000.png");
        SDL_Texture * textureA = SDL_CreateTextureFromSurface(rendererA, imageframe0);
        SDL_RenderCopy(rendererA, textureA, NULL, NULL);
        SDL_RenderPresent(rendererA);
        SDL_Delay(delay);
        SDL_DestroyTexture(textureA);
        SDL_DestroyRenderer(rendererA);
        SDL_FreeSurface(imageframe0);

        //B sequence
        SDL_Renderer * rendererB = SDL_CreateRenderer(window, -1, 0);
        SDL_Surface * imageframe1 = IMG_Load ("marioframe/frame_001.png");
        SDL_Texture * textureB = SDL_CreateTextureFromSurface(rendererB, imageframe1);
        SDL_RenderCopy(rendererB, textureB, NULL, NULL);
        SDL_RenderPresent(rendererB);
        SDL_Delay(delay);
        SDL_DestroyTexture(textureB);
        SDL_DestroyRenderer(rendererB);
        SDL_FreeSurface(imageframe1);

        //C sequence
        SDL_Renderer * rendererC = SDL_CreateRenderer(window, -1, 0);
        SDL_Surface * imageframe2 = IMG_Load ("marioframe/frame_002.png");
        SDL_Texture * textureC = SDL_CreateTextureFromSurface(rendererC, imageframe2);
        SDL_RenderCopy(rendererC, textureC, NULL, NULL);
        SDL_RenderPresent(rendererC);
        SDL_Delay(delay);
        SDL_DestroyTexture(textureC);
        SDL_DestroyRenderer(rendererC);
        SDL_FreeSurface(imageframe2);

        //D sequence
        SDL_Renderer * rendererD = SDL_CreateRenderer(window, -1, 0);
        SDL_Surface * imageframe3 = IMG_Load ("marioframe/frame_003.png");
        SDL_Texture * textureD = SDL_CreateTextureFromSurface(rendererD, imageframe3);
        SDL_RenderCopy(rendererD, textureD, NULL, NULL);
        SDL_RenderPresent(rendererD);
        SDL_Delay(delay);
        SDL_DestroyTexture(textureD);
        SDL_DestroyRenderer(rendererD);
        SDL_FreeSurface(imageframe3);

        //E sequence
        SDL_Renderer * rendererE = SDL_CreateRenderer(window, -1, 0);
        SDL_Surface * imageframe4 = IMG_Load ("marioframe/frame_004.png");
        SDL_Texture * textureE = SDL_CreateTextureFromSurface(rendererE, imageframe4);
        SDL_RenderCopy(rendererE, textureE, NULL, NULL);
        SDL_RenderPresent(rendererE);
        SDL_Delay(delay);
        SDL_DestroyTexture(textureE);
        SDL_DestroyRenderer(rendererE);
        SDL_FreeSurface(imageframe4);

        counter++;
    }
    */

    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();


    return 0;
}
