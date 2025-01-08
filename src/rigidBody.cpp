#include <rigidBody.h>

RigidBody::RigidBody(int x, int y, int width, int height, double mass)
    : x(x), y(y), width(width), height(height), mass(mass), vx(0), vy(300), ax(0), ay(0) {}

void RigidBody::render(SDL_Renderer *renderer) const
{
    SDL_Rect part = {x, y, width, height};
    SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
    SDL_RenderFillRect(renderer, &part);
}

void RigidBody::update(double deltaT)
{
    // update v based on acceleration
    vx += ax * deltaT;
    vy += ay * deltaT;

    // update position based on velocity
    x += static_cast<int>(vx * deltaT);
    y += static_cast<int>(vy * deltaT);

    // reset a
    ax = 0;
    ay = 0;
}

void RigidBody::applyForce(double fx, double fy)
{
    ax += fx / mass;
    ay += fy / mass;
}