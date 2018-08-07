#include "MeshEditor/MeshElements/HalfEdge.h"
#include "MeshEditor/MeshElements/Face.h"
#include "MeshEditor/MeshElements/Edge.h"
#include "MeshEditor/MeshElements/Vertex.h"


MeshManupulation::HalfEdgeIter & MeshManupulation::HalfEdge::twin()
{
	return _twin;
}

MeshManupulation::HalfEdgeIter & MeshManupulation::HalfEdge::next()
{
	return _next;
}

MeshManupulation::VertexIter & MeshManupulation::HalfEdge::vertex()
{
	return _vertex;
}

MeshManupulation::EdgeIter & MeshManupulation::HalfEdge::edge()
{
	return _edge;
}

MeshManupulation::FaceIter & MeshManupulation::HalfEdge::face()
{
	return _face;
}

MeshManupulation::HalfEdgeCIter MeshManupulation::HalfEdge::twin() const
{
	return _twin;
}

MeshManupulation::HalfEdgeCIter MeshManupulation::HalfEdge::next() const
{
	return _next;
}

MeshManupulation::VertexCIter MeshManupulation::HalfEdge::vertex() const
{
	return _vertex;
}

MeshManupulation::EdgeCIter MeshManupulation::HalfEdge::edge() const
{
	return _edge;
}

MeshManupulation::FaceCIter MeshManupulation::HalfEdge::face() const
{
	return _face;
}

bool MeshManupulation::HalfEdge::isBoundary()
{
	return face()->isBoundary();
}

MeshManupulation::Info getInfo()
{
	return MeshManupulation::Info();
}

void MeshManupulation::HalfEdge::setNeighbours(HalfEdgeIter next, HalfEdgeIter twin, VertexIter vertex, EdgeIter edge, FaceIter face)
{
	_next=next;
	_twin=twin;
	_vertex=vertex;
	_edge=edge;
	_face=face;
}

Vector3 MeshManupulation::HalfEdge::centroid() const
{
	return edge()->centroid();
}


MeshManupulation::BBox MeshManupulation::HalfEdge::bounds() const
{

	return  edge()->bounds();
}

void MeshManupulation::HalfEdge::translate(double dx, double dy, const Matrix4 & modelViewProj)
{
	edge()->translate(dx,dy,modelViewProj);
}

void MeshManupulation::HalfEdge::getAxes(std::vector<Vector3>& axes) const
{
	edge()->getAxes(axes);
}


void MeshManupulation::HalfEdge::getPickPoints(Vector3 & a, Vector3 & b, Vector3 & p, Vector3 & q, Vector3 & r) const
{
	const double w=1.0/6;

	Vector3 x0=vertex()->position;
	Vector3 x1=next()->vertex()->position;
	Vector3 x2=next()->next()->vertex()->position;

	a=x1;
	p=  (1.0 - w)*x1 + w * x2;
	r = (1.0 - w)*x1 + w * x0;
	q = (p + r ) / 2.0;
	b = a + 2.0 * (q - a);
}
