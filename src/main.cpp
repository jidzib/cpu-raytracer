#define STB_IMAGE_WRITE_IMPLEMENTATION
#define _CRT_SECURE_NO_WARNINGS
#include "stb_image_write.h"
#include "Vec3.h"
#include "Camera.h"
#include "Ray.h"
#include "Sphere.h"
#include "Utilities.h"
#include <iostream>
#include <vector>

int main() {

	std::vector<Sphere> world;

	Sphere sphere1(Vec3(0, 0, -5), 1);
	Sphere sphere2(Vec3(2, 0, -3), 1);
	Sphere sphere3(Vec3(-2, 2, -4), 1);

	world.push_back(sphere1);
	world.push_back(sphere2);
	world.push_back(sphere3);

	double WIDTH = 720;
	double HEIGHT = 480;
	double aspect_ratio = WIDTH / HEIGHT;

	unsigned char* pixels = new unsigned char[WIDTH * HEIGHT * 3];
	Vec3 cameraPos(0, 0, 0);

	double viewport_height = 1.0;
	double viewport_width = aspect_ratio * viewport_height; // <-- floating point division
	double focal_length = 1.0;

	Vec3 horizontal(viewport_width, 0, 0);    // X axis
	Vec3 vertical(0, viewport_height, 0);     // Y axis

	Vec3 lower_left = cameraPos - horizontal / 2.0 - vertical / 2.0 - Vec3(0, 0, focal_length);
	int samples_per_pixel = 10;

	for (int row = 0; row < HEIGHT; ++row) {
		for (int col = 0; col < WIDTH; ++col) {
			double u = (double)col / (WIDTH - 1);              // horizontal coordinate [0..1]
			double v = (double)(HEIGHT - 1 - row) / (HEIGHT - 1); // vertical coordinate [0..1], flip so top row is first

			Vec3 pixel_position = lower_left + horizontal * u + vertical * v;
			Vec3 ray_direction = pixel_position - cameraPos;
			Ray r(cameraPos, ray_direction);

			Vec3 pixel_color(0, 0, 0);
			for (int sample = 0; sample < samples_per_pixel; sample++)
			{
				pixel_color = pixel_color + ray_color(r, world);
			}

			int index = (row * WIDTH + col) * 3;

			pixels[index + 0] = static_cast<unsigned char>(255.999 * clamp(pixel_color.x / samples_per_pixel));
			pixels[index + 1] = static_cast<unsigned char>(255.999 * clamp(pixel_color.y / samples_per_pixel));
			pixels[index + 2] = static_cast<unsigned char>(255.999 * clamp(pixel_color.z / samples_per_pixel));
		}
	}
	stbi_write_png("images/image.png", WIDTH, HEIGHT, 3, pixels, WIDTH*3);

}