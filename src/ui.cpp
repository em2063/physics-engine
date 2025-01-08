#include <ui.h>

SDL_Rect toggleMode; // button used to toggle between different modes

// Function used to render the toggle button onto the screen (using SDL2's draw and fill features for shapes)
void renderToggleButton(SDL_Renderer *renderer, Mode mode)
{
    if (mode == MAIN_MODE)
    {
        SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255); // Light gray for button
    }
    else if (mode == SECOND_MODE)
    {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
    }
    toggleMode = {10, 10, 200, 50};
    SDL_RenderFillRect(renderer, &toggleMode);
}

// Function that returns the current state that of the mode the physics engine is in (balls mode/particles)
Mode getMode(Mode currentMode)
{
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    if (mouseX >= toggleMode.x && mouseX <= toggleMode.x + toggleMode.w && mouseY >= toggleMode.y && mouseY <= toggleMode.y + toggleMode.h)
    {
        return (currentMode == MAIN_MODE) ? SECOND_MODE : MAIN_MODE;
    }
    else
        return currentMode;
}