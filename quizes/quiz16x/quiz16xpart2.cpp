/*
Write a function that takes a std::vector, returns a std::pair containing the indices of the elements with the min and max values in the array.
The documentation for std::pair can be found here. Call the function on the following two vectors:
std::vector v1 { 3, 8, 2, 5, 7, 8, 3 };
std::vector v2 { 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 };

The program should output the following:

With array ( 3, 8, 2, 5, 7, 8, 3 ):
The min element has index 2 and value 2
The max element has index 1 and value 8

With array ( 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 ):
The min element has index 4 and value 1.2
The max element has index 5 and value 8.8
*/

#include <iostream>
#include <utility>
#include <vector>

template <typename T>
void printVector(const std::vector<T>& array, std::pair<int, int> minMax) {
    std::cout << "With array ( ";

    for (int i{ 0 }; i < std::size(array) - 1; i++) {
        std::cout << array.at(i) << ", ";
    }

    std::cout << array.back() << " )" << std::endl;

    std::cout << "The min element has index " << minMax.first << " and value " << array.at(minMax.first) << std::endl;
    std::cout << "The max element has index " << minMax.second << " and value " << array.at(minMax.second) << '\n' << std::endl;
}

template <typename T>
std::pair<int, int> getMinMax(const std::vector<T>& array) {
    std::pair<double, double> rValue{};

    int max{ 0 };
    int min{ 0 };

    bool foundMax{ false };
    bool foundMin{ false };
    
    for (int i{ 0 }; i < std::size(array); i++) {
        if (array.at(i) > max) {
            max = i;
        }
        if (array.at(i) < min) {
            min = i;
        }
    }

    rValue.first = min;
    rValue.second = max;

    return rValue;

}


int main()
{
    std::vector v1{ 3, 8, 2, 5, 7, 8, 3 };
    std::vector v2{ 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 };

    std::pair<int, int> v1MinMax{ getMinMax(v1) };
    std::pair<int, int> v2MinMax{ getMinMax(v2) };

    printVector(v1, v1MinMax);
    printVector(v2, v2MinMax);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
