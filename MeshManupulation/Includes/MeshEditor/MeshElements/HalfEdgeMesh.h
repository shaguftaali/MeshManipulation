#pragma once
#include <vector>
#include "Maths/Vector3.h"

namespace MeshManupulation
{

	typedef size_t Index;
	typedef size_t Size;


	class HalfEdgeMesh
	{
	public:
		HalfEdgeMesh();

		HalfEdgeMesh(const HalfEdgeMesh& mesh);

		const HalfEdgeMesh& operator=(const HalfEdgeMesh& mesh);


		void build(const std::vector<std::vector<Index>>& polygons, const std::vector<Vector3>& vertexPositions);

		void Rebuild(const std::vector<std::vector<Index>>& polygons, const std::vector<Vector3>& vertexPositions);

		Size nHalfEdge() const;

		Size nVertices() const;

		Size nEdge() const;

		Size nFace() const;

		Size nBoundaries() const;


	};

}

