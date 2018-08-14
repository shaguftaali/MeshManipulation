#pragma once
#include <ostream>

struct MaterialInfo: public Instance
{
	BSDF* bsdf;
};

std::ostream& operator<<(std::ostream& os,const MaterialInfo& material);
