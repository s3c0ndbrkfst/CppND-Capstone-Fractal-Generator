#include "julia.h"

#include <iostream>
#include <complex>
#include <vector>
#include <array>

// Julia set fractal generation credit Katsumi (https://gist.github.com/KatsumiKougen/74468b3c1c4b9844f6f77a2922f588f9)

Julia::Julia()
{
  GenerateColors();
}

std::vector<std::array<int, 3>> Julia::GenerateColors()
{
  for (int col = 0; col < 256; col++)
  {
    std::array<int, 3> CurrentColor = {(col >> 5) * 36, (col >> 3 & 7) * 36, (col & 3) * 85};
    _rgb_colors.push_back(CurrentColor);
  }
  return _rgb_colors;
}

void Julia::DrawJuliaSet(SDL_Renderer *r, int width, int height, double real, double imag, int maxiter)
{
  std::complex<double> c = {real, imag}, z;

  // Calculate the Julia set for each pixel in the window
  for (int x = 0; x < width; x++)
  {
    for (int y = 0; y < height; y++)
    {
      z.real(1.5 * (x - width / 2) / (0.5 * width));
      z.imag((y - height / 2) / (0.5 * height));

      int i = maxiter;

      while (std::norm(z) < 4 && i > 0)
      {
        z = z * z + c;
        i--;
      }

      // Draw the Julia set for each pixel in the window
      SDL_SetRenderDrawColor(r, _rgb_colors[i][0], _rgb_colors[i][1], _rgb_colors[i][2], 0xff);
      SDL_RenderDrawPoint(r, x, y);
    }
  }
  SDL_RenderPresent(r);
}