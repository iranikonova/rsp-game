#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include<vector>
#include "shape.h"

using namespace Levels;

class GameEngine
{
public:
    std::vector<Shape> GameShapes;
    Shape UserShape;
    Shape ProgramShape;

    GameEngine();
    ~GameEngine();

    Shape RandomShape();

    bool UserShapeChoose(std::string shapeName);
    void ProgramShapeChoose(int level); //TODO: change int to enum Level

    int GameResult();
};

#endif // GAMEENGINE_H
