

#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <cassert>

/*
In this quiz, implement the game as follows:

Numbers divisible by only 3 should print “fizz”.
Numbers divisible by only 5 should print “buzz”.
Numbers divisible by only 7 should print “pop”.
Numbers divisible by only 11 should print “bang”.
Numbers divisible by only 13 should print “jazz”.
Numbers divisible by only 17 should print “pow”.
Numbers divisible by only 19 should print “boom”.
Numbers divisible by more than one of the above should print each of the words associated with its divisors.
Numbers not divisible by any of the above should just print the number.
*/
void fizzbuzz(int x) {

    using namespace std::literals::string_view_literals;

    const std::vector<int> divisors{ 3, 5, 7, 11, 13, 17, 19 };
    const std::vector<std::string_view> words{ "fizz"sv, "buzz"sv, "pop"sv, "bang"sv, "jazz"sv, "pow"sv, "boom"sv };
    

    assert(divisors.size() == words.size());

    for (int i{ 0 }; i < x; i++) {

        bool printed{ false };

        for (int k{ 0 }; k < divisors.size(); k++) {
            if (i % divisors.at(k) == 0) {
                std::cout << words.at(k);
                printed = true;
            }
        }

        if (!printed) {
            std::cout << i;
        }

        std::cout << '\n';
    }
}

int main()
{


    
    fizzbuzz(150);

    


}
