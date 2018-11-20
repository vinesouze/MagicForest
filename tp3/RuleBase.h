#ifndef RULEBASE_H_INCLUDED
#define RULEBASE_H_INCLUDED

#include <vector>
#include "KnowledgeBase.h"

using namespace std;

enum Premisse {has_excrement,  has_not_excrement, has_portal, has_monster, is_windy, is_not_windy, is_not_visited};
enum Conclusion {monster_risk, exit_found, visited, hole_risk, no_monster, no_hole};

struct Rule {
    Premisse premisse;
    Conclusion conclusion;
    Rule(Premisse pre, Conclusion concl) : premisse(pre), conclusion(concl) {}
};

class RuleBase {
    vector<Rule> rules_base;
    KnowledgeBase* knowledge_base;

public:
    RuleBase();
    bool Premisses(Premisse pre);
    void Conclusions(Conclusion concl);
    vector<Rule> get_rulesBase();
};


#endif // RULEBASE_H_INCLUDED
