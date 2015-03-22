#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include<vector>
#include "shape.h"

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
    std::string ProgramShapeChoose(int level); //TODO: change int to enum Level

    int GameResult();
};

#endif // GAMEENGINE_H
