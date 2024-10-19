#pragma once

#include "Follower.h"

inline Follower guy(1280 / 2, 720 / 2);
class Sim {
  SDL_Window *window;
  SDL_Renderer *renderer;

  SDL_Event event;

  bool running = true;

  SDL_Rect m_rect{0, 0, 20, 20};

public:
  void init();
  void handleEvents();
  void update();
  void render();
  void run();
};
