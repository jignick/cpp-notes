/*
Write a class template named Triad that has 3 private data members with independent type template parameters. 
The class should have a constructor, access functions, and a print() member function that is defined outside the class.
*/

#include <iostream>
#include <string>
#include <string_view>
template <typename T, typename U, typename Z>
class Triad {
private: 
    T m_first{};
    U m_second{};
    Z m_third{};
public:
    Triad(T first, U second, Z third)
        :m_first{ first }
        , m_second { second }
        , m_third {third}
    {

    }

    constexpr T& getFirst() const { return this->m_first; }
    constexpr U& getSecond() const { return this->m_second; }
    constexpr Z& getThird() const { return this->m_third; }

    void print() const;
};

template <typename T, typename U, typename Z>
void Triad<T, U, Z>::print() const{
    std::cout << "First: " << this->getFirst() << "\nSecond: " << this->getSecond() << "\nThird: " << this->getThird() << std::endl;
}
int main()
{
    Triad<int, int, int> t1{ 1, 2, 3 };
    t1.print();
    std::cout << '\n';
    std::cout << t1.getFirst() << '\n';

    using namespace std::literals::string_literals;
    const Triad t2{ 1, 2.3, "Hello"s };
    t2.print();
    std::cout << '\n';

    return 0;
}
