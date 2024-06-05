#include <iostream>
#include "point3d.h"
#include "vector3d.h"

void Point3d::print() const {
	std::cout << "Point(" << m_x << ", " << m_y << ", " << m_z << ")\n";
}

void Point3d::moveByVector(const Vector3d& v) {
	std::cout << "Point moved to x:" << this->m_x + v.m_x << " y: " << this->m_y + v.m_y << " z: " << this->m_z + v.m_z << std::endl;
	this->m_x += v.m_x;
	this->m_y += v.m_y;
	this->m_z += v.m_z;
}

Point3d::Point3d(double x, double y, double z)
				:m_x{ x }
				,m_y{y}
				,m_z{z}
{
}