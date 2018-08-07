//#include "..\..\..\Includes\MeshEditor\MeshElements\Edge.h"
#include "MeshEditor/MeshElements/Edge.h"
#include "MeshEditor/MeshElements/HalfEdge.h"
#include "MeshEditor/MeshElements/Vertex.h"
#include "MeshEditor/MeshElements/Face.h"
#include <sstream>


MeshManupulation::HalfEdgeIter & MeshManupulation::Edge::halfEdge()
{
	return  _halfEdge;
}

MeshManupulation::HalfEdgeCIter MeshManupulation::Edge::halfEdgeC() const
{
	return _halfEdge;
}

bool MeshManupulation::Edge::isBoundary()
{
	return halfEdge()->face()->isBoundary()||halfEdge()->twin()->face()->isBoundary();
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
	HalfEdgeCIter h=halfEdgeC();
	Vector3 p=h->vertex()->position;
	Vector3 p2=h->twin()->vertex()->position;

	return (p+p2)/2.0;
}

MeshManupulation::BBox MeshManupulation::Edge::bounds() const
{
	BBox box;
	FaceCIter f0= halfEdgeC()->face();
	FaceCIter f1=halfEdgeC()->twin()->face();

	if(!f0->isBoundary())
	{
		box.expand(f0->bounds());
	}
	if(!f1->isBoundary())
	{
		box.expand(f1->bounds());
	}
	return box;

}

MeshManupulation::Info MeshManupulation::Edge::getInfo() 
{
	Info info;
	std::ostringstream m1,m2,m3,m4;
	m1<<"EDGE";
	m2<<"Address: "<<this;
//	m3<<"Halfegde: "<<elementAddressC(halfEdgeC());
	m4<<"Boundary: "<<(isBoundary() ?"YES":"NO");
	info.reserve(4);
	info.push_back(m1.str());
	info.push_back(std::string());
	info.push_back(m2.str());
	info.push_back(m3.str());
	info.push_back(std::string());
	info.push_back(m4.str());

	return info;
}

void MeshManupulation::Edge::translate(double dx, double dy, const Matrix4 & modelViewProj)
{
	HalfEdgeIter h=halfEdge();
	do
	{
		translatedPoint(h->vertex()->position,dx,dy,modelViewProj);
		h=h->twin();
	}while (h!=halfEdge());
}

void MeshManupulation::Edge::getAxes(std::vector<Vector3>& axes) const
{
	axes.resize(3);
	Vector3 p0=halfEdgeC()->vertex()->position;
	Vector3 p1 = halfEdgeC()->twin()->vertex()->position;
	axes[0]=(p1-p0).Normalization();

	Vector3 N0(0,0,0);
	Vector3 N1(0,0,0);
	FaceCIter f0=halfEdgeC()->face();
	FaceCIter f1=halfEdgeC()->twin()->face();
	if(!f0->isBoundary())
	{
		N0=f0->normal();
	}
	if (!f1->isBoundary())
	{
		N1 = f1->normal();
	}
	axes[2]=(N0+N1).Normalization();
	axes[1]=Vector3::CrossProduct(axes[2],axes[0]);
}

MeshManupulation::Edge * MeshManupulation::Edge::elementAddress(EdgeIter e)
{
	return &(*e);
}

MeshManupulation::Edge * MeshManupulation::Edge::elementAddressC(EdgeIter e) const
{
	return &(*e);
}
