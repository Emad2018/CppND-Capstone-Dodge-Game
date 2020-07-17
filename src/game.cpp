#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height) : _dodge(std::move(grid_width), std::move(grid_height))

{
  // add the first Enemie
  _enemies.push_back(std::make_shared<Enemie>(std::move(grid_width), std::move(grid_height)));
  _grid_width = static_cast<int>(grid_width);
  _grid_height = static_cast<int>(grid_height);
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration, bool &_play)
{
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;
  char user_input;
  while (running)
  {

    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, _dodge);
    if (!running)
    {
      _play = false;
      break;
    }
    Update();
    renderer.Render(_dodge, _enemies);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    if ((frame_end - title_timestamp) % 20 == 0) // check if the differeence devisable by 20 (it will be random add for the Enemies int next line)
    {

      if (_dodge.alive)
      {
       _enemies.push_back(std::make_shared<Enemie>(std::move(_grid_width), std::move(_grid_height)));// add new Enemie
        score += 5;                                                              // increase the score
      }
      else
      {
        std::cout << "Play again?press y\n"; //check If the player Died then ask for restart the game
        std::cin >> &user_input;
        if ((user_input == 'y') || (user_input == 'Y'))
        {
          _play = true;
          std::cout << "let's Go\n";
        }
        else
        {
          _play = false;
        }
        break;
      }
    }
    // After every second, update the window title.
    else if (frame_end - title_timestamp >= 1000)
    {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration)
    {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::Update()
{
  if (!_dodge.alive)
  {
    return;
  }

  _dodge.Update();

  for (int i = 0; i < _enemies.size(); i++)
  {
    _enemies[i]->Update();

    if (_dodge.DodgeCell(_enemies[i]->x, _enemies[i]->y)) //check if dodge hits the Enemie
    {

      _dodge.alive = false;
    }
    if (_enemies[i]->y >= _grid_height) // check if the Enemie reached the ENd of the sceen then remove it
    {
      _enemies.erase(_enemies.begin() + i);
    }
  }
}

int Game::GetScore() const { return score; }