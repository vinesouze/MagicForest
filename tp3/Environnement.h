#ifndef ENVIRONNEMENT_H_INCLUDED
#define ENVIRONNEMENT_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include "Cell.h"

using namespace std;

struct Position {
	int x = 0;
	int y = 0;
};

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
};


#endif // ENVIRONNEMENT_H_INCLUDED
