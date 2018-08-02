#include "MeshEditor/MeshElements/Face.h"

MeshManupulation::Face::Face(bool isBoundary):
_isBoundary(isBoundary)
{}

MeshManupulation::HalfEdgeIter & MeshManupulation::Face::halfEdge()
{
	return _halfEdge;
}

MeshManupulation::HalfEdgeCIter MeshManupulation::Face::halfEdge() const
{
	return _halfEdge;
}

MeshManupulation::Size MeshManupulation::Face::degree() const
{
	Size d=0;
	HalfEdgeIter h=_halfEdge;
	do
	{
		d++;
		h=h->next();
	}while (h!=_halfEdge);
	return d;
}

bool MeshManupulation::Face::isBoundary() const
{
	return false;
}

Vector3 MeshManupulation::Face::normal() const
{
	return Vector3();
}
