#ifndef JULIA_H
#define JULIA_H

#include "SDL2/SDL.h"

#include <vector>
#include <array>

class Julia
{
public:
  Julia();

  void DrawJuliaSet(SDL_Renderer *r, int width, int height, double real, double imag, int maxiter);
  std::vector<std::array<int, 3>> GenerateColors();

private:
  std::vector<std::array<int, 3>> _rgb_colors;
};

#endif