#pragma once
#include "Render.h"
#include "Maths/Matrix4.h"

namespace MeshManupulation
{
	// MOUSE INPUTS //
#define MOUSE_LEFT     0
#define MOUSE_RIGHT    1
#define MOUSE_MIDDLE   2
	class Application:public Renderer
	{
		
		enum  Mode
		{
			MODEL_MODE,
			RENDER_MODE,
			ANIMATION_MODE,
			VISUALIZE_MODE
		};

		Mode mode;

		enum class Action
		{
			Navigation,
			Edit,
			Bevel,
			CreateJoint,
			BoneRadius,
			IK,
			Wave,
			Object,
			Pose,
			Raytrace_Video,
			Rasterize_Video
		};

		Action action;

		//Internal event system
		float mouseX,mouseY;

		enum e_mouse_button
		{
			LEFT=MOUSE_LEFT,
			RIGHT=MOUSE_RIGHT,
			MIDDLE=MOUSE_MIDDLE
		};

		//Event Handling
		void mouse_pressed(e_mouse_button b);     // Mouse pressed.
		void mouse_released(e_mouse_button b);    // Mouse Released.
		void mouse1_dragged(float x,float y);     // Left Mouse Dragged.
		void mouse2_dragged(float x, float y);    // Right Mouse Dragged.
		void mouse_moved(float x, float y);       // Mouse Moved.

												  /**
												  * If there is current selection and it's draggable, apply its drag method.
												  */
		void dragSelection(float x, float y, float dx, float dy,
						   const Matrix4& modelViewProj);
	};
}
