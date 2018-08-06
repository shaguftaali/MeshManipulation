//#include "..\..\..\Includes\MeshEditor\MeshElements\Edge.h"
#include "MeshEditor/MeshElements/Edge.h"
#include "MeshEditor/MeshElements/HalfEdge.h"
#include "MeshEditor/MeshElements/Vertex.h"



MeshManupulation::HalfEdgeIter & MeshManupulation::Edge::halfEdge()
{
	return  _halfEdge;
}

MeshManupulation::HalfEdgeCIter MeshManupulation::Edge::hlafEdge() const
{
	return _halfEdge;
}

bool MeshManupulation::Edge::isBoundary()
{
	//return halfEdge()-face;
}

double MeshManupulation::Edge::lenght() const
{
	 HalfEdgeCIter h=_halfEdge;

	Vector3 p0=h->vertex()->position;
	Vector3 p1 = h->twin()->vertex()->position;
	return Vector3::Distance(p0,p1);
}

Vector3 MeshManupulation::Edge::centroid() const
{
	//HalfEdgeCIter h= halfEdge();

	return Vector3();
}

MeshManupulation::BBox MeshManupulation::Edge::bounds() const
{
	return BBox();
}

MeshManupulation::Info MeshManupulation::Edge::getInfo() const
{
	return Info();
}

void MeshManupulation::Edge::translate(double dx, double dy, const Matrix4 & modelViewProj)
{}

void MeshManupulation::Edge::getAxes(std::vector<Vector3>& axes) const
{}
