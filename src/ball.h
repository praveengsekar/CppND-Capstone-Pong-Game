#ifndef BALL_H
#define BALL_H

#include <vector>
#include "SDL.h"
#include "player.h"

class Ball {
 public:
  Ball(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        ball_x(grid_width / 2),
        ball_y(grid_height / 2) {}

  void Update(Player const &player);
  bool isIndomain() const  {return indomain; }
  float getPosX() const {return ball_x;}
  float getPosY() const {return ball_y;}
 
 private:
  bool indomain{true};
  float ball_x;
  float ball_y;  
  float speed_x{0.1f};
  float speed_y{0.0f};  
  int grid_width;
  int grid_height;
};

#endif