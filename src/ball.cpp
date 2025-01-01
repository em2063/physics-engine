#include "ball.h"

Ball::Ball(int x, int y, int radius, int r, int g, int b, int a)
    : x(x), y(y), radius(radius), r(r), g(g), b(b), a(a) {}

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