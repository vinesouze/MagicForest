#ifndef KNOWLEDGEBASE_H_INCLUDED
#define KNOWLEDGEBASE_H_INCLUDED

#include "Position.h"
#include "Cell.h"

struct Fact {
    int x;
    int y;
    State statut;
};

class KnowledgeBase {
    vector<vector<Fact> > facts;
    int size;
    Position agentPosition;

public:
    KnowledgeBase();
    bool fact_in_position(int x, int y, State Statut);
    void add_fact(int x, int y, State statut);
    void remove_fact(int x, int y, State statut);
    vector<vector<Fact> > getfacts();
    Position get_agentPosition();
    void set_agentPosition(int x, int y);
};

#endif // KNOWLEDGEBASE_H_INCLUDED
