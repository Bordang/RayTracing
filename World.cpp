#include "World.h"



World::World()
{
	
}


World::~World()
{
}

void World::add(std::string name, ObjectPtr obj)
{
	objects[name] = obj;
}

bool World::intersect(Ray ray, Hit& hit) const
{
	bool found = false;
	double bestdistance = 0;
	for (ObjectMap::const_iterator it = objects.begin(); it != objects.end(); ++it)
	{
		ObjectPtr obj = it->second;
		Hit newhit;
		if (obj->intersect(ray, newhit))
		{
			if ((!found) || (newhit.distance < bestdistance))
			{
				bestdistance = newhit.distance;
				found = true;
				hit = newhit;
			}
		}
	}
	return found;
}

bool Triangle::intersect(Ray ray, Hit & hit)
{
	Vec3 n = normal();
	double denom = n.dot(ray.direction);
	if (denom != 0) {
		double dist = n.dot(points[0] - ray.origin) / denom;
		Vec3 intersect = ray.origin + ray.direction*dist;
		Vec3 r0 = (points[1] - points[0]) * (intersect - points[0]);
		Vec3 r1 = (points[2] - points[1]) * (intersect - points[1]);
		Vec3 r2 = (points[0] - points[2]) * (intersect - points[2]);
		if ((r0.dot(n) > 0) && (r1.dot(n) > 0) && (r2.dot(n) > 0)) {
			hit.distance = dist;
			hit.point = intersect;
			hit.normal = n;
			hit.color = color;
			return true;
		}
	}
	return false;
}

Vec3 Triangle::normal() const
{
	return ((points[1] - points[0])*(points[2] - points[0])).normalize();
}

Triangle::Triangle()
{
	
}