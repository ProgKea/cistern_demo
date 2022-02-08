#include "vars.h"
#include "func.h"

int water_level = HEIGHT/3*2;
int water_max = HEIGHT/3*2;
int water_min = 10;

bool drain = false;
bool fill = false;

int ballx = WIDTH/2-200;
int bally;
int ballr = 75;
bool ball_is_down = false;

int valvex = WIDTH/2-175/2;
int valvey = HEIGHT-HEIGHT/4*3;
int valvew = 175;
int valveh = HEIGHT/4*3;
int valveymax = HEIGHT/5; 
int valveymin = HEIGHT-HEIGHT/4*3;
