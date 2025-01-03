#include "ball.h"
#include <cmath>
#include <iostream>
#include <algorithm>

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

    if (x + radius >= 1200)
    {
        x = 1200 - radius;
        vx = 0;
    }

    if (x - radius < 0)
    {
        x = radius;
        vx = 0;
    }
}

void Ball::setVelocity(double vx, double vy)
{
    this->vx = vx;
    this->vy = vy;
}

bool Ball::ballIsColliding(const Ball &otherBall) const
{
    double dx = x - otherBall.x;
    double dy = y - otherBall.y;
    double dSquared = dx * dx + dy * dy;
    double radiusSum = radius + otherBall.radius;

    return dSquared <= radiusSum * radiusSum;
}

void Ball::resolveCollision(Ball &otherBall)
{
    double dx = x - otherBall.x;
    double dy = y - otherBall.y;
    double distance = std::sqrt(dx * dx + dy * dy);

    if (distance == 0)
        return;

    // Calculate the overlap
    double overlap = (radius + otherBall.radius) - distance;

    if (overlap > 0)
    {
        // Normalize the collision vector
        double nx = dx / distance;
        double ny = dy / distance;

        // Resolve overlap by moving the balls apart
        double totalRadius = radius + otherBall.radius;
        double weight1 = otherBall.radius / totalRadius;
        double weight2 = radius / totalRadius;

        x += overlap * weight1 * nx;
        y += overlap * weight1 * ny;

        otherBall.x -= overlap * weight2 * nx;
        otherBall.y -= overlap * weight2 * ny;

        // Simulate a sliding effect by dampening velocity along the collision normal
        double velocityAlongNormal = (vx - otherBall.vx) * nx + (vy - otherBall.vy) * ny;

        if (velocityAlongNormal < 0)
        {
            vx -= velocityAlongNormal * nx * 0.1;
            vy -= velocityAlongNormal * ny * 0.5;

            otherBall.vx += velocityAlongNormal * nx * 0.1;
            otherBall.vy += velocityAlongNormal * ny * 0.5;
        }
    }
}
