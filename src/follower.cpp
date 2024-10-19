#include "Follower.h"

void Follower::updateFollower() {
  int m_x, m_y;
  SDL_GetMouseState(&m_x, &m_y);
  float x_dif = static_cast<float>(m_x) - pos_x;
  float y_dif = static_cast<float>(m_y) - pos_y;

  float mv_v = sqrt(pow(x_dif, 2) + pow(y_dif, 2));
  x_dif = x_dif / mv_v;
  y_dif = y_dif / mv_v;

  // if (x_dif < 1.0f || y_dif < 1.0f) {
  //   printf("Mouse location: %d, %d\tGuy location: %f, %f\tMovement Vector:
  //   %f, "
  //          "%f\n",
  //          m_x, m_y, pos_x, pos_y, x_dif, y_dif);
  // } else
  //   printf("TOO FAST!!!\n");
  float dx = 0.01, dy = 0.01;
  if (tracking) {
    pos_x += (v * x_dif);
    pos_y += (v * y_dif);
  }

  if (a_o_f >= PI * 2)
    a_o_f = 0.0f;
  else if (a_o_f <= PI * -2)
    a_o_f = 0.0f;
}

void Follower::drawSightCone(SDL_Renderer *renderer) {
  int x1 = r_o_s * cos(a_o_f);
  int y1 = r_o_s * sin(a_o_f);

  int x2 = r_o_s * cos(a_o_f + a_o_s);
  int y2 = r_o_s * sin(a_o_f + a_o_s);

  for (float omega = a_o_f; omega < a_o_f + a_o_s; omega += 0.01f) {
    float x_c = r_o_s * cos(omega);
    float y_c = r_o_s * sin(omega);

    SDL_RenderDrawPoint(renderer, pos_x + x_c, pos_y - y_c);
  }

  SDL_RenderDrawLine(renderer, pos_x, pos_y, pos_x + x1, pos_y - y1);
  SDL_RenderDrawLine(renderer, pos_x, pos_y, pos_x + x2, pos_y - y2);
}

void Follower::increaseAngle() { a_o_f += 0.1f; }

void Follower::decreaseAngle() { a_o_f -= 0.1f; }
