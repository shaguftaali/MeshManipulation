//#include "..\..\..\Includes\MeshEditor\MeshElements\Vertex.h"
#include "MeshEditor/MeshElements/Vertex.h"
#include "MeshEditor/MeshElements/Face.h"
#include "MeshEditor/MeshElements/HalfEdge.h"
#include <sstream>
//
//MeshManupulation::HalfEdgeIter & MeshManupulation::Vertex::halfEdgeC()
//{
//	// TODO: insert return statement here
//}

MeshManupulation::HalfEdgeIter & MeshManupulation::Vertex::halfEdge()
{
	return _halfEdge;
}

MeshManupulation::HalfEdgeCIter MeshManupulation::Vertex::halfEdge() const
{
	return _halfEdge;
}

void MeshManupulation::Vertex::translate(double dx, double dy, const Matrix4 & modelViewProj)
{
	translatedPoint(position,dx,dy,modelViewProj);
}

MeshManupulation::BBox MeshManupulation::Vertex::bounds() const
{
	BBox box;
	HalfEdgeCIter h=halfEdge();
	do
	{
		FaceCIter f=h->face();
		if(!f->isBoundary())
		{
			box.expand(f->bounds());
		}
		h=h->twin()->next();
	}while (h!=halfEdge());
	return box;
}

MeshManupulation::Info MeshManupulation::Vertex::getInfo() 
{
	Info info;
	std::ostringstream m1,m2,m3,m4,m5,m6;
	m1<<"VERTEX";
	m2<<"Address: "<<this;
	m3<<"Halfedge: "<<elementAddress(halfEdge());
	m4<<"Degree "<<degree();
	m5<<"Boundary: "<<(isBoundary()?"YES":"NO");
	return Info();
}

void MeshManupulation::Vertex::getNeighbourhood(std::map<HalfEdgeIter, double>& seen, int depth)
{
	if (depth<0)
	{
		return;
	}
	HalfEdgeIter h=_halfEdge;
	double dist= INF_D;
	do
	{
		//VertexIter u=h.tw
	}
	while (h!=_halfEdge);
}

void MeshManupulation::Vertex::smoothNeighborhood(double diff, std::map<HalfEdgeIter, double>& seen, int depth)
{
	seen.emplace(_halfEdge,0.0);
	getNeighbourhood(seen,depth);
	for (auto hd:seen)
	{
		HalfEdgeIter h=hd.first;
		VertexIter u=h->vertex();
		double dist=hd.second;
		double newDiff=diff*exp(-dist*dist*2);
		u->offset+=newDiff;
	}
}

Vector3 MeshManupulation::Vertex::centroid() const
{
	return position;
}

Vector3 MeshManupulation::Vertex::neighborhoodCentroid() const
{
	Vector3 c(0,0,0);
	double d=0;

	HalfEdgeCIter h=halfEdge();
	do
	{
		c=c+(h->next()->vertex()->position);
		d+=1;
		h=h->twin()->next();
	}while (h!=halfEdge());
	c=c/d;
	return c;
}

/**
* returns the number of edges (or equivalently, polygons) touching this
* vertex
*/
MeshManupulation::Size MeshManupulation::Vertex::degree() const
{
	Size d=0;
	HalfEdgeIter h=_halfEdge;
	do
	{
		if(!h->face()->isBoundary())
		{
			d++;
		}
	}while (h!=_halfEdge);
	return d;
}

MeshManupulation::HalfEdge * MeshManupulation::Vertex::elementAddress(HalfEdgeIter h)
{
	return &(*h);
}
