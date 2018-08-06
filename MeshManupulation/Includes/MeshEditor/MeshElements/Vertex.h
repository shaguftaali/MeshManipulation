#pragma once
//#include "HalfEdgeElement.h"
#include "HalfEdgeElement.h"
#include <list>


//#define INF_D (std::numeric_limits<double>::infinity())
namespace MeshManupulation
{
	class Vertex : public HalfEdgeElement

	{
	public:

			Vector3 position;

			Vector3 bindPosition;

			Vector3 newPosition;

			Index index;

			bool isNew;

			float offset;

			float velocity;

			Matrix4 quadric;

			HalfEdgeIter& halfEdge();

			HalfEdgeCIter halfEdge() const;


		void translate(double dx, double dy, const Matrix4& modelViewProj) override;

		BBox bounds() const override;

		Info getInfo() ;

			void getNeighbourhood(std::map<HalfEdgeIter,double>& seen, int depth=1);

			void smoothNeighborhood(double diff, std::map<HalfEdgeIter,double>& seen,int depth=1);

		void getAxes(std::vector<Vector3>& axes) const override;

		Vector3 centroid() const override;

			Vector3 neighborhoodCentroid() const;

			Vector3 normal () const;

			float laplacian() const;

			bool isBoundary() const;

			Size degree() const;

			

	protected:

		HalfEdgeIter _halfEdge;

		HalfEdge* elementAddress(HalfEdgeIter h);

		
	};
}