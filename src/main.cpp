#include <SDL.h>

#include <engine.h>
#include <ball.h>
#include <vector>

int main(int argc, char *argv[])
{
    // Init new engine window
    Engine engine("Physics Engine", 1200, 600);

    std::vector<Ball> balls;

    // start loop for window looping
    while (engine.isWindowRunning())
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                return 0; // Window is closed; break
            }

            // Check for mouse click
            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);

                // Create a new ball at the mouse click position
                balls.emplace_back(mouseX, mouseY, 10, 255, 0, 0, 255); // Red ball, radius 20
            }
        }

        // Clear window
        engine.clear();

        // Render all balls
        for (const auto &ball : balls)
        {
            ball.renderBall(engine.getRenderer());
        }

        engine.update();
    }

    return 0;
}
