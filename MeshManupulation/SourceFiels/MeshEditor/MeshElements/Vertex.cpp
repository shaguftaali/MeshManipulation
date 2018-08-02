//#include "..\..\..\Includes\MeshEditor\MeshElements\Vertex.h"
#include "MeshEditor/MeshElements/Vertex.h"

//
//MeshManupulation::HalfEdgeIter & MeshManupulation::Vertex::halfEdge()
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
{}

Vector3 MeshManupulation::Vertex::centroid() const
{
	return position;
}

Vector3 MeshManupulation::Vertex::neighborhoodCentroid() const
{
	return Vector3();
}

MeshManupulation::Size MeshManupulation::Vertex::degree() const
{
	return Size();
}
