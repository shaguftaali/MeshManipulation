#pragma once
#include "MeshEditor/Scene/SceneObject.h"
#include "MeshEditor/Bounds/BBox.h"
#include "Maths/Vector2.h"
#include "Selection.h"

namespace MeshManupulation
{
	class SceneLight
	{
	public:
		virtual SceneLight *get_static_light() const=0;
	};

	class Scene
	{
		
	public:

		Scene(std::vector<SceneObject*> _objects,std::vector<SceneLight*>_lights);

		~Scene();

		void apply_transforms(double t);

		bool addObject(SceneObject* object);

		bool removeObject(SceneObject* object);

		void renderInOpenGl();

		BBox get_bbox();

		/**
		* Finds the object pointed to by the given (x, y) point.
		* x and y are from -1 to 1, NOT screenW to screenH.
		* Note that hoverIdx (and therefore has_hover) is automatically updated every
		* time this function is called.
		*/
		void getHoveredObject(const Vector2 &p, bool getElement=true, bool transformed=false);

		/**
		* Returns true iff there is a hovered feature in the scene.
		*/
		bool has_hover();

		/**
		* Returns true iff there is a selected feature in the scene.
		*/
		bool has_selection();

		
		
		void selectNextHalfedge();
		void selectTwinHalfedge();
		void selectHalfedge();

		
		
		void collapse_selected_element();
		void flip_selected_edge();
		void split_selected_edge();
		void erase_selected_element();
		void erase_selected_joint();


		void upsample_selected_mesh();
		void downsample_selected_mesh();
		void resample_selected_mesh();

		Selection selected;
	};
}
