#include "shape.h"

Shape::Shape(std::string shapeName)
{
    this->shapeName = shapeName;
}

Shape::SetName(std::string shapeName)
{
   this->shapeName = shapeName;
}

bool Shape::IsInitialized()
{
    return !shapeName.empty();
}

void Shape::AddKiller(Shape &killer)
{
    killers.push_back(killer);
}

void Shape::AddVictim(Shape &victim)
{
    victims.push_back(victim);
}

