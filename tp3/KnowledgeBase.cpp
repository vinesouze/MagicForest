#include "KnowledgeBase.h"

KnowledgeBase::KnowledgeBase() {
    size = 3;
    for (int i = 0; i < size; i++) {
		vector<Fact>* line = new vector<Fact>;
        for (int j = 0; j < size; j++) {
            Fact fact;
            fact.x = i;
            fact.y = j;
            fact.statut = State::Inconnu;
        }
        facts.push_back(*line);
    }
}

bool KnowledgeBase::fact_in_position(int i, int j, State statut) {
    if (facts[i][j].statut != statut)
        return true;
    else return false;
}

void KnowledgeBase::add_fact(int i, int j, State statut) {
    facts[i][j].statut == statut;
}

void KnowledgeBase::remove_fact(int i, int j, State statut) {
    facts[i][j].statut == NULL;
}

vector<vector<Fact> > KnowledgeBase::getfacts() {
    return facts;
}

Position KnowledgeBase::get_agentPosition() {
    return agentPosition;
}

void KnowledgeBase::set_agentPosition(int x, int y) {
    agentPosition.x = x;
    agentPosition.y = y;
}
