#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "dodge.h"

void Controller::HandleInput(bool &running, Dodge &dodge) const
{
  SDL_Event e;
  while (SDL_PollEvent(&e))
  {
    if (e.type == SDL_QUIT)
    {
      running = false;
    }
    else if (e.type == SDL_KEYDOWN)
    {
      switch (e.key.keysym.sym)
      {
      case SDLK_UP:

        dodge.direction = Dodge::Direction::kUp;
        break;

      case SDLK_DOWN:

        dodge.direction = Dodge::Direction::kDown;
        break;

      case SDLK_LEFT:

        dodge.direction = Dodge::Direction::kLeft;
        break;

      case SDLK_RIGHT:

        dodge.direction = Dodge::Direction::kRight;
        break;
      }
    }
    else if (e.type == SDL_KEYUP)
    {
      dodge.direction = Dodge::Direction::KHold;
    }
  }
}