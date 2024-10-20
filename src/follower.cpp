#include "Follower.h"

float dotProduct(float ax, float ay, float bx, float by) {
  return (ax * bx) + (ay * by);
}

void Follower::updateFollower() {
  SDL_GetMouseState(&m_x, &m_y);
  float x_dif = static_cast<float>(m_x) - pos_x;
  float y_dif = static_cast<float>(m_y) - pos_y;

  float mv_v = sqrt(pow(x_dif, 2) + pow(y_dif, 2));
  x_dif = x_dif / mv_v;
  y_dif = y_dif / mv_v;

  float dx = 0.01, dy = 0.01;
  if (isDetected() && distanceMag <= radius)
    detected = true;

  if (detected) {
    pos_x += (v * x_dif);
    pos_y += (v * y_dif);

    aof = atan2(v * y_dif, v * x_dif);
  }

  if (aof >= PI * 2)
    aof = 0.0f;
  else if (aof <= PI * -2)
    aof = 0.0f;
}

void Follower::drawSightCone(SDL_Renderer *renderer) {
  float x1 = radius * cos(aof + (aos * 0.5f));
  float y1 = radius * sin(aof + (aos * 0.5f));

  float x2 = radius * cos(aof + (-aos * 0.5f));
  float y2 = radius * sin(aof + (-aos * 0.5f));

  SDL_RenderDrawLine(renderer, pos_x, pos_y, pos_x + x1, pos_y + y1);
  SDL_RenderDrawLine(renderer, pos_x, pos_y, pos_x + x2, pos_y + y2);

  sideX = m_x - pos_x;
  sideY = m_y - pos_y;
  distanceMag = sqrt(sideX * sideX + sideY * sideY);

  for (float omega = aof + (-aos * 0.5f); omega < aof + (aos * 0.5f);
       omega += 0.01f) {
    float xc = radius * cos(omega);
    float yc = radius * sin(omega);

    SDL_RenderDrawPoint(renderer, pos_x + xc, pos_y + yc);
  }
}

void Follower::increaseAngle() { aof += 0.1f; }

void Follower::decreaseAngle() { aof -= 0.1f; }

bool Follower::isDetected() {
  float coneX = radius * cos(aof);
  float coneY = radius * sin(aof);

  float dot = dotProduct((float)sideX / distanceMag, (float)sideY / distanceMag,
                         coneX / radius, coneY / radius);

  float angle = acos(dot);

  return angle < (aof / 2.0f);
}
