#pragma once
#include "HalfEdgeElement.h"
#include "MeshEditor/MeshElements/EdgeRecord.h"


namespace MeshManupulation
{
	//class  EdgeRecord;

	class Edge:public HalfEdgeElement
	{
	public:
		HalfEdgeIter& halfEdge();

		HalfEdgeCIter halfEdgeC() const;

		bool isBoundary();

		double lenght() const;

		Vector3 centroid() const override;

		BBox bounds() const override;

		Info getInfo() ;

		void translate(double dx, double dy, const Matrix4& modelViewProj) override;

		void getAxes(std::vector<Vector3>& axes) const override;

		Vector3 newPosition;

		Index index;

		bool isNew;

		EdgeRecord record;

	protected:
		HalfEdgeIter _halfEdge;

		Edge* elementAddress(EdgeIter e);


		Edge* elementAddressC(EdgeIter e) const;

	};
}
