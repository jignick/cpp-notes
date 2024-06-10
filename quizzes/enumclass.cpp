#include <iostream>
#include <string_view>
#include <string>
/*
Define an enum class named Animal that contains the following animals: 
pig, chicken, goat, cat, dog, duck. Write a function named getAnimalName() that takes an Animal parameter and uses a switch statement 
to return the name for that animal as a std::string_view (or std::string if you’re using C++14). 
Write another function named printNumberOfLegs() that uses a switch statement to print the number of legs each animal walks on. 
Make sure both functions have a default case that prints an error message. 
Call printNumberOfLegs() from main() with a cat and a chicken.
*/
enum class Animal {
    chicken,
    goat,
    cat,
    dog,
    duck,
};

std::string_view getAnimalName(Animal animal) {
    using enum Animal;

    switch (animal) {
    case chicken:
        return "chicken";
    case goat:
        return "goat";
    case cat:
        return "cat";
    case dog:
        return "dog";
    case duck:
        return "duck";
    default:
        return "No animal match.";
    }

}

void printNumberOfLegs(Animal animal) {
    using enum Animal;

    switch (animal) {
    case chicken:
        std::cout << "Chicken walks on 2 legs\n";
        break;
    case goat:
        std::cout << "Goat walks on 4 legs\n";
        break;
    case cat:
        std::cout << "Cat walks on 4 legs\n";
        break;
    case dog:
        std::cout << "Dog walks on 4 legs\n";
        break;
    case duck:
        std::cout << "Duck walks on 2 legs\n";
        break;
    default:
        std::cout << "No animal match.\n";
        break;
    }
}

int main()
{
    Animal goat{ Animal::goat };
    Animal chicken{ Animal::chicken };
    Animal cat{ Animal::cat };
    std::cout << "animal: " << getAnimalName(goat) << "\n";
    printNumberOfLegs(chicken);
    printNumberOfLegs(cat);
}
