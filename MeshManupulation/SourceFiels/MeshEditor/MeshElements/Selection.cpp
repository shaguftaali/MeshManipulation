#include "..\..\..\Includes\MeshEditor\MeshElements\Selection.h"

MeshManupulation::Selection::Selection()
{
	clear();
}

void MeshManupulation::Selection::clear()
{
	object=nullptr;
	element=nullptr;
	coordinates=Vector3(0,0,0);
	axis=Axis::Center;
}

bool MeshManupulation::Selection::operator==(const Selection & s) const
{
	return (
		object==s.object				 &&
		element==s.element				 &&
		axis==s.axis					 &&
		coordinates.x == s.coordinates.x &&
		coordinates.x == s.coordinates.y &&
		coordinates.x == s.coordinates.z 

		);

}

bool MeshManupulation::Selection::operator!=(const Selection & s) const
{
	return !(*this==s);
}
