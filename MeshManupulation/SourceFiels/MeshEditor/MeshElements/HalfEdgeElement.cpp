#include "MeshEditor/MeshElements/HalfEdgeElement.h"
#include "MeshEditor/MeshElements/Vertex.h"
#include "MeshEditor/MeshElements/Edge.h"
#include "MeshEditor/MeshElements/HalfEdge.h"
#include "MeshEditor/MeshElements/Face.h"


MeshManupulation::HalfEdge * MeshManupulation::HalfEdgeElement::getHalfEdge()
{
	return dynamic_cast<HalfEdge*>(this);
}

MeshManupulation::Vertex * MeshManupulation::HalfEdgeElement::getVertex()
{
	return dynamic_cast<Vertex*>(this);
}

MeshManupulation::Edge * MeshManupulation::HalfEdgeElement::getEdge()
{
	return dynamic_cast<Edge*>(this);
}

MeshManupulation::Face * MeshManupulation::HalfEdgeElement::getFace()
{
	return dynamic_cast<Face*>(this);
}

MeshManupulation::HalfEdgeElement::~HalfEdgeElement()
{}

void MeshManupulation::HalfEdgeElement::translatedPoint(Vector3 & p, double dx, double dy, const Matrix4 & modelViewProj)
{
	Vector4 q(p,1.0);

	// Transform into clip space
	q=modelViewProj*q;
	double w=q.w;
	q=q*(1/w);

	q.x+=dx;
	q.y+=dy;

	// Transform back into model space
	q=q*w;
	q=modelViewProj.Inverse()*q;
	p.x=q.x;
	p.y=q.y;
	p.z=q.z
	;
}
