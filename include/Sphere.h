#ifndef SPHERE_CLASS
#define SPHERE_CLASS
#include "Vec3.h"
#include "Ray.h"
#include <optional>

class Sphere
{
	public:
		Vec3 center;
		double radius;
		Vec3 albedo;
		Sphere(Vec3 c, double r, Vec3 color);
		std::optional<double> intersect(Ray r);
};

#endif

