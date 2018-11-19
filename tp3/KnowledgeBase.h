#ifndef KNOWLEDGEBASE_H_INCLUDED
#define KNOWLEDGEBASE_H_INCLUDED

#include "Environnement.h"

struct Fact {
    int x;
    int y;
    State statut;
};

class KnowledgeBase {
    vector<vector<Fact> > facts;
    int size;

public:
    KnowledgeBase();
    bool fact_in_position(int x, int y);
    void add_fact(int x, int y, State statut);
    void remove_fact(int x, int y, State statut);
};

#endif // KNOWLEDGEBASE_H_INCLUDED
