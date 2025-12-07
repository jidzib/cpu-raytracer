#include "Sphere.h"
#include <cmath>

Sphere::Sphere(Vec3 c, double r, Vec3 color)
{
	center = c;
	radius = r;
	albedo = color;
}

std::optional<double> Sphere::intersect(Ray r)
{
	double a = r.direction.dot(r.direction);
	double b = 2 * r.direction.dot(r.origin - center);
	double c = (r.origin - center).dot(r.origin - center) - radius * radius;
	double discriminant = b * b - 4 * a * c;

	if (discriminant < 0)
	{
		return std::nullopt;
	}
	else
	{
		double t1 = (-b - std::sqrt(discriminant)) / (2 * a);
		double t2 = (-b + std::sqrt(discriminant)) / (2 * a);
		if (t1 > 0) return t1;
		if (t2 > 0) return t2;
	}
	return std::nullopt;
}