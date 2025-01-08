#ifndef UI_H
#define UI_H

#include <SDL.h>
#include <engine.h>

// Different modes available
enum Mode
{
    BALLS,
    MANNEQUIN
};

static const Mode MAIN_MODE = BALLS;
static const Mode SECOND_MODE = MANNEQUIN;

void renderToggleButton(SDL_Renderer *renderer, Mode mode);
Mode getMode(Mode currentMode);

#endif