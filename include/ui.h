#ifndef UI_H
#define UI_H

#include <SDL.h>
#include <engine.h>

// Different modes available
enum Mode
{
    BALLS,
    PARTICLES
};

void renderToggleButton(SDL_Renderer *renderer, Mode mode);
Mode getMode(Mode currentMode);

#endif