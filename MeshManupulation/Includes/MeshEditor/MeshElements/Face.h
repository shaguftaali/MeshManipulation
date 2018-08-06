#pragma once
#include "HalfEdgeElement.h"

namespace MeshManupulation
{
	class Face : public HalfEdgeElement
	{
	public:
		Face(bool isBoundary=false);

		HalfEdgeIter& halfEdge();

		HalfEdgeCIter halfEdge() const;
		
		Size degree() const;

		Vector3 centroid() const override;

		BBox bounds() const override;

		Info getInfo() const override;

		void translate(double dx, double dy, const Matrix4& modelViewProj) override;

		virtual void getAxes(std::vector<Vector3>& axes) const ;

		bool isBoundary() const;

		Vector3 normal() const;

		Index index;

		Vector3 newPosition;

		Matrix4 quadric;

	protected:
		HalfEdgeIter _halfEdge;
		bool _isBoundary;
	
	};
}
