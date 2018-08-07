#include "MeshEditor/MeshElements/Face.h"
#include <iterator>
#include <iostream>

#include "MeshEditor/MeshElements/HalfEdge.h"
#include "MeshEditor/MeshElements/Vertex.h"
#include <sstream>

MeshManupulation::Face::Face(bool isBoundary):
_isBoundary(isBoundary)
{}

MeshManupulation::HalfEdgeIter & MeshManupulation::Face::halfEdge()
{
	return _halfEdge;
}

MeshManupulation::HalfEdgeCIter MeshManupulation::Face::halfEdgeC() const
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
	Vector3 c(0.0,0.0,0.0);
	double d=0.0;

	HalfEdgeIter h=_halfEdge;
	do
	{
		c=c+h->vertex()->position;
		d+=1;
	}while (h!=_halfEdge);
	return c/d;
}

MeshManupulation::BBox MeshManupulation::Face::bounds() const
{
	BBox box;

	FaceCIter f0=halfEdgeC()->face();
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

MeshManupulation::Info MeshManupulation::Face::getInfo() const
{
	Info info;
	std::ostringstream m1,m2,m3,m4,m5;
	m1 << "FACE";
	m2 << "Address: " << this;
	//m3 << "Halfedge: " << elementAddress(halfedge());
	m4 << "Degree: " << degree();
	m5 << "Boundary: " << (isBoundary() ? "YES" : "NO");

	info.reserve(8);
	info.push_back(m1.str());
	info.push_back(std::string());
	info.push_back(m2.str());
	info.push_back(m3.str());
	info.push_back(std::string());
	info.push_back(m4.str());
	info.push_back(std::string());
	info.push_back(m5.str());

	return info;
}

void MeshManupulation::Face::translate(double dx, double dy, const Matrix4 & modelViewProj)
{
	HalfEdgeIter h=halfEdge();
	do
	{
		translatedPoint(h->vertex()->position,dx,dy,modelViewProj);
		h=h->next();
	}while (h!=halfEdge());
}

void MeshManupulation::Face::getAxes(std::vector<Vector3>& axes) const
{
	axes.resize(3);
	axes[2]=normal();

	if(degree()==4)
	{
		HalfEdgeCIter h=halfEdgeC();
		
		Vector3 p0=h->vertex()->position;
		h=h->next();

		Vector3 p1=h->vertex()->position;
		h=h->next();

		Vector3 p2=h->vertex()->position;
		h=h->next();

		Vector3 p3=h->vertex()->position;

		axes[0]=(p1-p0)+(p2-p3);
	}
	else
	{
		HalfEdgeCIter h=halfEdgeC();
		Vector3 p0=h->vertex()->position;
		h=h->next();

		Vector3 p1=h->vertex()->position;
		axes[0]=p1-p0;
	}
	axes[0] =axes[0]- Vector3::DotProduct(axes[0], axes[2]) * axes[2];
	axes[0]=axes[0].Normalization();

	// Choose the Y direction so that X x Y = Z
	axes[1] =Vector3::CrossProduct(axes[2], axes[0]);
}

bool MeshManupulation::Face::isBoundary() const
{
	return _isBoundary;
}

Vector3 MeshManupulation::Face::normal() const
{
	Vector3 N(0,0,0);

	HalfEdgeCIter h=halfEdgeC();

	do
	{
		Vector3 pi=h->vertex()->position;
		Vector3 pj = h->next()->vertex()->position;

		Vector3 v1=Vector3::CrossProduct(pi,pj);

		N=N+v1;
		h=h->next();
	}while (h!=halfEdgeC());

	return N.Normalization();
}
