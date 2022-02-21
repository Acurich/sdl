#include <SDL.h>
#include <iostream>
#define WINDOW_WIDTH 600

using namespace std;
.
void hLine(SDL_Renderer *renderer, int x, int y, int length) {
    if (length < 0) for (int i = x; i > x + length; i--) SDL_RenderDrawPoint(renderer, i, y);
    else for (int i = x; i < x + length; i++) SDL_RenderDrawPoint(renderer, i, y);
}
void vLine(SDL_Renderer *renderer, int x, int y, int length) {
    if (length < 0) for (int i = y; i > y + length; i--) SDL_RenderDrawPoint(renderer, x, i);
    else for (int i = y; i < y + length; i++) SDL_RenderDrawPoint(renderer, x, i);
}

void drawRobot(SDL_Renderer *r) {
    //left ear
    hLine(r, 50, 50, 50);
    hLine(r, 50, 200, 50);
    vLine(r, 50, 50, 150);
    vLine(r, 100, 50, 150);
    //head
    hLine(r, 100, 65, 300);
    hLine(r, 100, 250, 300);
    vLine(r, 100, 65, 185);
    vLine(r, 400, 65, 185);
    //right ear
    hLine(r, 400, 50, 50);
    hLine(r, 400, 200, 50);
    vLine(r, 400, 50, 150);
    vLine(r, 450, 50, 150);
    //left eye
    hLine(r, 140, 100, 50);
    hLine(r, 140, 150, 50);
    vLine(r, 140, 100, 50);
    vLine(r, 190, 100, 50);
    //right eye
    hLine(r, 310, 100, 50);
    hLine(r, 310, 150, 50);
    vLine(r, 310, 100, 50);
    vLine(r, 360, 100, 50);
    //mouth
    hLine(r, 130, 200, 230);
    hLine(r, 130, 230, 230);
    vLine(r, 130, 200, 30);
    vLine(r, 360, 200, 30);
}

void drawLine(SDL_Renderer *renderer, int x1, int y1, int x2, int y2) {
    float dy = y2 - y1;
    float dx = x2 - x1;
    float k = dy / dx;
    for (float x = x1; x < x2; x++){
        float y = k * x;
        SDL_RenderDrawPoint(renderer, x, y);
    }
}

int main(int argc, char* args[]){
    SDL_Renderer *renderer;
    SDL_Window *window;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_WIDTH, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 0);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

    //drawRobot(renderer);
    drawLine(renderer, 200, 200, 400, 300);

    SDL_RenderPresent(renderer);
    SDL_Delay(3000);
    SDL_Quit();
    return 0;
}
