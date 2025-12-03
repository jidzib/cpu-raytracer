#define STB_IMAGE_WRITE_IMPLEMENTATION
#define _CRT_SECURE_NO_WARNINGS
#include "stb_image_write.h"
#include "Vec3.h"
#include "Camera.h"
#include "Ray.h"
#include "Sphere.h"
#include <iostream>

Vec3 ray_color(Ray r, Sphere s)
{
	auto t = s.intersect(r);
	if (t)
	{
		Vec3 hit = r.at(*t);
		Vec3 normal = (hit - s.center).normalized();
		return Vec3(0.5 * (normal.x + 1), 0.5 * (normal.y + 1), 0.5 * (normal.z + 1));
	}
	Vec3 unit_dir = r.direction.normalized();
	double a = 0.5 * (unit_dir.y + 1.0);
	return (Vec3(1, 1, 1) * (1 - a) + Vec3(0.5, 0.7, 1.0) * (a));
}

int main() {

	Sphere sphere(Vec3(0, 0, -5), 1);

	double WIDTH = 1920;
	double HEIGHT = 1080;

	unsigned char* pixels = new unsigned char[WIDTH * HEIGHT * 3];
	Vec3 cameraPos(0, 0, 0);

	double viewport_height = 2.0;
	double viewport_width = 2.0 * (WIDTH / HEIGHT); // <-- floating point division
	double focal_length    = 1.0;

	Vec3 horizontal(viewport_width, 0, 0);    // X axis
	Vec3 vertical(0, viewport_height, 0);     // Y axis

	Vec3 lower_left = cameraPos - horizontal / 2.0 - vertical / 2.0 - Vec3(0, 0, focal_length);

	for (int row = 0; row < HEIGHT; ++row) {
		for (int col = 0; col < WIDTH; ++col) {
			double u = (double)col / (WIDTH - 1);              // horizontal coordinate [0..1]
			double v = (double)(HEIGHT - 1 - row) / (HEIGHT - 1); // vertical coordinate [0..1], flip so top row is first

			Vec3 pixel_position = lower_left + horizontal * u + vertical * v;
			Vec3 ray_direction = pixel_position - cameraPos;
			Ray r(cameraPos, ray_direction);


			Vec3 pixel_color = ray_color(r, sphere);
			int index = (row * WIDTH + col) * 3;
			auto clamp = [](double x) {
				if (x < 0.0) return 0.0;
				if (x > 1.0) return 1.0;
				return x;
				};

			pixels[index + 0] = static_cast<unsigned char>(255.999 * clamp(pixel_color.x));
			pixels[index + 1] = static_cast<unsigned char>(255.999 * clamp(pixel_color.y));
			pixels[index + 2] = static_cast<unsigned char>(255.999 * clamp(pixel_color.z));
		}
	}
	stbi_write_png("image.png", WIDTH, HEIGHT, 3, pixels, WIDTH*3);

}