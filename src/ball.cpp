#include "ball.h"

const double GRAVITY = 650.0; // set constant for gravity

Ball::Ball(int x, int y, int radius, int r, int g, int b, int a)
    : x(x), y(y), radius(radius), r(r), g(g), b(b), a(a), vx(0), vy(0), ax(0), ay(GRAVITY) {}

void Ball::renderBall(SDL_Renderer *renderer) const
{

    SDL_SetRenderDrawColor(renderer, r, g, b, a);

    for (int w = 0; w < radius * 2; w++)
    {
        for (int h = 0; h < radius * 2; h++)
        {
            int dx = radius - w;
            int dy = radius - h;
            if (dx * dx + dy * dy <= radius * radius)
            {
                SDL_RenderDrawPoint(renderer, x + dx, y + dy);
            }
        }
    }
}

void Ball::updatePosition(double deltaT)
{
    // Apply gravity to vertical velocity
    vy += ay * (deltaT * 5);

    // Update position based on velocity
    x += vx * deltaT;
    y += vy * deltaT;

    // Collision detection for bottom boundary
    if (y + radius >= 600) // Bottom boundary
    {
        y = 600 - radius; // Clamp position to the bottom
        vy = 0;
    }

    // Collision detection for top boundary (optional, to prevent unrealistic behavior)
    if (y - radius < 0)
    {
        vy = -vy;   // Reverse velocity
        y = radius; // Clamp position to top
    }
}

void Ball::setVelocity(double vx, double vy)
{
    this->vx = vx;
    this->vy = vy;
}