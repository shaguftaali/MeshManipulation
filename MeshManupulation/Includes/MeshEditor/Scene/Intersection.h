#pragma once
#include "Maths/Vector3.h"
#include "MeshEditor/MeshElements/HalfEdgeElement.h"

class Primitive;

struct  Intersection
{
	double t;

	const Primitive* primitive;

	Vector3 n;

	BSDF* bsdf;

	Intersection():
	t(INF_D),
	primitive(NULL),
	bsdf(NULL)
	{
		
	}
};