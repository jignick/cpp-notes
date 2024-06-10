/*
Write a class named Ball. Ball should have two private member variables, one to hold a color (default value: black), 
and one to hold a radius (default value: 10.0).
Add 4 constructors, one to handle each case below:
*/

#include <iostream>
#include <string>
#include <string_view>
class Ball {
public:
    Ball(std::string color = "black", double radius = 10.0)
        :m_color{ color }
        , m_radius{ radius }
    {
        std::cout << "Ball (" << this->getColor() << ", " << this->getRadius() << ")\n";
    }
    Ball(double radius) : Ball("black", radius){}

    const std::string_view& getColor() const {
        return m_color;
    }

    const double& getRadius() const {
        return m_radius;
    }
private:
    std::string m_color{};
    double m_radius{};
};
int main()
{
    Ball def{};
    Ball blue{ "blue" };
    Ball twenty{ 20.0 };
    Ball blueTwenty{ "blue", 20.0 };
}

