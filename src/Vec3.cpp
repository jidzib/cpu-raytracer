#include "Vec3.h"
#include <cmath>
#include "Utilities.h"

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

Vec3 Vec3::operator*(Vec3 other)
{
	return Vec3(x * other.x, y * other.y, z * other.z);
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

Vec3 Vec3::random()
{
	return Vec3(random_double(), random_double(), random_double());
}

Vec3 Vec3::random(double min, double max)
{
	return Vec3(random_double(min, max), random_double(min, max), random_double(min, max));
}

Vec3 Vec3::random_unit_vector()
{
	while (true)
	{
		auto p = Vec3::random(-1, 1);
		auto lensq = p.length_squared();
		if (1e-160 < lensq && lensq <= 1)
			return p / sqrt(lensq);
	}
}
double Vec3::length_squared()
{
	return x * x + y * y + z * z;
}