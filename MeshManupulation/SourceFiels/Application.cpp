#include "..\Includes\Application.h"
#include <GL/glew.h>

void MeshManupulation::Application::mouse1_dragged(float x, float y)
{
	if(mode==RENDER_MODE)
	{
		return;
	}

	float dx=(x-mouseX);
	float dy=(y-mouseY);

	if(mode==MODEL_MODE)
	{
		switch (action)
		{
		case Action::Edit:
			if(scene->has_selection())
			{
				dragSelection(x,y,dx,dy,get_world_to_3DH());
			}
			break;;

		case  Action::Navigation:
			//TODO
			break;

		case Action::Bevel:
			//TODO
			break;
		}
	}

	else if(mode==ANIMATION_MODE)
	{
		//TODO
	}
}

void MeshManupulation::Application::dragSelection(float x, float y, float dx, float dy, const Matrix4 & modelViewProj)
{
	if(scene->selected.object==nullptr)
	{
		return;
	}
	if(scene->selected.element)
	{
		scene->selected.element->translate(dx,dy,modelViewProj);
	}
	else
	{
		//scene->selected.object->
	}

}

Matrix4 MeshManupulation::Application::get_world_to_3DH()
{
	Matrix4 P, M;
	double a1=(double)P[0][0];
	double a2 = (double)P[0][0];
	glGetDoublev(GL_PROJECTION_MATRIX,&a1);
	glGetDoublev(GL_MODELVIEW_MATRIX, &a2);
	return P*M;
}
