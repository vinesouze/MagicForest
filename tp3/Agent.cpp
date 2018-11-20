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

KnowledgeBase* Agent::getBelief() {
    return beliefs;
}

RuleBase* Agent::getRuleBase() {
    return rule_base;
}

void Agent::update_state() {
    //mise a jour des croyances
    vector<vector<Cell> > foret = sensor->data();
    Position agent = sensor->getPosition();
    int size = getBelief()->getfacts().size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (foret[i][j].decouverte()) {
                beliefs->add_fact(i,j,foret[i][j].getState());
            }
            else {
                beliefs->add_fact(i,j,State::Inconnu);
            }
            if ((agent.x == i) && (agent.y == j))
                beliefs->set_agentPosition(i,j);
        }
    }

    // mise a jour de la base des faits à partir des regles
    for (auto& rule : rule_base->get_rulesBase()) {
        if(getRuleBase()->Premisses(rule.premisse)) {
            getRuleBase()->Conclusions(rule.conclusion);
        }
    };
}
