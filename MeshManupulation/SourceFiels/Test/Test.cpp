#include "..\..\Includes\Test\Test.h"
#include "Shapes/Sphere.h"

Test::Test(Window window):
m_window(window),
sphere(
	"D:/Shagufta/OpenGL_Workspace/MeshManupulation/MeshManupulation/Shaders/LightVertexShader.vs",
	//"D:/Shagufta/OpenGL_Workspace/MeshManupulation/MeshManupulation/Shaders/SelectionFrag.fs",
	"D:/Shagufta/OpenGL_Workspace/SphearParentChild/SphearParentChild/Shaders/LightFragmentShader.fs",

	Vector3(0, 0, 0),
	5,
	30,
	nullptr
)
{
	
}


void Test::SphereRotation(Camera cam)
{
	/*float xoffset=m_window.GetLastMouseX()-m_window.GetMouseX();
	float yoffset = m_window.GetLastMouseY() - m_window.GetMouseY();

	float sensitivity=0.05f;
	float dir=0.5f;
	if(xoffset<0)
	{
		dir=-0.5f;
	}*/
	//angle+=dir*sensitivity;
	//std::cout<<"angle "<< dir <<std::endl;
	//sphere.transform.Rotate(Vector3(0,1,0),dir);
	sphere.Render(cam);

}

void Test::SelectionRender(Camera cam)
{
	sphere.SelectionRender(cam);
}


