#include <iostream>

#include "Environnement.h"
#include "Agent.h"

using namespace std;

class Agent;

int main()
{
    Environnement* foret = new Environnement();
    Sensor* sensor = new Sensor(foret);
    Effector* effector = new Effector(foret);
    Agent* agent = new Agent(effector, sensor);
    foret->Display();
    agent->getEffector()->exit();
    foret->updateForestLevel();
    foret->Display();
    delete foret;
}
