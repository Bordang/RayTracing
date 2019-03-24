#pragma once
struct Vec3
{
	double x, y, z;
	Vec3(double X, double Y, double Z) {
		x = X;
		y = Y;
		z = Z;
	}
	Vec3() {
		x = 0;
		y = 0;
		z = 0;
	}
};


struct Vec2
{
	double x, y;
	Vec2(double X, double Y) :x(X), y(Y) {};
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

