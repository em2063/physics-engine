#ifndef BALL_H
#define BALL_H

#include <SDL.h>

class Ball
{
public:
    Ball(int x, int y, int radius, int r, int g, int b, int a);

    void renderBall(SDL_Renderer *renderer) const; // render the ball

private:
    int x, y;       // 2D position of the ball
    int radius;     // radius of the ball
    int r, g, b, a; // colour of the ball
};

#endif
