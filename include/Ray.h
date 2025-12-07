#ifndef RAY_CLASS
#define RAY_CLASS
#include "Vec3.h"
class Ray
{
	public:
		Vec3 origin;
		Vec3 direction;
		Ray();
		Ray(Vec3 orig, Vec3 dir);
		Vec3 at(double t);

};

#endif

