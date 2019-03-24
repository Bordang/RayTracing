#pragma once
#include "Camera.h"
#include <vector>
struct Hit
{
	Point3 point;
	Vec3 normal;
	Vec3 color;
};

class Object
{
public:
	virtual bool intersect(Ray ray, Hit& hit) = 0;
};

class Cube: public Object{
public:
	virtual bool intersect(Ray ray, Hit& hit) override;
private:
	Point3 position;
	Vec3 dimensions;
};

class World
{
public:
	World();
	~World();
private:
	std::vector<Object> objects;
};

