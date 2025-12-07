#include "Utilities.h"

Vec3 ray_color(Ray r, std::vector<Sphere> world, int depth)
{
	if (depth <= 0)
		return Vec3(0, 0, 0);

	double closest_t = std::numeric_limits<double>::infinity();
	const Sphere* hitSphere = nullptr;

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
		Vec3 direction = direction.random_unit_vector() + normal;

		if (direction.dot(normal) <= 0.0)
			direction = direction * -1;
		return ray_color(Ray(hit, direction), world, depth-1) * 0.5;
	}
	Vec3 unit_dir = r.direction.normalized();
	double a = 0.5 * (unit_dir.y + 1.0);
	return (Vec3(1, 1, 1) * (1 - a) + Vec3(0.5, 0.7, 1.0) * (a));
}


double clamp(double x)
	{
		if (x < 0.0) return 0.0;
		if (x > 1.0) return 1.0;
		return x;
	};