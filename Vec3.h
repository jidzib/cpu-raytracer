#ifndef VEC_3
#define VEC_3

class Vec3
{
	public:
		double x, y, z;
		Vec3();
		Vec3(double, double, double);
		Vec3 operator+(Vec3 other);
		Vec3 operator-(Vec3 other);
		Vec3 operator*(double scalar);
		Vec3 operator/(double divider);
		double dot(Vec3 other);
		Vec3 normalized();
};

#endif

