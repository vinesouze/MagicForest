#include "Sensor.h"

vector<vector<Cell> > Sensor::data() {
	return environnement->getForest();
}

Position Sensor::getPosition() {
    return environnement->getAgentPosition();
}
