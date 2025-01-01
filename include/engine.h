#ifndef ENGINE_H
#define ENGINE_H

#include <SDL.h>
#include <string>

class Engine
{
public:
    Engine(const std::string &title, int width, int height);
    ~Engine();

    void clear();           // Clears window of all content
    void update();          // Updates window with any new content
    bool isWindowRunning(); // returns boolean to check if user exits window
    SDL_Renderer *getRenderer();

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool running; // boolean to check for window exit
};

#endif