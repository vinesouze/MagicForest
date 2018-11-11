#ifndef ENVIRONNEMENT_H_INCLUDED
#define ENVIRONNEMENT_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "Cell.h"

struct Position {
	int x = 0;
	int y = 0;
}

class Environnement {
    Position agentPosition;
    vector<vector<Case> > forest;
    int level;
public:
    Environnement();
    void updateForestLevel();
    void generateForest();
};


#endif // ENVIRONNEMENT_H_INCLUDED
