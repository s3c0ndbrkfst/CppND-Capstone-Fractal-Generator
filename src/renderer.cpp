#include "renderer.h"
#include <iostream>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height)
    : screen_width(screen_width),
      screen_height(screen_height)
{
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow( 
      "Julia set - Press ESC to exit, SPACE to reset, Arrow keys to update image",
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      screen_width, screen_height,
      SDL_WINDOW_SHOWN
  );

  if (nullptr == sdl_window)
  {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);

  if (nullptr == sdl_renderer)
  {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  SDL_SetRenderDrawColor(sdl_renderer, 0xff, 0xff, 0xff, 0xff);
  SDL_RenderClear(sdl_renderer);
}

Renderer::~Renderer()
{
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::UpdateWindowTitle(double real, double imag)
{
  std::string title{"Press ESC to exit, SPACE to reset - c = " + std::to_string(real) + " + " + std::to_string(imag) + "i"};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}

void Renderer::UpdateWindowTitle(double real, double imag, std::string custom_title)
{
  std::string title{custom_title + std::to_string(real) + " + " + std::to_string(imag) + "i"};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}