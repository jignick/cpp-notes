// quiz159.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "vector3d.h"
#include "point3d.h"



int main()
{
	Point3d p{ 1.0, 2.0, 3.0 };
	Vector3d v{ 2.0, 2.0, -3.0 };

	p.print();
	p.moveByVector(v);
	p.print();

	return 0;
}