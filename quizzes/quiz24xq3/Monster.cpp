#include "Monster.h"

Monster::Monster(Type monstertype) : Creature{ Monster::monsterData[monstertype] } {
}

Monster::Type Monster::getRandomMonster() { return static_cast<Type>(Random::get(0, Type::max_types - 1)); }