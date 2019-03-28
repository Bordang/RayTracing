#pragma once
#include "Camera.h"
#include <vector>
#include <memory>
#include <map>
#include <array>

struct Color
{
	double r, g, b, a;
};

struct Hit
{
	Point3 point;
	Vec3 normal;
	Color color;
	double distance;
};



class Object
{
public:
	virtual bool intersect(Ray ray, Hit& hit) = 0;
};

typedef std::shared_ptr<Object> ObjectPtr;

struct Triangle: public Object{
	virtual bool intersect(Ray ray, Hit& hit) override;
	Vec3 normal() const;
	Triangle();
	std::array<Point3, 3> points;
	Color color;
};

typedef std::shared_ptr<Triangle> TrianglePtr;

class World
{
public:
	World();
	~World();
	void add(std::string name, ObjectPtr obj);
	bool intersect(Ray ray, Hit& hit) const;
private:
	typedef std::map<std::string, ObjectPtr> ObjectMap;
	ObjectMap objects;
};

