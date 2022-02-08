#ifndef VARS_H
#define VARS_H
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>
#include <stdbool.h>
extern SDL_Window *win;
extern SDL_Renderer *renderer;

// water values
extern int water_level;
extern int water_max;
extern int water_min;

// actions
extern bool drain;
extern bool fill;

// ball values
extern int ballx;
extern int bally;
extern int ballr;
extern bool ball_is_down;

// valve values;
extern int valvex;
extern int valvey;
extern int valvew;
extern int valveh;
extern int valveymax; 
extern int valveymin;
#endif
