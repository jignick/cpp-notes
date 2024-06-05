#include "point3d.h"
#include "vector3d.h"
#include <iostream>

void Vector3d::print() const{
	std::cout << "Vector(" << m_x << ", " << m_y << ", " << m_z << ")\n";
}

Vector3d::Vector3d(double x, double y, double z)
	:m_x{ x }
	, m_y{ y }
	, m_z{ z }
{

}