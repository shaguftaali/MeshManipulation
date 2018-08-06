#include "MeshEditor/MeshElements/Face.h"
#include <iterator>
#include <iostream>

#include "MeshEditor/MeshElements/HalfEdge.h"
#include "MeshEditor/MeshElements/Vertex.h"

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

Vector3 MeshManupulation::Face::centroid() const
{
	return Vector3();
}

MeshManupulation::BBox MeshManupulation::Face::bounds() const
{
	return BBox();
}

MeshManupulation::Info MeshManupulation::Face::getInfo() const
{
	return Info();
}

void MeshManupulation::Face::translate(double dx, double dy, const Matrix4 & modelViewProj)
{}

void MeshManupulation::Face::getAxes(std::vector<Vector3>& axes) const
{}

bool MeshManupulation::Face::isBoundary() const
{
	return _isBoundary;
}

Vector3 MeshManupulation::Face::normal() const
{
	Vector3 N(0,0,0);

	HalfEdgeCIter h=halfEdge();

	do
	{
		Vector3 pi=h->vertex()->position;
		Vector3 pj = h->next()->vertex()->position;

		Vector3 v1=Vector3::CrossProduct(pi,pj);

		N=N+v1;
		h=h->next();
	}while (h!=halfEdge());

	return N.Normalization();
}
