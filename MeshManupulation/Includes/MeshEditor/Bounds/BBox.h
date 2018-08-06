#pragma once

#include "Maths/Misc.h"
#include <algorithm>
#include "Ray.h"
#include "../../../SourceFiels/MeshEditor/Bounds/Color.h"
#include <ostream>
#include "Maths/Vector3.h"


namespace MeshManupulation
{


	struct  BBox
	{
		Vector3 max;
		Vector3 min;
		Vector3 extent;

		BBox();
	

		BBox(const Vector3& p);
		

		BBox(const Vector3& a_min, const Vector3& a_max);
		

		BBox(const double minX,const double minY,const double minZ,
			 const double maxX,const double maxY,const double maxZ);
	

		void expand(const BBox& bbox);
	

		void expand(const Vector3& p);
		

		Vector3 centroid() const;
		

		double surface_area() const;
	

		bool empty() const;
	

		bool intersect(const Ray& r,double& t0,double& t1) const;

		void draw(Color c) const;

	//	std::ostream &operator<<(std::ostream &os, const BBox &b);

	};
}
