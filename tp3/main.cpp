#include <iostream>

#include "Environnement.h"
#include "Agent.h"

using namespace std;

class Agent;

void commande() {
    cout << "Quelle action souhaitez vous faire ?" << endl;
    cout << "Z - Haut" << endl;
    cout << "Q - Gauche" << endl;
    cout << "S - Bas" << endl;
    cout << "Z - Droite" << endl;
    cout << "E - Exit" << endl;
    cout << "T - Shoot" << endl << endl;
}

Action convertirAction(char touche) {
    Action action;
    switch(touche) {
        case 'z':
            action = Action::Up;
            break;
        case 'q':
            action = Action::Left;
            break;
        case 's':
            action = Action::Down;
            break;
        case 'd':
            action = Action::Right;
            break;
        case 'e':
            action = Action::Exit;
            break;
        case 't':
            action = Action::Shoot;
            break;
    };
    return action;
}

int main()
{
    char touche;
    Environnement* foret = new Environnement();
    Sensor* sensor = new Sensor(foret);
    Effector* effector = new Effector(foret);
    Agent* agent = new Agent(effector, sensor,3);

    while(!agent->isDead()) {
        foret->Display();
        if (agent->getSensor()->is_shinny())
            cout << "la case est brillante, il s'agit surement d'un portail" << endl;
        if (agent->getSensor()->is_windy())
            cout << "la case est venteuse, il y a une crevasse a cote de cette case" << endl;
        if (agent->getSensor()->is_stinky())
            cout << "la case est puante, il y  a un monstre a cote de cette case" << endl;
        if (foret->getCell(foret->getAgentPosition().x,foret->getAgentPosition().y).getState() == State::Monster)
            cout << "Il y a un monstre, tuez le !" << endl;
        cout << endl;
        commande();
        cin >> touche;
        Action action = convertirAction(touche);

        // si case monstre et pas tirer
        if ((foret->getCell(foret->getAgentPosition().x,foret->getAgentPosition().y).getState()== State::Monster) && action != Action::Shoot) {
            agent->setDead(true);
            break;
        }

        agent->getEffector()->doAction(action);

        // si case monstre et plus de tir alors mort
        if ((foret->getCell(foret->getAgentPosition().x,foret->getAgentPosition().y).getState()== State::Monster) && agent->getNbTir()==0) {
            agent->setDead(true);
        }

        if (action == Action::Shoot)
            agent->tirer();

        // agent tombe dans un trou
        if (foret->getCell(foret->getAgentPosition().x,foret->getAgentPosition().y).getState()== State::Hole) {
            agent->setDead(true);
        }
    }

    cout << endl << " ### GAME OVER ### " << endl;
    delete foret;
}
