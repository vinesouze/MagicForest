#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

enum State {Vent, Crevasse, Crotte, Monstre, Vide, Inconnu};

class Cell {
	State state;
public:
	Cell(State name) : state(name) {};
	void setState(State name);
	State getState();
};



#endif // CELL_H_INCLUDED
