#pragma once
#include "MeshEditor/Scene/SceneObject.h"
#include "HalfEdgeElement.h"

namespace MeshManupulation
{
	class Selection
	{
	public:
		enum class Axis
		{
			X,
			Y,
			Z,
			Center,
			None
		};

		SceneObject *object;
		HalfEdgeElement* element;
		Vector3 coordinates;
		Axis axis;

		Selection();

		void clear();

		bool operator==(const Selection& s)const;

		bool operator!=(const Selection& s)const;
	};
}
