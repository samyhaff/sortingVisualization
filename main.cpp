#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cstdlib>

using namespace std;

const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080; 

SDL_Window *gWindow = NULL;
SDL_Renderer *gRenderer = NULL;

const int NB_OF_ELEMENTS = 40; 
int a[NB_OF_ELEMENTS];
const int RECT_WIDTH = SCREEN_WIDTH / NB_OF_ELEMENTS;

void generateArray()
{
    for (int i = 0; i < NB_OF_ELEMENTS; i++) 
    {
        a[i] = rand() % SCREEN_HEIGHT;
    }
}


void init() 
{
    SDL_Init(SDL_INIT_VIDEO);
    gWindow = SDL_CreateWindow("Sorting Algorithms", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
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

void drawArray() 
{
    // clear the screen
    SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(gRenderer);

    SDL_Rect fillRect;
    for (int i = 0; i < NB_OF_ELEMENTS; i++) 
    {
        fillRect = {i * RECT_WIDTH, SCREEN_HEIGHT - a[i], RECT_WIDTH, a[i]};
        SDL_SetRenderDrawColor(gRenderer, 0xff, 0xff, 0xff, 0xff);
        SDL_RenderFillRect(gRenderer, &fillRect);
    }
    SDL_RenderPresent(gRenderer);
}

void swap(int i, int j) 
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void bubbleSort() 
{
    for (int i = 0; i < NB_OF_ELEMENTS - 1; i++) 
    {
        for (int j = 0; j < NB_OF_ELEMENTS - i - 1; j++) 
        {
            if (a[j] > a[j + 1])
                swap(j, j + 1);
            SDL_Delay(10);
            drawArray();
        }
    }
}

int main(int argc, char *args[])
{
    init();
    generateArray();

    bool quit = false;
    SDL_Event e;

    bubbleSort();

    close();

    return 0;
}
