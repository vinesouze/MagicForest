#include "Agent.h"

Effector* Agent::getEffector() {
    return effector;
}

Sensor* Agent::getSensor() {
    return sensor;
}

bool Agent::isDead() {
    return dead;
}

void Agent::setDead(bool statut) {
    dead = statut;
}

void Agent::tirer() {
    if (NbTir > 0)
        NbTir--;
}

int Agent::getNbTir() {
    return NbTir;
}
