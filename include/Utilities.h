#ifndef UTILITY_CLASS
#define UTILITY_CLASS
#include <cmath>
#include <numbers>
#include <vector>

Vec3 ray_color(Ray r, std::vector<Sphere> world)
{
	double closest_t = std::numeric_limits<double>::infinity();
	Sphere* hitSphere = nullptr;

	for (auto& s : world)
	{
		auto t = s.intersect(r);
		if (!t.has_value()) continue;
		if (*t > 0.001 && *t < closest_t)
		{
			closest_t = *t;
			hitSphere = &s;
		}
	}
	if (hitSphere)
	{
		Vec3 hit = r.at(closest_t);
		Vec3 normal = (hit - hitSphere->center).normalized();
		return Vec3(normal.x+1, normal.y+1, normal.z+1) * 0.5;
	}
	Vec3 unit_dir = r.direction.normalized();
	double a = 0.5 * (unit_dir.y + 1.0);
	return (Vec3(1, 1, 1) * (1 - a) + Vec3(0.5, 0.7, 1.0) * (a));
}

inline double degrees_to_radians(double degrees) {
	return degrees * std::numbers::pi / 180.0;
}

inline double random_double() {
	// Returns a random real in [0,1).
	return std::rand() / (RAND_MAX + 1.0);
}

inline double random_double(double min, double max) {
	// Returns a random real in [min,max).
	return min + (max - min) * random_double();
}

auto clamp = [](double x) {
	if (x < 0.0) return 0.0;
	if (x > 1.0) return 1.0;
	return x;
	};

#endif 
