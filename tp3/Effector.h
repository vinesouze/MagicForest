#ifndef EFFECTOR_H_INCLUDED
#define EFFECTOR_H_INCLUDED

#include "Environnement.h"

class Environnement;
enum Action {Up, Down, Left, Right, Shoot, Exit};

class Effector {
	Environnement* environnement;
public :
	Effector(Environnement* env) : environnement(env) {};
	void move(Action name);
	void shoot();
	void exit();
};


#endif // EFFECTOR_H_INCLUDED
