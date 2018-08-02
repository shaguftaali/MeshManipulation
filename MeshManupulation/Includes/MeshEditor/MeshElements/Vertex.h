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


			virtual void translate(double dx, double dy, const Matrix4& modelViewProj);

			virtual BBox bounds() const ;

			virtual Info getInfo() const ;

			void getNeighbourhood(std::map<HalfEdgeIter,double>& seen, int depth=1);

			void smoothNeighborhood(double diff, std::map<HalfEdgeIter,double>& seen,int depth=1);

			virtual  void getAxes(std::vector<Vector3>& axes) const;

			virtual Vector3 centroid() const ;

			Vector3 neighborhoodCentroid() const;

			Vector3 normal () const;

			float laplacian() const;

			bool isBoundary() const;

			Size degree() const;

			

	protected:

		HalfEdgeIter _halfEdge;


		
	};
}