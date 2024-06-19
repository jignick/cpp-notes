#include "Potion.h"
#include "Random.h"
std::string_view Potion::getName(){
	switch (m_type) {
	case Potion::health:
		return "health potion";
	case Potion::poison:
		return "poison potion";
	case Potion::strength:
		return "strenght potion";;
	default:
		return "??";
	}
}

std::string_view Potion::getSizeName() {
	switch (m_type) {
	case Potion::small:
		return "small";
	case Potion::medium:
		return "medium";
	case Potion::large:
		return "large";;
	default:
		return "??";
	}
}


Potion::Potion(Potion::Type type, Potion::Size size) 
	: m_type{type}
	, m_size{size}
{}

Potion Potion::getRandomPot() {
	return Potion::Potion(static_cast<Potion::Type>(Random::get(0, Potion::max_types - 1))
						, static_cast<Potion::Size>(Random::get(0, Potion::max_sizes - 1)));
}

