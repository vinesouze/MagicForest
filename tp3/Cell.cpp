#include "Cell.h"

using namespace std;

void Cell::setState(State name) {
	state = name;
}

State Cell::getState() {
	return state;
}

void Cell::setInconnu(bool statut) {
    inconnu = statut;
}

bool Cell::decouverte() {
	if (inconnu)
		return false;
	else return true;
}
