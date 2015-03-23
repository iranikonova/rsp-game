#include "shape.h"
#include <iostream>

Shape::Shape(std::string shapeName)
{
    this->shapeName = shapeName;
}

void Shape::SetName(std::string shapeName)
{
   this->shapeName = shapeName;
}

bool Shape::IsInitialized()
{
    return !shapeName.empty();
}

void Shape::AddKiller(Shape killer)
{
    killers.push_back(killer);
}

void Shape::AddVictim(Shape victim)
{
    victims.push_back(victim);
}

//void Shape::OutShape()
//{
//    std::cout << "Name:" << GetName() << std::endl;
//    std::cout << "Killers:" << std::endl;
//    for (Shape & shape: GetKillers())
//    {
//        std::cout << "-" << shape.GetName() << std::endl;
//    }
//    std::cout << "Victims:" << std::endl;
//    for (Shape & shape: GetVictims())
//    {
//        std::cout << "-" << shape.GetName() << std::endl;
//    }
//}

