#include <SDL3/SDL.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>

#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>

int main() {
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    SDL_Log("SDL_Init failed: %s", SDL_GetError());
    return 1;
  }

  if (!TTF_Init()) {
    SDL_Log("TTF_Init failed: %s", SDL_GetError());
    return 1;
  }

  SDL_Window *win = nullptr;
  SDL_Renderer *ren = nullptr;
  if (!SDL_CreateWindowAndRenderer("SDL3 Template", 800, 600, 0, &win, &ren)) {
    SDL_Log("CreateWindowAndRenderer failed: %s", SDL_GetError());
    return 1;
  }

  SDL_SetRenderDrawColor(ren, 20, 20, 25, 255);
  SDL_RenderClear(ren);
  SDL_RenderPresent(ren);

  SDL_Delay(2000); // minimal proof of life

  if (ren)
    SDL_DestroyRenderer(ren);
  if (win)
    SDL_DestroyWindow(win);
  TTF_Quit();
  SDL_Quit();
  return 0;
}
