#ifndef EFFECTOR_H_INCLUDED
#define EFFECTOR_H_INCLUDED

#include "Environnement.h"

class Effector {
	Environnement environnement;
public :
	Effector(Environnement env) : environnement(env) {};
};


#endif // EFFECTOR_H_INCLUDED
