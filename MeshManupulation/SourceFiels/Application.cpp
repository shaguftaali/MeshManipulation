#include "..\Includes\Application.h"

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
