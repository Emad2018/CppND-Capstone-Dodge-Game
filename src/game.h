#ifndef GAME_H
#define GAME_H
#include <memory>
#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "dodge.h"
#include "enemie.h"


class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;


 private:
  Dodge _dodge;
  std::vector<std::shared_ptr<Enemie>>_enemies;

  int score{0};

  void Update();
};

#endif