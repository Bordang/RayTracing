#include "Image.h"
#include "Camera.h"
#include "World.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>


int main(void)
{
	Camera camera(Vec3(5,5,5));
	World world;
	TrianglePtr tri1(new Triangle);
	tri1->points[0] = Vec3(-0.5, -0.5, 5);
	tri1->points[1] = Vec3(0, 0.5, 5);
	tri1->points[2] = Vec3(0.5, -0.5, 5);
	tri1->color = { 1,0,0,0 };
	TrianglePtr tri2(new Triangle);
	tri2->points[0] = Vec3(0, 0, 3);
	tri2->points[1] = Vec3(0, 1, 10);
	tri2->points[2] = Vec3(1, 0, 10);
	tri2->color = { 1,1,0,0 };
	world.add("triangle 1", tri1);
	world.add("triangle 2", tri2);
	Image img(800, 800);
	for (uint32_t i = 0; i < img.rows(); i++) {
		for (uint32_t j = 0; j < img.cols(); j++) {
			Vec2 coords(double(j) / (img.cols() - 1), double(i) / (img.rows() - 1));
			Ray ray = camera.project(coords);
			Hit hit;
			if (world.intersect(ray, hit))
			{
				img(i, j) = Pixel(hit.color.r*255, hit.color.g*255, hit.color.b*255);
				//std::cout << "Position " << i << ", " << j << ", " << hit.point << "\n";
			}
		}
	}
	img.write("myimage.ppm");
}