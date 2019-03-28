#include "Camera.h"
#include <cstdint>
#include <cmath>


Camera::Camera()
{
	dim = Point3(1, 1, 1);
	pos = Vec3(0, 0, 0);
}

Camera::Camera(Vec3 dimensions)
{
	dim = dimensions;
	pos = Vec3(0, 0, 0);
}

Ray Camera::project(Point2 coords)
{
	Ray ray;
	Point3 p;
	p.x = -dim.x / 2 + dim.x * coords.x;
	p.y = dim.y / 2 - dim.y * coords.y;
	p.z = dim.z;
	ray.origin = pos;
	ray.direction = p.normalize();
	return ray;
}

void Camera::move(Point3 position)
{
	pos = position;
}

Vec3::Vec3(double X, double Y, double Z) {
	x = X;
	y = Y;
	z = Z;
}
Vec3::Vec3() {
	x = 0;
	y = 0;
	z = 0;
}

Vec3 Vec3::normalize() const
{
	
	double length = sqrt(x * x + y * y + z * z);
	if (length != 0) {
		Vec3 res;
		res.x = x / length;
		res.y = y / length;
		res.z = z / length;
		return res;
	}
	return *this;
}

double Vec3::dot(const Vec3& a) const 
{
	return x * a.x + y * a.y + z * a.z;
}

Vec3 Vec3::cross(const Vec3& rhs) const
{
	return Vec3(y * rhs.z - z * rhs.y,
			    z * rhs.x - x * rhs.z,
			    x * rhs.y - y * rhs.x);
}

Vec3 Vec3::operator-(const Vec3 & rhs) const
{
	return Vec3(x - rhs.x, y - rhs.y, z - rhs.z);
}

Vec3 Vec3::operator-() const
{
	return Vec3(-x, -y, -z);
}

Vec3 Vec3::operator+(const Vec3 & rhs) const
{
	return Vec3(x + rhs.x, y + rhs.y, z + rhs.z);
}

double Vec2::dot(const Vec2& a) const
{
	return x*a.x + y*a.y;
}

Vec3 operator*(const Vec3 & lhs, const Vec3 & rhs)
{
	return Vec3(lhs.y * rhs.z - lhs.z * rhs.y,
				lhs.z * rhs.x - lhs.x * rhs.z,
				lhs.x * rhs.y - lhs.y * rhs.x);
}

Vec3 operator*(const Vec3 & lhs, double rhs)
{
	return Vec3(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);
}

std::ostream & operator<<(std::ostream & ost, const Vec3 & v)
{
	ost << "(" << v.x << "," << v.y << "," << v.z << ")";
	return ost;

}
