#ifndef POTION_H
#define POTION_H
#include <string_view>

class Potion
{

public:
	enum Type {
		health,
		strength,
		poison,
		max_types
	};

	enum Size {
		small,
		medium,
		large,
		max_sizes
	};
private:
	Type m_type{};
	Size m_size{};

public:
	Potion(Type type, Size size);

	std::string_view getName();
	std::string_view getSizeName();
	
	Type getType() const { return this->m_type; }
	Size getSize() const { return this->m_size; }

	static Potion getRandomPot();



};

#endif