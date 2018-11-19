#include "KnowledgeBase.h"

KnowledgeBase::KnowledgeBase() {
    size = 3;
    for (int i = 0; i < size; i++) {
		vector<Fact>* line = new vector<Fact>;
        for (int j = 0; j < size; j++) {
            Fact fact;
            fact.x = i;
            fact.y = j;
        }
        facts.push_back(*line);
    }
}

bool KnowledgeBase::fact_in_position(int i, int j) {
    if (facts[i][j].statut != NULL)
        return true;
    else return false;
}

void KnowledgeBase::add_fact(int i, int j, State statut) {
    facts[i][j].statut == statut;
}

void KnowledgeBase::remove_fact(int i, int j, State statut) {
    facts[i][j].statut == NULL;
}
