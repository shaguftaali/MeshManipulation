#include "..\..\..\Includes\MeshEditor\Scene\MaterialInfo.h"

std::ostream & operator<<(std::ostream & os, const MaterialInfo & material)
{
	os<<"MaterialInfo: " << material.name<< "(id:"<<material.id<<")";

	os<<" [ "<<" BSDF="<< material.bsdf<< " ] ";
	return os;
}
