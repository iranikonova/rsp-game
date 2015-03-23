#include "gameengine.h"
#include <iostream>

GameEngine::GameEngine()
{
    Shape rock("rock");
    Shape paper("paper");
    Shape scissors("scissors");

    rock.AddKiller(paper);
    rock.AddVictim(scissors);

    paper.AddKiller(scissors);
    paper.AddVictim(rock);

    scissors.AddKiller(rock);
    scissors.AddVictim(paper);

    GameShapes.push_back(rock);
    GameShapes.push_back(paper);
    GameShapes.push_back(scissors);
}

GameEngine::~GameEngine()
{

}

bool GameEngine::UserShapeChoose(std::string shapeName)
{
    for (Shape & shape: GameShapes)
    {
        if(shapeName == shape.GetName())
        {
            UserShape = shape;
        }
    }
    return UserShape.IsInitialized();

//    std::cout << std::endl;
//    std::cout << "UserShapeChoose:" << std::endl;
//    UserShape.OutShape();
//    std::cout << std::endl;

}

Shape GameEngine::RandomShape()
{
    int shapeCount = GameShapes.size();
    int randNumber = rand() % shapeCount;

    return GameShapes[randNumber];
}

std::string GameEngine::ProgramShapeChoose(int level)
{

    if(1 == level)
    {
        // User wins with probability 66%

        int randomNumber;
        randomNumber = rand() % 3;
        if(2 != randomNumber)
        {
            int randomVictim = 0;

            std::vector<Shape> victims = UserShape.GetVictims();


            int victimsCount = victims.size();
            if(1 < victimsCount)
            {
                randomVictim = rand() % victimsCount;
            }

            ProgramShape = victims[randomVictim];
        }
        else
        {
            ProgramShape = RandomShape();
        }

    }
    if(2 == level)
    {
        ProgramShape = RandomShape();
    }
    if(3 == level)
    {
        // User looses with probability 66%

        int randomNumber;
        randomNumber = rand() % 3;
        if(2 != randomNumber)
        {
            int randomKiller = 0;

            std::vector<Shape> killers = UserShape.GetKillers();

            int killersCount = killers.size();
            if(1 < killersCount)
            {
                randomKiller = rand() % killersCount;
            }

            ProgramShape = killers[randomKiller];
        }
        else
        {
            ProgramShape = RandomShape();
        }
    }

    return ProgramShape.GetName();
}

int GameEngine::GameResult()
{
    // 0 - Draw, 1 - User, 2 - Program

    for (Shape & shape: UserShape.GetVictims())
    {
        if(shape.GetName() == ProgramShape.GetName())
        {
            return 1;
        }
    }

    for (Shape & shape: UserShape.GetKillers())
    {
        if(shape.GetName() == ProgramShape.GetName())
        {
            return 2;
        }
    }

    return 0;
}

