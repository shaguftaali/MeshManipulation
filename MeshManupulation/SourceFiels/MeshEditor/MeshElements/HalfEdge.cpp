#include "MeshEditor/MeshElements/HalfEdge.h"


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

MeshManupulation::Info MeshManupulation::HalfEdge::getInfo()
{
	return Info();
}

void MeshManupulation::HalfEdge::setNeighbours(HalfEdgeIter next, HalfEdgeIter twin, VertexIter vertex, EdgeIter edge, FaceIter face)
{
	_next=next;
	_twin=twin;
	_vertex=vertex;
	_edge=edge;
	_face=face;
}


MeshManupulation::BBox MeshManupulation::HalfEdge::bounds() const
{
	return BBox();
}


void MeshManupulation::HalfEdge::getPickPoints(Vector3 & a, Vector3 & b, Vector3 & p, Vector3 & q, Vector3 & r) const
{
	

}
