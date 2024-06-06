#include <iostream>
/*
1)You are running a website, and you are trying to calculate your advertising revenue. 
Write a program that allows you to enter 3 pieces of data:

-How many ads were watched.
-What percentage of users clicked on an ad.
-The average earnings per clicked ad.

Store those 3 values in a struct. 
Pass that struct to another function that prints each of the values.
The print function should also print how much you made for that day (multiply the 3 fields together).
*/

/*
2)Create a struct to hold a fraction. The struct should have an integer numerator and an integer denominator member.
Write a function to read in a Fraction from the user, and use it to read-in two fraction objects. 
Write another function to multiply two Fractions together and return the result as a Fraction (you don’t need to reduce the fraction).
Write another function that prints a fraction.
*/
struct Stats {
    int adsWatched{};
    int percentClick{};
    double avgEarnings{};
};
//1
Stats stats_init() {
    Stats temp{};
    std::cout << "Give me the ads watched: \n";
    std::cin >> temp.adsWatched;

    std::cout << "Give me the percent of users that clicked on the ads: \n";
    std::cin >> temp.percentClick;

    std::cout << "Give me the average earnings: \n";
    std::cin >> temp.avgEarnings;

    return temp;
}
//1
void printEarnings(Stats stats) {
    std::cout << "Money earned: " << stats.adsWatched * stats.percentClick * stats.avgEarnings << std::endl;
}

//2
struct Fraction {
    int numerator{};
    int denominator{};
};

//2
Fraction fraction_init() {
    Fraction temp;

    std::cout << "Give me the numerator: \n";
    std::cin >> temp.numerator;

    std::cout << "Give me the denominator: \n";
    std::cin >> temp.denominator;

    return temp;
}

//2
Fraction fraction_mul(Fraction one, Fraction two) {
    Fraction temp{};
    temp.numerator = one.numerator * two.numerator;
    temp.denominator = one.denominator * two.denominator;

    return temp;
}

//2
void fraction_print(Fraction fraction) {
    std::cout << fraction.numerator << "/" << fraction.denominator << std::endl;
}
int main()
{
    //1
    Stats stats{ stats_init()};
    printEarnings(stats);

    //2
    Fraction first{ fraction_init() };
    Fraction second{ fraction_init() };
    Fraction sum{ fraction_mul(first, second) };

    fraction_print(sum);
}