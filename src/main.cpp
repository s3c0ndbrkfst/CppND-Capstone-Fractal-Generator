#include "SDL2/SDL.h"
#include "julia.h"
#include "renderer.h"
#include "parameters.h"

#include <iostream>
#include <string>
#include <vector>
#include <map>

std::map<int, std::vector<double>> custom_parameters = {
    {SDLK_1, ReadParameters("1")},
    {SDLK_2, ReadParameters("2")},
    {SDLK_3, ReadParameters("3")},
    {SDLK_4, ReadParameters("4")},
    {SDLK_5, ReadParameters("5")},
    {SDLK_6, ReadParameters("6")},
    {SDLK_7, ReadParameters("7")},
    {SDLK_8, ReadParameters("8")},
    {SDLK_9, ReadParameters("9")},
};

int main()
{
  // Constants
  const int MaximumIterations = 256;
  const int ScreenWidth = 800;
  const int ScreenHeight = 600;

  // Create renderer
  Renderer renderer(ScreenWidth, ScreenHeight);

  // Create Julia object
  Julia julia;

  // Initial values
  double real = -0.7;
  double imag = 0.27015;

  // Draw initial Julia set
  julia.DrawJuliaSet(renderer.sdl_renderer, ScreenWidth, ScreenHeight, real, imag, MaximumIterations);

  SDL_Event event;
  while (1)
  {
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
      exit(0);
      break;
    case SDL_KEYDOWN:
      if (event.key.keysym.sym == SDLK_ESCAPE)
      {
        exit(0);
        break;
      }
      else if (event.key.keysym.sym == SDLK_SPACE)
      {
        real = -0.7;
        imag = 0.27015;
        julia.DrawJuliaSet(renderer.sdl_renderer, ScreenWidth, ScreenHeight, real, imag, MaximumIterations);
        renderer.UpdateWindowTitle(real, imag);
      }
      else if (event.key.keysym.sym == SDLK_UP)
      {
        real += 0.01;
        julia.DrawJuliaSet(renderer.sdl_renderer, ScreenWidth, ScreenHeight, real, imag, MaximumIterations);
        renderer.UpdateWindowTitle(real, imag);
      }
      else if (event.key.keysym.sym == SDLK_DOWN)
      {
        real -= 0.01;
        julia.DrawJuliaSet(renderer.sdl_renderer, ScreenWidth, ScreenHeight, real, imag, MaximumIterations);
        renderer.UpdateWindowTitle(real, imag);
      }
      else if (event.key.keysym.sym == SDLK_RIGHT)
      {
        imag += 0.01;
        julia.DrawJuliaSet(renderer.sdl_renderer, ScreenWidth, ScreenHeight, real, imag, MaximumIterations);
        renderer.UpdateWindowTitle(real, imag);
      }
      else if (event.key.keysym.sym == SDLK_LEFT)
      {
        imag -= 0.01;
        julia.DrawJuliaSet(renderer.sdl_renderer, ScreenWidth, ScreenHeight, real, imag, MaximumIterations);
        renderer.UpdateWindowTitle(real, imag);
      }
      else if (event.key.keysym.sym >= SDLK_1 && event.key.keysym.sym <= SDLK_9)
      {
        std::vector<double> parameters = custom_parameters[event.key.keysym.sym];
        real = parameters[0];
        imag = parameters[1];
        julia.DrawJuliaSet(renderer.sdl_renderer, ScreenWidth, ScreenHeight, real, imag, MaximumIterations);
        renderer.UpdateWindowTitle(real, imag, "Custom - c = ");
      }
    }
  }
  return 0;
}