#ifndef RENDERER_H
#define RENDERER_H

#include "SDL2/SDL.h"
#include <string>

class Renderer
{
public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height);
  ~Renderer();
  void UpdateWindowTitle(double real, double imag);
  void UpdateWindowTitle(double real, double imag, std::string custom_title);

  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;
  
private:
  const std::size_t screen_width;
  const std::size_t screen_height;
};

#endif