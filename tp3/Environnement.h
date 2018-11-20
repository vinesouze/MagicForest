#ifndef ENVIRONNEMENT_H_INCLUDED
#define ENVIRONNEMENT_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include "Cell.h"
#include "Agent.h"
#include "Position.h"

using namespace std;

class Agent;

class Environnement {
    Position agentPosition;
    vector<vector<Cell> > forest;
    int level;
public:
    Environnement();
    void updateForestLevel();
    void generateForest();
	void addState(int i, int j, int level, State state);
	void Display();
	Cell& getCell(int i, int j);
	vector<vector<Cell> > getForest();
	Position getAgentPosition();
	void setAgentPosition(Position pos);
};


#endif // ENVIRONNEMENT_H_INCLUDED
