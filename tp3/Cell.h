#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum State {Vent, Hole, Crotte, Monster, Vide, Portail, Inconnu};

class Cell {
	State state;
	bool inconnu;
public:
	void setState(State name);
	State getState();
	bool decouverte();
	void setInconnu(bool statut);
};



#endif // CELL_H_INCLUDED
