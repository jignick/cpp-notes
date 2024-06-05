#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <cassert>

/*
Create a program-defined enum (inside a namespace) containing the names of the following animals: chicken, dog, cat, elephant, duck, and snake. 
Define an array with an element for each of these animals, and use an initializer list to initialize each element to hold the number of legs that animal has. 
Assert that the array has the correct number of initializers.

Write a main() function that prints the number of legs an elephant has, using the enumerator.
*/
namespace Animals {
    enum type {
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,
        max_animals
    };

    const std::vector legs{ 2, 4, 4, 4, 2, 0 };
}
int main()
{
    assert(Animals::legs.size() == Animals::type::max_animals);

    std::cout << Animals::legs.at(Animals::type::elephant);
        
}
