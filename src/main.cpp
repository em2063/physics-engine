#include <SDL.h>

#include <engine.h>
#include <ball.h>
#include <ui.h>
#include <vector>
#include <chrono>
#include <iostream>

Mode currentMode = BALLS;

void renderToggleButton(SDL_Renderer *renderer, Mode mode)
{
    if (currentMode == BALLS)
    {
        SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255); // Light gray for button
    }
    else if (currentMode == PARTICLES)
    {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
    }
    SDL_Rect button = {10, 10, 200, 50};
    SDL_RenderFillRect(renderer, &button);
}

int main(int argc, char *argv[])
{
    // Init new engine window
    Engine engine("Physics Engine", 1200, 600);
    std::vector<Ball> balls; // init vector to hold balls in

    auto lastTime = std::chrono::high_resolution_clock::now();

    // start loop for window looping
    while (engine.isWindowRunning())
    {
        auto currentTime = std::chrono::high_resolution_clock::now();                  // get current time
        double deltaT = std::chrono::duration<double>(currentTime - lastTime).count(); // change in time (very small number usually ~16ms)

        lastTime = currentTime;

        SDL_Rect toggleMode = {10, 20, 200, 50}; // toggle button for selecting modes (ball engine, particle emitter etc)
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

                // Check if the toggle button was pressed for changing the mode
                if (mouseX >= toggleMode.x && mouseX <= toggleMode.x + toggleMode.w && mouseY >= toggleMode.y && mouseY <= toggleMode.y + toggleMode.h)
                {
                    currentMode = (currentMode == BALLS) ? PARTICLES : BALLS;
                }
                // Handle behaviour if the toggle is set to BALLS
                if (currentMode == BALLS && event.type == SDL_MOUSEBUTTONDOWN)
                {
                    int mouseX, mouseY;
                    SDL_GetMouseState(&mouseX, &mouseY);
                    balls.emplace_back(mouseX, mouseY, 20, 255, 0, 0, 255);
                }
                else if (currentMode == PARTICLES && event.type == SDL_MOUSEBUTTONDOWN)
                {
                    std::cout << "THIS IS PARTICLE MODE - COME BACK LATER.." << std::endl;
                }
            }
        }

        // Clear window
        engine.clear();

        renderToggleButton(engine.getRenderer(), currentMode);

        // TODO - IMPROVE ALGORITHM FROM BRUTE FORCE
        // Render balls and check for collisions (iterating through the entire vector)
        for (size_t i = 0; i < balls.size(); ++i)
        {
            for (size_t j = i + 1; j < balls.size(); ++j)
            {
                if (balls[i].ballIsColliding(balls[j]))
                {
                    balls[i].resolveCollision(balls[j]); // if there is a collision then we can apply the algorithm that updates positions of ball based on the collision
                }
            }
            balls[i].updatePosition(deltaT);           // ensures ball is always where it should be relative to its surroundings
            balls[i].renderBall(engine.getRenderer()); // makes ball visible on the screen
        }

        // ensures physics on screen reflects what has been calculated
        engine.update();
    }

    return 0;
}
