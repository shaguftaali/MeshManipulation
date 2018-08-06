#pragma once
#include "Maths/Vector3.h"
#include "MeshEditor/Bounds/BBox.h"
#include <vector>
#include "Maths/Matrix4.h"
#include <list>
#include "HalfEdgeMesh.h"
#include <map>
//
//#define PI (3.14159265358979323)
//#define EPS_D (0.00000000001)
//#define EPS_F (0.00001f)
//#define INF_D (std::numeric_limits<double>::infinity())
//#define INF_F (std::numeric_limits<float>::infinity())

namespace MeshManupulation
{

#define PI (3.14159265358979323)
#define EPS_D (0.00000000001)
#define EPS_F (0.00001f)
#define INF_D (std::numeric_limits<double>::infinity())
#define INF_F (std::numeric_limits<float>::infinity())


	class  Vertex;
	class Edge;
	class  Face;
	class  HalfEdge;



typedef std::vector<std::string> Info;
typedef std::list<Vertex>::iterator VertexIter;
typedef std::list<Edge>::iterator EdgeIter;
typedef std::list<Face>::iterator FaceIter;
typedef std::list<HalfEdge>::iterator HalfEdgeIter;

typedef std::list<Vertex>::const_iterator VertexCIter;
typedef std::list<Edge>::const_iterator EdgeCIter;
typedef std::list<Face>::const_iterator FaceCIter;
typedef std::list<HalfEdge>::const_iterator HalfEdgeCIter;

	class HalfEdgeElement
	{
	public:
		
		HalfEdge* getHalfEdge();

		Vertex* getVertex();

		Edge* getEdge();

		Face* getFace();

		virtual Vector3 centroid() const=0;

		virtual  BBox bounds() const=0;

		virtual  void getAxes(std::vector<Vector3>& axes) const=0;

		virtual Info getInfo() const=0;

		virtual void translate(double dx,double dy,const Matrix4& modelViewProj)=0;

		virtual ~HalfEdgeElement();
		

	protected:
		void translatedPoint(Vector3& p, double dx, double dy, const Matrix4& modelViewProj);
	};

	

}


