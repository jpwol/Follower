#pragma once
#include <SDL2/SDL.h>
#include <cmath>
#include <iostream>

inline const float PI = 3.14;

class Follower {
  bool detected = false;
  // float aof = PI / 3;
  float aof = PI;
  float aos = PI / 3;
  int radius = 90;
  int distanceMag;
  int sideX, sideY;

  int m_x, m_y;

public:
  float pos_x, pos_y;
  float v = 0.01;

  Follower(int x, int y) : pos_x(x), pos_y(y) {}

  void updateFollower();
  void drawSightCone(SDL_Renderer *renderer);
  void increaseAngle();
  void decreaseAngle();

  bool getDetection() { return detected; }
  void setDetection(bool d) { detected = d; }

  bool isDetected();
};
