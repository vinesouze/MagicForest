#include "Cell.h"

void Cell::setState(State name) {
	state = name;
}

State Cell::getState() {
	return state;
}
