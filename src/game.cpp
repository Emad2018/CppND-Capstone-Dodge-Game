#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height):_dodge(grid_width,grid_height)
    
{
  

   
	_enemies.push_back(std::make_shared<Enemie>(grid_width, grid_height));
   _grid_width = static_cast<int>(grid_width);
   _grid_height = static_cast<int>(grid_height);
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration,bool &_play) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;
  char user_input;
  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, _dodge);
    Update();
    renderer.Render(_dodge, _enemies);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;
    
    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1500) {
      if (_dodge.alive)
      {
          _enemies.push_back(std::make_shared<Enemie>(_grid_width, _grid_height));
          score +=10;
          //_enemies[0]->speed += 0.01;

      }
      else
      {
           std::cout<<"Play again?press y\n";
           std::cin>>&user_input;
           if((user_input=='y')||(user_input=='Y'))
           {
              _play=true;
              std::cout<<"let's Go\n";

           }
           else
           _play=false;

           break;


      }
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
      //std::cout<< _enemies[1]->speed<<std::endl;
      
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
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

  for (int i=0;i<_enemies.size();i++)
  {
    _enemies[i]->Update();

    if(_dodge.DodgeCell(_enemies[i]->x, _enemies[i]->y))
    {

     _dodge.alive=false;
    }
    if(_enemies[i]->y >= _grid_height)
    {
        _enemies.erase(_enemies.begin()+i);

    }
  }




  
}

int Game::GetScore() const { return score; }