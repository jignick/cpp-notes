#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <string>
#include <string_view>

class Creature
{
protected:
    std::string m_name{};
    char m_symbol{};
    int m_hp{};
    int m_adamage{};
    int m_gold{};
public:
    std::string_view getName();
    char getSymbol();
    int getHealth();
    int getAdamage();
    int getGold();

    Creature(std::string_view name, char symbol, int hp, int adamage, int gold);

    void reduceHealth(int damage);
    bool isDead();

    void addGold(int gold);
};

#endif