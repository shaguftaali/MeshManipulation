#pragma once
#include "UI/Window.h"
#include "Shapes/Sphere.h"

class Test
{
public:
	Test(Window window);


	void SphereRotation(Camera cam);

	void SelectionRender(Camera cam);

private:
	Sphere sphere;
	Window m_window;
	float angle;
};
