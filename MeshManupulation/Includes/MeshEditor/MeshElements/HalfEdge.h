#pragma once
#include "HalfEdgeElement.h"

namespace MeshManupulation
{
	class  HalfEdge:public HalfEdgeElement
	{
	public:
		HalfEdgeIter& twin();

		HalfEdgeIter& next();

		VertexIter& vertex();

		EdgeIter& edge();

		FaceIter& face();

		HalfEdgeCIter twin() const;

		HalfEdgeCIter next() const;

		VertexCIter vertex() const;

		EdgeCIter edge() const;

		FaceCIter face() const;

		bool isBoundary();

		Info getInfo() const override;

		void setNeighbours(HalfEdgeIter next,HalfEdgeIter twin,VertexIter vertex,
						   EdgeIter edge,FaceIter face);

		Vector3 centroid() const override;

		BBox bounds() const override;

		void translate(double dx, double dy, const Matrix4& modelViewProj) override;

		void getAxes(std::vector<Vector3>& axes) const override;

		void getPickPoints(Vector3& a,Vector3& b,Vector3& p,Vector3& q,Vector3& r) const;

	protected:
		HalfEdgeIter _twin;
		HalfEdgeIter _next;
		VertexIter _vertex;
		EdgeIter _edge;
		FaceIter _face;
	};
}
