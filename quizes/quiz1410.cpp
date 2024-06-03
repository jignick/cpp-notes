/*
Write a class named Ball. Ball should have two private member variables, one to hold a color, and one to hold a radius. 
Also write a function to print out the color and radius of the ball.
*/

#include <iostream>
#include <string>
#include <string_view>

class Ball {
public:
    Ball(std::string_view colour, double r) : color {colour}, radius { r }
    {

    }
    const std::string_view& getColor() const{ 
        return this->color;
    }
    const double& getRadius() const{
        return this->radius;
    }
private:
    std::string color{};
    double radius;
};
void print(const Ball& ball) {
    std::cout << "Ball (" << ball.getColor() << ", " << ball.getRadius() << ")\n";
}
int main()
{
    Ball blue{ "blue", 10.0 };
    print(blue);

    Ball red{ "red", 12.0 };
    print(red);

    return 0;
}
