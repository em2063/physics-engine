#ifndef MANNEQUIN_H
#define MANNEQUIN_H

#include <SDL.h>
#include <vector>

class Mannequin
{
public:
    Mannequin(int startX, int startY);                        // Init mannequin at position (X, Y)
    void renderMannequin(SDL_Renderer *renderer);             // make mannequin visible on the screen
    void moveBodyPart(int partIndex, int deltaX, int deltaY); // Allows body parts on mannequin to be manually moved by user
    // TODO - add more functions such as resetting position of mannequin and perhaps autonomous movement based on goal

private:
    std::vector<RigidBody> bodyParts;
    std::vector <
}