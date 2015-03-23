#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <vector>

class Shape
{
private:
    std::string shapeName;
    std::vector<Shape> killers;
    std::vector<Shape> victims;

public:
    Shape(){}
    Shape(std::string shapeName);
    ~Shape(){}

    void SetName(std::string shapeName);
    std::string GetName(){return shapeName;}

    bool IsInitialized();

    void AddKiller(Shape killer);
    std::vector<Shape> GetKillers(){ return killers;}

    void AddVictim(Shape victim);
    std::vector<Shape> GetVictims(){ return victims;}

//    void OutShape();
};

#endif // SHAPE_H
