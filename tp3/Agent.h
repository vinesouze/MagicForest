#ifndef AGENT_H_INCLUDED
#define AGENT_H_INCLUDED

#include "Sensor.h"
#include "Effector.h"

class Sensor;
class Effector;

class Agent {
	Effector* effector;
	Sensor* sensor;
	//vector<vector<Cell> > beliefs;
	int position;
public:
    //Agent();
	Agent(Effector* effect, Sensor* sens) : effector(effect), sensor(sens) {};
	Effector* getEffector();
	Sensor* getSensor();
};


#endif // AGENT_H_INCLUDED
