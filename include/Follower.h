#pragma once
#include <SDL2/SDL.h>
#include <cmath>
#include <iostream>

inline const float PI = 3.14;

class Follower {
  bool tracking = false;
  float a_o_f = -PI / 6;
  float a_o_s = PI / 3;
  int r_o_s = 90;

public:
  float pos_x, pos_y;
  float v = 0.1;

  Follower(int x, int y) : pos_x(x), pos_y(y) {}

  void updateFollower();
  void drawSightCone(SDL_Renderer *renderer);
  void increaseAngle();
  void decreaseAngle();
};
