#ifndef AGENT_H_INCLUDED
#define AGENT_H_INCLUDED

#include "Sensor.h"
#include "Effector.h"
#include "KnowledgeBase.h"
#include "RuleBase.h"

class Sensor;
class Effector;
class KnowledgeBase;
class RuleBase;

class Agent {
	Effector* effector;
	Sensor* sensor;
	//vector<vector<Cell> > beliefs;
	bool dead;
	int NbTir;
	KnowledgeBase* beliefs;
	RuleBase* rule_base;
	vector<string> intentions;

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
	void update_state();
	KnowledgeBase* getBelief();
	RuleBase* getRuleBase();
};


#endif // AGENT_H_INCLUDED
