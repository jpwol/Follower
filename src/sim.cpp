#include "Sim.h"

void Sim::init() {
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    window = SDL_CreateWindow("Follower", SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, 1280, 720, 0);
    if (window == NULL) {
      std::cerr << "Window is null!\n";
      return;
    } else {
      renderer = SDL_CreateRenderer(window, -1, 0);
      if (renderer == NULL) {
        std::cerr << "Renderer is null!\n";
        return;
      }
    }
  }
}

void Sim::handleEvents() {
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_QUIT:
      running = false;
      break;
    case SDL_KEYDOWN:
      switch (event.key.keysym.sym) {
      case SDLK_ESCAPE:
        running = false;
        break;
      case SDLK_SPACE:
        guy.setDetection(false);
        break;
      case SDLK_w:
        guy.increaseAngle();
        break;
      case SDLK_s:
        guy.decreaseAngle();
        break;
      default:
        break;
      }
    default:
      break;
    }
  }
}

void Sim::update() { guy.updateFollower(); }

void Sim::render() {
  SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255);
  SDL_RenderClear(renderer);
  SDL_SetRenderDrawColor(renderer, 90, 90, 90, 255);
  m_rect.x = guy.pos_x - 10;
  m_rect.y = guy.pos_y - 10;

  if (guy.getDetection())
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
  guy.drawSightCone(renderer);

  SDL_RenderFillRect(renderer, &m_rect);
  SDL_RenderPresent(renderer);
}

void Sim::run() {
  init();
  while (running) {
    handleEvents();
    update();
    render();
  }
  SDL_Quit();
}
