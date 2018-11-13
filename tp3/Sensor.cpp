#include "Sensor.h"

vector<vector<Cell> > Sensor::data() {
	return environnement->getForest();
}

Position Sensor::getPosition() {
    return environnement->getAgentPosition();
}

bool Sensor::is_shinny() {
    Position actuel = getPosition();
    if (environnement->getCell(actuel.x,actuel.y).getState()== State::Portail)
        return true;
    return false;
}

bool Sensor::is_windy() {
    Position actuel = getPosition();
    if (environnement->getCell(actuel.x,actuel.y).getState()== State::Vent)
        return true;
    return false;
}

bool Sensor::is_stinky() {
    Position actuel = getPosition();
    if (environnement->getCell(actuel.x,actuel.y).getState()== State::Crotte)
        return true;
    return false;
}
