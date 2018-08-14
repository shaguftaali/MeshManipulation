#pragma once
#include <vector>
#include "Maths/Vector3.h"
#include "Maths/Vector2.h"
#include <string>
#include "MaterialInfo.h"

struct Polygon
{
	std::vector<size_t> vertex_indices;        ///indices into vertex array
	std::vector<size_t> normal_indices;        ///indices into normal array
	std::vector<size_t> texcoord_indices;        ///indices into texcoord array
};

class Instance
{
public:

	enum Type
	{
		CAMERA,
		LIGHT,
		SPHERE,
		POLYMESH,
		MATERIAL
	};

	Type type;
	std::string id;
	std::string name;
};

struct PolymeshInfo:Instance
{
	std::vector<Vector3> vertices;
	std::vector<Vector3> normals;
	std::vector<Vector2> texcoords;

	std::vector<Polygon> polygons;
	MaterialInfo* material;
	
};


std::ostream& operator<<(std::ostream& os, const PolymeshInfo& polymesh)
{
	os << "PolymeshInfo: " << polymesh.name << " (id:" << polymesh.id << ")";

	os << " [";

	os << " num_polygons=" << polymesh.polygons.size();
	os << " num_vertices=" << polymesh.vertices.size();
	os << " num_normals=" << polymesh.normals.size();
	os << " num_texcoords=" << polymesh.texcoords.size();

	os << " ]";

	return os;
}
