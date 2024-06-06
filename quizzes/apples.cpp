#include <iostream>
#include <string>

std::string_view getQuantityPhrase(int quantity) {
    if (quantity < 0) {
        return "negative";
    }
    else if (quantity == 0) {
        return "no";
    }
    else if (quantity == 1) {
        return "single";
    }
    else if (quantity == 2) {
        return "a couple";
    }
    else if (quantity == 3) {
        return "a few";
    }
    
    return "many";
 
}

std::string_view getApplesPlural(int applesQuantity) {
    if (applesQuantity == 1) {
        return "apple";
    }

    return "apples";
 
}

int main() {
    constexpr int maryApples{ 3 };
    std::cout << "Mary has " << getQuantityPhrase(maryApples) << ' ' << getApplesPlural(maryApples) << ".\n";

    std::cout << "How many apples do you have? ";
    int numApples{};
    std::cin >> numApples;

    std::cout << "You have " << getQuantityPhrase(numApples) << ' ' << getApplesPlural(numApples) << ".\n";

    return 0;
}