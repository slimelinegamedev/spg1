#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char ** argv)
{
    // variables

    bool quit = false;
    SDL_Event event;
    int x = 288;
    int y = 208;

    // init SDL

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window * window = SDL_CreateWindow("SDL2 Keyboard/Mouse events",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Surface * image = SDL_LoadIMG("mario.png");
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer,
        image);
    SDL_FreeSurface(image);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

    // handle events

    while (!quit)
    {
        SDL_WaitEvent(&event);

        switch (event.type)
        {
        case SDL_QUIT:
            quit = true;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_LEFT:  x--; break;
            case SDLK_RIGHT: x++; break;
            case SDLK_UP:    y--; break;
            case SDLK_DOWN:  y++; break;
            }
            break;
        }

        SDL_Rect dstrect = { x, y, 64, 64 };

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, &dstrect);
        SDL_RenderPresent(renderer);
    }

    // cleanup SDL

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
