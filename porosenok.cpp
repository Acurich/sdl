#include <string>
#include <iostream>
#include <cmath>
#include <SDL.h>
#define WINDOW_WIDTH 600
using namespace std;

void line (SDL_Renderer *renderer, int x1, int y1, int x2, int y2) {

    int len = max(abs(x2-x1), abs(y2-y1));

    double dx = (double)(x2-x1)/len;
    double dy = (double)(y2-y1)/len;

    for (int i = 0; i < len; i++) {
        SDL_RenderDrawPoint(renderer, roundf(x1), roundf(y1));
        x1 = (int)((double)x1 + dx);
        y1 = (int)((double)y1 + dy);
}
}

void create_rectangle(SDL_Renderer* renderer, int x1, int y1, int x2, int y2) {
    line(renderer, x1, y1, x2, y1);
    line(renderer, x2, y2, x1, y2);
    line(renderer, x1, y1, x1, y2);
    line(renderer, x2, y2, x2, y1);
}

int main(int argc, char * argv[] )
{
    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        SDL_Renderer *renderer;
        SDL_Window *window;
        if (SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_WIDTH, 0, &window, &renderer) == 0) {
            SDL_bool done = SDL_FALSE;
            while (!done) {
                SDL_Event event;
                SDL_SetRenderDrawColor(renderer, 0, 0 , 0, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(renderer);
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);


                create_rectangle(renderer, 50, 50, 400, 175);
                create_rectangle(renderer, 400, 50, 550, 200);
                create_rectangle(renderer, 130, 70, 320, 80);
                create_rectangle(renderer, 80, 175, 150, 250);
                create_rectangle(renderer, 280, 175, 350, 250);
                create_rectangle(renderer, 450, 200, 500, 250);

                SDL_RenderPresent(renderer);
                while(SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) done = SDL_TRUE;
                }
            }
        }
        if (renderer) SDL_DestroyRenderer(renderer);
        if (window) SDL_DestroyWindow(window);
    }


    //line(renderer, 0, 0, 500, 500);


    SDL_Quit();
    return 1;
}

