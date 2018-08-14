#include "..\..\..\Includes\MeshEditor\Scene\Mesh.h"

Mesh::Mesh(PolymeshInfo & polymesh, const Matrix4 & transform)
{
	std::vector<std::vector<size_t>> polygons;
	for (const Polygon &p : polymesh.polygons)
	{
		polygons.push_back(p.vertex_indices);
	}
	std::vector<Vector3> vertices=polymesh.vertices;
	for (int i = 0; i < vertices.size(); ++i)
	{
		vertices[i]=(transform*Vector4(vertices[i],1)).projectTo3D();
	}
	mesh.build(polygons,vertices);
	if (polymesh.material)
	{
		bsdf=polymesh.material->bsdf;
	}
	else
	{
		bsdf=new DiffuseBSDF(Spectrum(1.0,1.0,1.0));
	}

	scale=Vector3(1,1,1);
	
}

Mesh::~Mesh()
{}

void Mesh::draw()
{}

void Mesh::drawGhost()
{}
