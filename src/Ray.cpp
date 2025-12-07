#include "Ray.h"

Ray::Ray()
{
	origin = Vec3(0, 0, 0);
	direction = Vec3(1, 0, 0);
}

Ray::Ray(Vec3 orig, Vec3 dir)
{
	origin = orig;
	direction = dir;
}

Vec3 Ray::at(double t)
{
	return origin + direction * t;
}