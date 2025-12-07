#include "Vec3.h"
#include <cmath>

Vec3::Vec3()
{
	x = 0;
	y = 0;
	z = 0;
}
Vec3::Vec3(double nx, double ny, double nz)
{
	x = nx;
	y = ny;
	z = nz;
}

Vec3 Vec3::operator+(Vec3 other)
{
	return Vec3(x + other.x, y + other.y, z + other.z);
}

Vec3 Vec3::operator-(Vec3 other)
{
	return Vec3(x - other.x, y - other.y, z - other.z);
}

Vec3 Vec3::operator*(double scalar)
{
	return Vec3(x * scalar, y * scalar, z * scalar);
}

Vec3 Vec3::operator/(double divider)
{
	return Vec3(x / divider, y / divider, z / divider);
}

double Vec3::dot(Vec3 other)
{
	return x * other.x + y * other.y + z * other.z;
}

Vec3 Vec3::normalized()
{
	double m = std::sqrt(x * x + y * y + z * z);
	if (m == 0) return Vec3(0, 0, 0);
	return Vec3(x / m, y / m, z / m);
}
