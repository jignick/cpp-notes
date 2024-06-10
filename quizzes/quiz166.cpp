/*
Write a short program that prints the elements of the following vector to the screen using a loop: (std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };)
*/

#include <iostream>
#include <vector>
template <typename T>
void printArray(const std::vector<T>& arr) {
    for (int x : arr) {
        std::cout << x << std::endl;
    }
}

int getInput() {
    int input{};
    
    
    do {
        std::cout << "Give a number from 1 - 9: ";
        std::cin >> input;

        if (!std::cin)
            std::cin.clear();

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (input < 1 || input > 9);
    
    return input;
}

template <typename T>
void searchElement(T& value, const std::vector<T>& arr) {
    for (int i{ 0 }; i < std::size(arr); i++) {
        if (arr.at(i) == value) {
            std::cout << "Element " << value << " was found at: " << i << std::endl;
            return;
        }
    }

    std::cout << "Element was not found.";
}

template <typename T>
T findMax(const std::vector<T>& arr) {
    

    if (std::size(arr) == 0) {
        return T{};
    }

    T max{ arr.at(0) };

    for (int x : arr) {
        if (x > max) {
            max = x;
        }
    }

    return max;
}
int main()
{

    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };
    int a{ 0 };

    a = getInput();

    std::vector data1{ 84, 92, 76, 81, 56 };
    std::cout << findMax(data1) << '\n';

    std::vector data2{ -13.0, -26.7, -105.5, -14.8 };
    std::cout << findMax(data2) << '\n';

    std::vector<int> data3{ };
    std::cout << findMax(data3) << '\n';

    searchElement(a, arr);
    
}
