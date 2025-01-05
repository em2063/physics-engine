#include <ui.h>

void renderToggleButton(SDL_Renderer *renderer, Mode mode)
{
    if (mode == BALLS)
    {
        SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255); // Light gray for button
    }
    else if (mode == PARTICLES)
    {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
    }
    SDL_Rect button = {10, 10, 200, 50};
    SDL_RenderFillRect(renderer, &button);
}