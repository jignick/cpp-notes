#include "Player.h"
#include <string_view>

Player::Player(std::string_view name) : Creature::Creature(name, '@', 10, 1, 0) {

}

void Player::levelUp() {
	this->m_level++;
	this->m_adamage++;
}
int Player::getLevel() { return this->m_level; }
bool Player::hasWon() { return this->m_level >= 20; }

void Player::drinkPotion(Potion pot) {
	char choice{};

	do {
		std::cout << "Do you want to drink the potion? y/n:";
		std::cin >> choice;
	} while (choice != 'y' && choice != 'n');

	if (choice == 'y') {
		std::cout << "You have found a " << pot.getSizeName() << " " << pot.getName() << std::endl;

		switch (pot.getType()) {
		case Potion::health:
			if (pot.getSize() == Potion::small || pot.getSize() == Potion::large) {
				this->m_hp += 2;
				std::cout << "Your hp is now: " << this->m_hp << std::endl;
			}
			if (pot.getSize() == Potion::large) {
				this->m_hp += 5;
				std::cout << "Your hp is now: " << this->m_hp << std::endl;
			}
			break;
		case Potion::strength:
			this->m_adamage += 1;
			std::cout << "Your attack damage is now: " << this->m_adamage << std::endl;
			break;
		case Potion::poison:
			this->m_hp -= 1;
			std::cout << "Your hp is now: " << this->m_hp << std::endl;
			break;
		}
	}
	else {
		std::cout << "You lost the potion." << std::endl;
	}

}