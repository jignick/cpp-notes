/*
Define a std::vector with the following names: “Alex”, “Betty”, “Caroline”, “Dave”, “Emily”, “Fred”, “Greg”, and “Holly”. Ask the user to enter a name. 
Use a range-based for loop to see if the name the user entered is in the array.

Modify your solution to quiz 1. In this version, create a function template (not a normal function) called isValueInArray() 
that takes two parameters: a std::vector, and a value. The function should return true if the value is in the array, and false otherwise. 
Call the function from main() and pass it the array of names and the name the user entered.
*/

#include <iostream>
#include <vector>
#include <string>
#include <string_view>

template <typename T>
bool isValueInArray(const std::vector<T>& v, const T& value) {
    for (const auto& name : v) {
        if (name.compare(value)) {
            return true;
        }
    }

    return false;
}
int main()
{
    using namespace std::literals;

    std::vector<std::string_view> names{ "Alex"sv, "Betty"sv, "Caroline"sv, "Dave"sv, "Emily"sv, "Fred"sv, "Greg"sv, "Holly"sv };

    std::string a{};

    std::cout << "Give me a name: ";
    std::cin >> a;

    if (isValueInArray<std::string_view>(names, a)) {
        std::cout << "Found.";
    }
    else {
        std::cout << "Not found.";
    }

}

