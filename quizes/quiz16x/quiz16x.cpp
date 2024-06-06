#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <string_view>

/*
Let’s say you’re writing a game where the player can hold 3 types of items: health potions, torches, and arrows.

> Step #1

Define an unscoped enum in a namespace to identify the different types of items. 
Define an std::vector to store the number of each item type the player is carrying. 
The player should start with 1 health potion, 5 torches, and 10 arrows. Assert to make sure the array has the correct number of initializers.

Hint: Define a count enumerator and use it inside the assert.

The program should output the following: You have 16 total items
*/
namespace Item {
    enum type {
        health_potion,
        torch,
        arrow,
        max_items
    };

    std::vector<int> numberOfItem { 1, 5, 10 };


}

int countItems(const std::vector<int>& items) {
    int sum{};
    for (int x : items) {
        sum += x;
    }

    return sum;
}

/*
> Step #2

Modify your program from the prior step so it now outputs :

You have 1 health potion
You have 5 torches
You have 10 arrows
You have 16 total items
*/

std::string_view getName(Item::type type) {
    switch (type) {
    case Item::health_potion:
        return "health potion";
    case Item::arrow:
        return "arrow";
    case Item::torch:
        return "torch";
    default:
        return "??";
    }
}

std::string_view getNamePlural(Item::type type) {
    switch (type) {
    case Item::health_potion:
        return "health potions";
    case Item::arrow:
        return "arrows";
    case Item::torch:
        return "torches";
    default:
        return "??";
    }
}

void printItems(const std::vector<int>& items) {
    int i{ Item::health_potion };

    for (int x : items) {
        if (x == 1) {
            std::cout << "You have " << x << " " << getName(static_cast<Item::type>(i)) << std::endl;
        }
        else {
            std::cout << "You have " << x << " " << getNamePlural(static_cast<Item::type>(i)) << std::endl;
        }
        

        i++;
    }

    std::cout << "You have " << countItems(Item::numberOfItem) << " items" << std::endl;

}
int main()
{
    assert(static_cast<int>(std::size(Item::numberOfItem)) == Item::type::max_items);

    printItems(Item::numberOfItem);

}
