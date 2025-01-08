#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include <SDL.h>

class RigidBody
{
public:
    RigidBody(int x, int y, int width, int height, double mass = 1.0); // Defines the attributes required for body parts on models

    void render(SDL_Renderer *renderer) const;

    // Update position based on velocity and forces
    void update(double deltaT);

    void applyForce(double fx, double fy);

    // Move the rigid body manually (e.g., user-controlled movement)
    void move(int deltaX, int deltaY);

    void setVelocity(double vx, double vy);
    void getVelocity(double &vx, double &vy) const;

    // Collision boundary check
    SDL_Rect getBounds() const;

private:
    int x, y;
    double mass;
    int width, height;

    double vx, vy;
    double ax, ay;
};

#endif