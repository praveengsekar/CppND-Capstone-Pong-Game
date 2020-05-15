#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>
#include <vector>
#include "SDL.h"

class Player {
 public:
 enum class Direction { kUp, kDown };
  Player(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        player_x(0.0),
        player_y(grid_height-1) {}

  Direction direction = Direction::kUp;

  void Update()
  {
    switch (direction) {
      case Direction::kUp:
        player_y -= 2;
        break;

      case Direction::kDown:
        player_y += 2;
        break;
    }
  }

  float getPosX() const {return player_x;}
  float getPosY() const {return player_y;}
  
 private:  
  float player_x;
  float player_y;
  int grid_width;
  int grid_height;
  
};

#endif