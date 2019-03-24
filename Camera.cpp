#include "Camera.h"
#include <cstdint>


Camera::Camera()
{
	dim = Point3(1, 1, 1);
}

Camera::Camera(Vec3 dimensions)
{
	dim = dimensions;
}

Ray Camera::project(Point2 coords)
{
	Ray ray;
	Point3 p;
	p.x = -dim.x / 2 + dim.x * coords.y;
	p.y = dim.y / 2 - dim.y * coords.x;
	ray.origin = pos;
	ray.direction = Point3()
}

void Camera::move(Point3 position)
{
	pos = position;
}
