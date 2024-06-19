#ifndef PLAYER_H
#define PLAYER_H
#include "Creature.h"
#include "Potion.h"
class Player : public Creature
{
private:
	int m_level{1};
public:
	Player(std::string_view name);

	void levelUp();
	int getLevel();
	bool hasWon();

	void drinkPotion(Potion pot);
};

#endif