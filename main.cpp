#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080; 

SDL_Window *gWindow = NULL;
SDL_Renderer *gRenderer = NULL;

void init() 
{
    SDL_Init(SDL_INIT_VIDEO);
    gWindow = SDL_CreateWindow("Sorting Algorithms", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(gRenderer, 0xff, 0xff, 0xff, 0xff);
}

void close() 
{
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;

    IMG_Quit();
    SDL_Quit();
}

int main(int argc, char *args[])
{
    init();

    bool quit = false;
    SDL_Event e;
    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT) 
                quit = true; 
        }

        SDL_SetRenderDrawColor(gRenderer, 0xff, 0xff, 0xff, 0xff);
        SDL_RenderClear(gRenderer);

        SDL_Rect fillRect = {SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
        SDL_SetRenderDrawColor(gRenderer, 0xff, 0x00, 0x00, 0xff);
        SDL_RenderFillRect(gRenderer, &fillRect);

        SDL_RenderPresent(gRenderer);
    }

    close();

    return 0;
}
