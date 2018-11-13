#include "Effector.h"

void Effector::doAction(Action name) {
    Position before = environnement->getAgentPosition();
    Position after = before;
    switch(name) {
        case Action::Up:
            after.x = (before.x)-1;
            environnement->setAgentPosition(after);
            environnement->getCell(after.x,after.y).setInconnu(false);
            break;
        case Action::Down:
            after.x = (before.x)+1;
            environnement->setAgentPosition(after);
            environnement->getCell(after.x,after.y).setInconnu(false);
            break;
        case Action::Left:
            after.y = (before.y)-1;
            environnement->setAgentPosition(after);
            environnement->getCell(after.x,after.y).setInconnu(false);
            break;
        case Action::Right:
            after.y = (before.y)+1;
            environnement->setAgentPosition(after);
            environnement->getCell(after.x,after.y).setInconnu(false);
            break;
        case Action::Shoot:
            environnement->getCell(after.x,after.y).setState(State::Vide);
            break;
        case Action::Exit:
            if (environnement->getCell(before.x,before.y).getState() == State::Portail)
                environnement->updateForestLevel();
            break;
    };
}
