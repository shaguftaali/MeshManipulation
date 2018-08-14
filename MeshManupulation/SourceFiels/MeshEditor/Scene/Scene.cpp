#include "..\..\..\Includes\MeshEditor\Scene\Scene.h"

void MeshManupulation::Scene::collapse_selected_element()
{}

void MeshManupulation::Scene::flip_selected_edge()
{
	if(selected.object==nullptr || selected.element==nullptr)
	{
		return;
	}
}

void MeshManupulation::Scene::split_selected_edge()
{}

void MeshManupulation::Scene::erase_selected_element()
{}

void MeshManupulation::Scene::erase_selected_joint()
{}
