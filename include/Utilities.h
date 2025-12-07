#pragma once
#include <cmath>
#include <numbers>
#include <vector>
#include "Ray.h"
#include "Sphere.h"
#include "Vec3.h"

double clamp(double x);

Vec3 ray_color(Ray r, std::vector<Sphere> world, int depth);

inline double degrees_to_radians(double degrees)
{
	return degrees * std::numbers::pi / 180.0;
}

inline double random_double()
{
	// Returns a random real in [0,1).
	return std::rand() / (RAND_MAX + 1.0);
}

inline double random_double(double min, double max)
{
	// Returns a random real in [min,max).
	return min + (max - min) * random_double();
}
