#include "Effector.h"

void Effector::move(Action name) {
    switch(name) {
        case Action::Up:
           break;
        case Action::Down:
            break;
        case Action::Left:
            break;
        case Action::Right:
            break;
    };
}

void Effector::shoot() {

}

void Effector::exit() {
    Position agent = environnement->getAgentPosition();
    if (environnement->getCell(agent.x,agent.y).getState() == State::Portail)
        environnement->updateForestLevel();
}
