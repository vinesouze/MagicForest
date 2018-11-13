#ifndef SENSOR_H_INCLUDED
#define SENSOR_H_INCLUDED

#include "Environnement.h"

class Environnement;
struct Position;

class Sensor {
	Environnement* environnement;
public:
    Sensor(Environnement* env) : environnement(env) {};
    vector<vector<Cell> > data();
    Position getPosition();
    bool is_shinny();
    bool is_windy();
    bool is_stinky();
};

#endif // SENSOR_H_INCLUDED
