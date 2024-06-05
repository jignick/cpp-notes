/*
a) First, let’s create an scoped enumeration of monster types named MonsterType. 
Include the following monster types: Dragon, Goblin, Ogre, Orc, Skeleton, Troll, Vampire, and Zombie.
Add an additional maxMonsterTypes enumerator so we can count how many enumerators there are.

b) Now, let’s create our Monster class. 
Our Monster will have 4 attributes (member variables): a type (MonsterType), a name (std::string), a roar (std::string) and the number of hit points (int).

c)enum class MonsterType is specific to Monster, so make MonsterType a nested unscoped enum inside Monster and rename it to Type.
d)Create a constructor that allows you to initialize all of the member variables.

e) Now we want to be able to print our monster so we can validate it’s correct. Write two functions: 
One called getTypeString() that returns the monster’s type as a string, 
and one called print() that matches the output in the sample program below.

f) Now we can create a random monster generator.
Let’s consider how our MonsterGenerator will work. 
Ideally, we’ll ask it to give us a Monster, and it will create a random one for us. 
Because MonsterGenerator doesn’t have any state, this is a good candidate for a namespace.

Create a MonsterGenerator namespace. 
Create function within named generate().
This should return a Monster. 
For now, make it return Monster{ Monster::skeleton, "Bones", "*rattle*", 4};

g) Add two more functions to the MonsterGenerator namespace.
getName(int) will take a number between 0 and 5 (inclusive) and return a name of your choice.
getRoar(int) will also take a number between 0 and 5 (inclusive) and return a roar of your choice.
Also update your generate() function to call getName(0) and getRoar(0).


h) Now we’ll randomize our generated monster. Grab the “Random.h” code from 8.15 -- Global random numbers (Random.h) and save it as Random.h. 
Then use Random::get() to generate a random monster type, random name, random roar, and random hit points (between 1 and 100).
*/

#include <iostream>
#include <string>
#include <string_view>
#include "random.h"


class Monster {
public:
    enum Type {
        dragon,
        goblin,
        ogre,
        orc,
        skeleton,
        troll,
        vampire,
        zombie
    };
    Monster(Type type, std::string_view name, std::string_view roar, int hp)
        :m_type{ type }
        , m_name{ name }
        , m_roar{ roar }
        , m_hp{ hp } 
    {

    }

    std::string_view getTypeString(){
        switch (this->m_type) {
        case dragon:
            return "dragon";
        case goblin:
            return "goblin";
        case ogre:
            return "ogre";
        case orc:
            return "orc";
        case skeleton:
            return "skeleton";
        case troll:
            return "troll";
        case vampire:
            return "vampire";
        case zombie:
            return "zombie";
        default:
            return "??";
        }
    }

    void print() {
        std::cout << this->m_name << " the " << this->getTypeString() << " has " << this->m_hp << " hit points and says " << this->m_roar << std::endl;
    }

private:
    Type m_type{};
    std::string m_name{};
    std::string m_roar{};
    int m_hp{};
};

namespace MonsterGenerator {


    std::string_view getName(int x) {
        switch (x) {
        case 0:
            return "Frankenstein";
        case 1:
            return "Mucklops";
        case 2:
            return "Wisplisk";
        case 3:
            return "Ewwloo";
        case 4:
            return "Spiritthing";
        case 5:
            return "Bloodling";
        default:
            return "???";
        }
    }

    std::string_view getRoar(int x) {
        switch (x) {
        case 0:
            return "wewe";
        case 1:
            return "sasa";
        case 2:
            return "hehe";
        case 3:
            return "hihi";
        case 4:
            return "koko";
        case 5:
            return "riri";
        default:
            return "???";
        }
    }

    Monster generate() {
        return Monster{ Monster::skeleton, getName(Random::get(0, 5)), getRoar(Random::get(0, 5)), 4 };
    }
}

int main()
{
    Monster skeleton{ Monster::skeleton, "Bones", "*rattle*", 4 };
    skeleton.print();

    Monster vampire{ Monster::vampire, "Nibblez", "*hiss*", 0 };
    vampire.print();

    Monster m{ MonsterGenerator::generate() };
    m.print();

    return 0;
}
