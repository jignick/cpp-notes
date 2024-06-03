/*
Write a short program to simulate a ball being dropped off of a tower. 
To start, the user should be asked for the height of the tower in meters. 
Assume normal gravity (9.8 m/s2), and that the ball has no initial velocity 
(the ball is not moving to start). 
Have the program output the height of the ball above the ground after 0, 1, 2, 3, 4, and 5 seconds. 
The ball should not go underneath the ground (height 0).

Use a function to calculate the height of the ball after x seconds. 
The function can calculate how far the ball has fallen after x seconds using the following formula:
distance fallen = gravity_constant * x_seconds^2 / 2
*/

#include <iostream>
double calculateHeight(int second){
    double gravity{ 9.8 };
    double distance_fallen{ gravity * (second * second) / 2 };

    return distance_fallen;
}

void printPosition(int second, double height) {
    std::cout << "At " << second << " seconds, the ball is at height: " << height - calculateHeight(second)
              << " meters.\n";
}
int main()
{
    
    int height;

    std::cout << "Enter the height of the tower: ";
    std::cin >> height;

    printPosition(0, height);
    printPosition(1, height);
    printPosition(2, height);
    printPosition(3, height);
    printPosition(4, height);
}
