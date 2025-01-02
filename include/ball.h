#ifndef BALL_H
#define BALL_H

#include <SDL.h>

class Ball
{
public:
    Ball(int x, int y, int radius, int r, int g, int b, int a);

    void renderBall(SDL_Renderer *renderer) const; // render the ball onto the screen
    void updatePosition(double deltaT);            // update the ball position within the container (from physical effects such as gravity)

    void setVelocity(double vx, double vy); // set the balls initial velocity

    // Functions to allow collisions between balls to be possible
    bool ballIsColliding(const Ball &otherBall) const; // Used to detect whether two balls have collided (basic solution to check whether the circles have intersected)
    // void resolveCollision(Ball &otherBall);

private:
    int x, y;       // 2D position of the ball
    int radius;     // radius of the ball
    int r, g, b, a; // colour of the ball

    double vx, vy; // vertical and horizontal velocity of the ball
    double ax, ay; // vertical and horizontal acceleration of the ball
};

#endif
