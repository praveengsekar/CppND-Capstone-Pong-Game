#include "ball.h"
#include <cmath>
#include <iostream>

void Ball::Update(Player const &player) {

  ball_y += speed_y;
  ball_x += speed_x;

  std::cout << "ball_x = " << ball_x << std::endl;
  std::cout << "ball_y = " << ball_y << std::endl;
  std::cout << "speed_x = " << speed_x << std::endl;
  std::cout << "speed_y = " << speed_y << std::endl;
  std::cout << "player_y = " << player.getPosY() << std::endl;

  if (static_cast<int>(ball_x + 0.5) >= grid_width-1)
    speed_x = speed_x * -1;
  
  if(static_cast<int>(ball_x + 0.5) == 1)
  {
    std::cout << "Reached Here" << std::endl;
    if(static_cast<int>(ball_y + 0.5) == static_cast<int>(player.getPosY()))
    {
      speed_x = speed_x * -1 + 0.2; 
      speed_y = speed_y - 0.1;                  
    }
    else if(static_cast<int>(ball_y + 0.5) == static_cast<int>(player.getPosY()-1))
    {
      speed_x = speed_x * -1;  
      speed_y = speed_y - 0.3;         
    }
    else if (static_cast<int>(ball_y + 0.5) == static_cast<int>(player.getPosY()+1))
    {
      speed_x = speed_x * -1 + 0.2;  
      speed_y = speed_y + 0.1;         
    }
    else if (static_cast<int>(ball_y + 0.5) == static_cast<int>(player.getPosY()+2))
    {
      speed_x = speed_x * -1 ;
      speed_y = speed_y + 0.3;         
    }
  }
 
  if(static_cast<int>(ball_x + 0.5) <= 0)
  {
    std::cout << "reached here 1 " << std::endl;
    indomain = false;   
  }

  if (static_cast<int>(ball_y + 0.5) >= grid_height-1 || static_cast<int>(ball_y + 0.5) <= 0)
    speed_y = speed_y * -1;  

  if (std::abs(speed_y) > 0.8)
        speed_y = copysign(0.8,speed_y);
    
  if (std::abs(speed_x) > 0.8)
    speed_x = copysign(0.8,speed_x);    
}