#include "Image.h"
#include "Camera.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>


int main(void)
{
	Camera camera(Vec3(0.5,0.5,0.5));
	Image img(800, 800);
	img(0, 0) = Pixel(0, 0, 0);
	for (uint32_t i = 0; i < img.rows(); i++) {
		for (uint32_t j = 0; j < img.cols(); j++) {
			Vec2 coords(double(j) / (img.cols() - 1), double(i) / (img.rows() - 1));
			Ray ray = camera.project(coords);
		}
	}
	img.write("myimage.ppm");
}