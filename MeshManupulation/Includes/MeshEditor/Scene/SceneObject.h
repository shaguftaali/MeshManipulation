#pragma once
#include "Primitive.h"
#include "MeshEditor/Light/BSDF.h"
#include "Selection.h"

namespace MeshManupulation
{
	class SceneObject
	{
	public:
		SceneObject();

		virtual void set_draw_styles(DrawStyle *defaultStyle, DrawStyle *hoveredStyle,
									 DrawStyle *selectedStyle)=0;

		virtual void draw()=0;

		virtual void draw_pretty();

		virtual void drawGhost();

		virtual BBox get_bbox()=0;

		virtual Info getInfo()=0;

		virtual void drag(double x,double y,double dx,double dy,
						  const Matrix4 &modelViewProj)=0;

		virtual  SceneObject* get_static_object()=0;

		virtual SceneObject* get_transformed_static_object(double t);

		virtual void draw_pick(int &pickID, Selection& selection)=0;

		virtual Matrix4 getTransformation();

		virtual Matrix4 getRotation();

		virtual std::vector<Primitive*> get_primitives() const=0;

		virtual BSDF* get_bsdf() const=0;

		Vector3 position;
		Vector3 rotation;
		Vector3 scale;

		bool isVisible;

		bool isGhosted;

		bool isPickable;
	};
}
