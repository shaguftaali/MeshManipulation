#include "MeshEditor/Bounds/BBox.h"
#include "Maths/Vector3.h"
#include <GL/glew.h>

MeshManupulation::BBox::BBox()
{
	max = Vector3(-INF_D, -INF_D, -INF_D);
	min = Vector3(INF_D, INF_D, INF_D);
	extent = max - min;
}

MeshManupulation::BBox::BBox(const Vector3 & p) :min(p), max(p)
{
	extent = max - min;
}

MeshManupulation::BBox::BBox(const Vector3 & a_min, const Vector3 & a_max) : min(a_min), max(a_max)
{
	extent = a_max - a_min;
}

MeshManupulation::BBox::BBox(const double minX, const double minY, const double minZ, const double maxX, const double maxY, const double maxZ)
{
	min = Vector3(minX, minY, minZ);
	max = Vector3(maxX, maxY, maxZ);
	extent = max - min;
}

void MeshManupulation::BBox::expand(const BBox & bbox)
{
	min.x = std::min(min.x, bbox.min.x);
	min.y = std::min(min.y, bbox.min.y);
	min.z = std::min(min.z, bbox.min.z);

	max.x = std::min(max.x, bbox.max.x);
	max.y = std::min(max.y, bbox.max.y);
	max.z = std::min(max.z, bbox.max.z);
}

void MeshManupulation::BBox::expand(const Vector3 & p)
{
	min.x = std::min(min.x, p.x);
	min.y = std::min(min.y, p.y);
	min.z = std::min(min.z, p.z);

	max.x = std::min(max.x, p.x);
	max.y = std::min(max.y, p.y);
	max.z = std::min(max.z, p.z);
}

Vector3 MeshManupulation::BBox::centroid() const
{
	Vector3 v = min;
	return (v + max) / 2;
}

double MeshManupulation::BBox::surface_area() const
{
	if (empty())
	{
		return 0.0;
	}

	return 2 * (extent.x*extent.z + extent.x*extent.y + extent.y*extent.z);
}

bool MeshManupulation::BBox::empty() const
{
	return (min.x>max.x || min.y>max.y || min.z>max.z);
}

bool MeshManupulation::BBox::intersect(const Ray & r, double & t0, double & t1) const
{
	return false;
}

void MeshManupulation::BBox::draw(Color c) const
{
	glColor4f(c.r,c.g,c.b,c.a);

	glBegin(GL_LINE_STRIP);
	glVertex3d(max.x,max.y,max.z);
	glVertex3d(max.x, max.y, min.z);
	glVertex3d(min.x, max.y, min.z);
	glVertex3d(min.x, max.y, max.z);
	glVertex3d(max.x, max.y, max.z);
	glEnd();

	// bottom
	glBegin(GL_LINE_STRIP);
	glVertex3d(min.x, min.y, min.z);
	glVertex3d(min.x, min.y, max.z);
	glVertex3d(max.x, min.y, max.z);
	glVertex3d(max.x, min.y, min.z);
	glVertex3d(min.x, min.y, min.z);
	glEnd();

	// side
	glBegin(GL_LINES);
	glVertex3d(max.x, max.y, max.z);
	glVertex3d(max.x, min.y, max.z);
	glVertex3d(max.x, max.y, min.z);
	glVertex3d(max.x, min.y, min.z);
	glVertex3d(min.x, max.y, min.z);
	glVertex3d(min.x, min.y, min.z);
	glVertex3d(min.x, max.y, max.z);
	glVertex3d(min.x, min.y, max.z);
	glEnd();

}

//std::ostream &operator<<(std::ostream &os, const MeshManupulation::BBox &b)
//{
//
//	return os << "BBOX(" << b.min << ", " << b.max << ")";
//}


