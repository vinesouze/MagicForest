#include <iostream>

#include "Environnement.h"

using namespace std;

int main()
{
    Environnement* foret = new Environnement();
    foret->Display();
    delete foret;
}
