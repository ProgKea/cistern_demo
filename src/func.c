#include "func.h"
#include <SDL2/SDL_blendmode.h>
#include <SDL2/SDL_image.h>

SDL_Window *win;
SDL_Renderer *renderer;

void init_sdl() {
  SDL_Init(SDL_INIT_EVERYTHING);
  win = SDL_CreateWindow("cistern demo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
  renderer = SDL_CreateRenderer(win, -1, 0);
  SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
}

void free_resources() {
  SDL_DestroyWindow(win);
  SDL_DestroyRenderer(renderer);
}

/* drawing */
void draw_rect(int x, int y, int w, int h, int r, int g, int b, int a) {
  SDL_Rect rect;
  rect.h = h;
  rect.w = w;
  rect.x = x;
  rect.y = y;

  SDL_SetRenderDrawColor(renderer, r, g, b, a);
  SDL_RenderFillRect(renderer, &rect);
}

void drawImgRect(SDL_Rect rect, SDL_Texture *tex) {
  SDL_RenderCopy(renderer, tex, NULL, &rect);
} 

void draw_water(int water_level) {
  draw_rect(0, HEIGHT-water_level, WIDTH, water_level, 0, 0, 100, 75);
}

void draw_water_stream(int x, int y, int width, int desty) {
  draw_rect(x, y, width, HEIGHT-desty-y, 0, 0, 100, 75);
}

void draw_line(int x1, int y1, int x2, int y2, int r, int g, int b, int a) {
  SDL_SetRenderDrawColor(renderer, r, g, b, a);
  SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

void draw_circle(int x, int y, int radius, int r, int g, int b, int a) {
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    for (int w = 0; w < radius * 2; w++)
    {
        for (int h = 0; h < radius * 2; h++)
        {
            int dx = radius - w; // horizontal offset
            int dy = radius - h; // vertical offset
            if ((dx*dx + dy*dy) <= (radius * radius))
            {
                SDL_RenderDrawPoint(renderer, x + dx, y + dy);
            }
        }
    }
}
