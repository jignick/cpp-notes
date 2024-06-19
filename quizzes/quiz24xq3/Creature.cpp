#include <iostream>
#include <string>
#include <string_view>
#include "Creature.h"


    std::string_view Creature::getName() { return this->m_name; }
    char Creature::getSymbol() { return this->m_symbol; }
    int Creature::getHealth() { return this->m_hp; }
    int Creature::getAdamage() { return this->m_adamage; }
    int Creature::getGold() { return this->m_gold; }

    Creature::Creature(std::string_view name, char symbol, int hp, int adamage, int gold)
        :m_name{ name }
        , m_symbol{ symbol }
        , m_hp{ hp }
        , m_adamage(adamage)
        , m_gold(gold)
    {
    }
    void Creature::reduceHealth(int damage) { this->m_hp -= damage; }
    bool Creature::isDead() { return m_hp <= 0; }

    void Creature::addGold(int gold) { m_gold += gold; }
