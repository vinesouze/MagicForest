#include "RuleBase.h"

RuleBase::RuleBase() {
    rules_base.push_back(Rule(has_excrement,monster_risk));
    rules_base.push_back(Rule(has_not_excrement,no_monster));
    rules_base.push_back(Rule(has_portal,exit_found));
    rules_base.push_back(Rule(is_not_visited,visited));
    rules_base.push_back(Rule(is_not_windy,no_hole));
    rules_base.push_back(Rule(is_windy,hole_risk));
};

vector<Rule> RuleBase::get_rulesBase() {
    return rules_base;
}

bool RuleBase::Premisses(Premisse pre) {
    Position pos = knowledge_base->get_agentPosition();
    switch(pre) {
        case Premisse::has_excrement:
            if (knowledge_base->fact_in_position(pos.x, pos.y, State::Crotte))
                return true;
            break;
        case Premisse::has_not_excrement:
            if (!knowledge_base->fact_in_position(pos.x, pos.y, State::Crotte))
                return true;
            break;
        case Premisse::has_portal:
            if (knowledge_base->fact_in_position(pos.x, pos.y, State::Portail))
                return true;
            break;
        case Premisse::is_not_visited:
            if (knowledge_base->fact_in_position(pos.x, pos.y, State::Inconnu))
                return true;
            break;
        case Premisse::is_not_windy:
            if (!knowledge_base->fact_in_position(pos.x, pos.y, State::Vent))
                return true;
            break;
        case Premisse::is_windy:
            if (knowledge_base->fact_in_position(pos.x, pos.y, State::Vent))
                return true;
            break;
    };
    return false;
}

void RuleBase::Conclusions(Conclusion concl) {
    Position pos = knowledge_base->get_agentPosition();
    switch(concl) {
        case Conclusion::monster_risk:
            if (knowledge_base->fact_in_position(pos.x, pos.y, State::Crotte))
                return;
            break;
        case Conclusion::exit_found:
            if (!knowledge_base->fact_in_position(pos.x, pos.y, State::Crotte))
                return;
            break;
        case Conclusion::visited:
            if (knowledge_base->fact_in_position(pos.x, pos.y, State::Portail))
                return;
            break;
        case Conclusion::hole_risk:
            if (knowledge_base->fact_in_position(pos.x, pos.y, State::Inconnu))
                return;
            break;
        case Conclusion::no_monster:
            if (!knowledge_base->fact_in_position(pos.x, pos.y, State::Vent))
                return;
            break;
        case Conclusion::no_hole:
            if (knowledge_base->fact_in_position(pos.x, pos.y, State::Vent))
                return;
            break;
    };
}

