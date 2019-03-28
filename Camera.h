#pragma once
#include <ostream>
struct Vec3
{
	double x, y, z;
	Vec3(double X, double Y, double Z);
	Vec3();
	Vec3 normalize() const;
	double dot(const Vec3& a) const;
	Vec3 cross(const Vec3& rhs) const;
	Vec3 operator -(const Vec3& rhs) const;
	Vec3 operator -() const;
	Vec3 operator +(const Vec3& rhs) const;
	
};

Vec3 operator *(const Vec3& lhs, const Vec3& rhs);
Vec3 operator *(const Vec3& lhs, double rhs);
std::ostream& operator <<(std::ostream& ost, const Vec3& v);

struct Vec2
{
	double x, y;
	Vec2(double X, double Y) :x(X), y(Y) {};
	double dot(const Vec2& a) const;
};

typedef Vec3 Point3;
typedef Vec2 Point2;

struct Ray
{
	Point3 origin;
	Vec3 direction;
	Ray() {};
};

class Camera
{
public:
	Camera();
	Camera(Vec3 dimensions);
	Ray project(Point2 coordinates);
	void move(Point3 position);
private:
	Vec3 dim;
	Point3 pos;
};

