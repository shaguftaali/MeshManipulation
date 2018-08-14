#pragma once
#include "MeshEditor/Bounds/BBox.h"
#include "Intersection.h"


class Primitive
{
public:

	virtual MeshManupulation::BBox get_bbox();

	virtual bool intersect(const Ray& r) const=0;

	virtual  bool intersect(const Ray& r,Intersection* i)const=0;

	virtual  BSDF* get_bsdf() const=0;

	/**
	* Draw with OpenGL (for visualization)
	* \param c desired highlight color
	*/
	virtual void draw(const Color& c)const=0;

	/**
	* Draw outline with OpenGL (for visualization)
	* \param c desired highlight color
	*/
	virtual void drawOutline(const Color& c)const=0;
};
