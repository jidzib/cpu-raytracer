#ifndef SPEHRE_CLASS
#define SPHERE_CLASS
#include "Vec3.h"
#include "Ray.h"
#include <optional>

class Sphere
{
	public:
		Vec3 center;
		double radius;
		Sphere(Vec3 c, double r);
		std::optional<double> intersect(Ray r);
};

#endif

