#include <engine.h>
#include <iostream>

Engine::Engine(const std::string &title, int width, int height)
    : window(nullptr), renderer(nullptr), running(true)
{

    // Initialise the SDL environment
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "Could not initialise SDL!" << SDL_GetError() << std::endl;
        running = false;
        return;
    }

    // Create a window for the environment
    window = SDL_CreateWindow(title.c_str(),
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              width, height,
                              SDL_WINDOW_SHOWN);

    if (!window)
    {
        std::cerr << "Error! Could not create window" << SDL_GetError() << std::endl;
        running = false;
        return;
    }

    // Creates renderer for displaying information
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        std::cerr << "Error! Could not create renderer" << SDL_GetError() << std::endl;
        running = false;
        return;
    }
}

Engine::~Engine()
{
    if (renderer)
        SDL_DestroyRenderer(renderer);
    if (window)
        SDL_DestroyWindow(window);
    SDL_Quit();
}

// Clears window and sets as a blank screen
void Engine::clear()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Set color to black
    SDL_RenderClear(renderer);
}

// Updates the window to incluude the rendered information
void Engine::update()
{
    SDL_RenderPresent(renderer); // Update the window
}

// method to check if the current window is still open - returns window status.
bool Engine::isWindowRunning()
{
    return running;
}

SDL_Renderer *Engine::getRenderer()
{
    return renderer;
}
