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
	bool dead;
	int NbTir;
public:
    //Agent();
	Agent(Effector* effect, Sensor* sens,int shoot) : effector(effect), sensor(sens), NbTir(shoot), dead(false) {
        cout << "Creation d'un agent avec " << NbTir << " tir disponible." << endl << endl;
	};
	Effector* getEffector();
	Sensor* getSensor();
	bool isDead();
	void setDead(bool statut);
	int getNbTir();
	void tirer();
};


#endif // AGENT_H_INCLUDED
