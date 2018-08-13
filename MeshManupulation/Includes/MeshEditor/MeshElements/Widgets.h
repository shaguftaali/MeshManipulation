#pragma once
#include "Maths/Vector2.h"
#include "MeshEditor/Bounds/BBox.h"
#include "Face.h"
#include "MeshEditor/Scene/SceneObject.h"
#include "Selection.h"
#include <GL/glew.h>

namespace MeshManupulation
{
	class Selection;

	class Widgets :public SceneObject
	{
	public:

		Selection target;

		Widgets();


		enum class Mode
		{
			Translate,
			Rotate,
			Scale
		};

		void setTarget(Selection& target);

		void setTranslate();

		void setRotation();

		void setScale();

		void cycleMode();

		void restoreLastMode();

		void setClickPosition(const Vector2& position);

		virtual void set_draw_styles(DrawStyle* defaultStyle, DrawStyle* hoveredStyle, DrawStyle* selectedStyle);

		virtual void draw();

		virtual  void drawGhost();

		virtual BBox get_bbox();

		virtual Info getInfo();

		virtual void drag(double x, double y,double dx, double dy,const Matrix4& modelViewProj);

		virtual  SceneObject* get_static_object();

		virtual void draw_pick(int& pickID,bool transformed=false);

		virtual void setSelection(int pickID,Selection& selection);

		void updateGeometry();

		void enterObjectMode();

		void exitObjectMode();

		void enterJointMode(bool isRoot);

		void exitJointMode();

		void enterTransformedMode();

		void exitTransformMode();

		Mode mode,lastMode;

	protected:
		std::map<int,Selection::Axis> pickIDToAxis;
		std::vector<Vector3> axes;
		BBox bounds;
		Vector3 center;

		bool objectMode;
		bool jointMode,jointIsRoot;
		bool transformedMode;

		void directionalTransform(
			Vector3& position, std::vector<int> tranformAxes,
			Vector3 center, double x, double y, double dx,
			double dy, const Matrix4& modelViewProj);

		void drawHandles() const;
		void drawTranslateHandles() const;
		void drawRotateHandles() const;
		void drawScaleHandles() const;
		void drawCenterHandle() const;

		Vector2 clickPosition;

		std::vector<std::vector<GLubyte>> axisColors;
	};
}
