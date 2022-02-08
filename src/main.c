#include "func.h"
#include "vars.h"

const int fps = 60;
const int desiredDelta = 1000 / fps;
int startLoop;

#ifdef _WIN32
int WinMain(int argc, char argv[])
#else
int main()
#endif
{
  init_sdl();

  // main loop
  while (1) {
    startLoop = SDL_GetTicks();
    SDL_Event e;
    
    if (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT)
        break;
      if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_q)
        break;
      if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE && fill != true)
        drain = true;
    }

    SDL_RenderClear(renderer);
    draw_line(ballx, bally, WIDTH-175, 100, 0, 0, 0, 255);
    draw_circle(ballx, bally, ballr, 255, 0, 0, 255);
    draw_rect(valvex, valvey, valvew, valveh, 20, 100, 20, 255);
    draw_rect(WIDTH/2-200/2, HEIGHT-water_min, 200, water_min, 0, 0, 0, 255);
    if (ball_is_down) draw_water_stream(WIDTH-100, 100, 50, water_level);
    draw_water(water_level);
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255); // background colour
    SDL_RenderPresent(renderer);

    // stop ball
    if (water_level >= HEIGHT/3) {
      bally = HEIGHT-water_level-ballr+ballr/3*2;
    }
    else ball_is_down = true;
    if (water_level == water_max) 
      ball_is_down = false;

    // drain water
    if (drain && water_level != water_min) {
      water_level--;
      if (valvey!=valveymax)
        valvey--;
    }
    else {
      drain = false;
      fill = true;
    }

    // fill water
    if (fill && water_level != water_max) {
      water_level++;
      if (valvey!=valveymin)
        valvey++;
    }
    else fill = false;

    // limit frames
    int delta = SDL_GetTicks() - startLoop;
    if (delta < desiredDelta)
      SDL_Delay(desiredDelta-delta);
  }

  free_resources();
  return 0;
}
