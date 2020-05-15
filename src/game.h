#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "ball.h"
#include "player.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);

 private:
  Player player;
  Ball ball;

  void Update();
};

#endif