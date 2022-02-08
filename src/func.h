#ifndef FUNC_H
#define FUNC_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <stdbool.h>

#define HEIGHT 750
#define WIDTH 1260

void init_sdl();
void free_resources();
void draw_water(int water_level);
void draw_water_stream(int x, int y, int width, int desty);
void draw_circle(int x, int y, int radius, int r, int g, int b, int a);
void draw_line(int x1, int y1, int x2, int y2, int r, int g, int b, int a);
void draw_rect(int x, int y, int w, int h, int r, int g, int b, int a);
#endif
