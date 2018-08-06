#pragma once
#include "Edge.h"

namespace MeshManupulation
{
	class EdgeRecord
	{
	public:
		EdgeRecord();

		EdgeRecord(EdgeIter& _edge);

		EdgeIter edge;

		Vector3 optimalPoint;

		double score;

	};
}
