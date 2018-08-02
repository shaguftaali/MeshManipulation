

#include "..\Includes\Shader.h"
#include <iostream>

#include "../Includes/UI/Window.h"
#include "../Includes/3D/Camera.h"
#include "Test/Test.h"


//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow *window);




int main(int argc, char* argv[])
{
	Window window;


	Camera camera(Vector3(0, 0, -50), Vector3(0, 0, 0), 500, .005f, 60);

	Test test(window);
	//std::cout<<data.GetDoesIntersect()<<std::endl;

	while (!window.IsWindowColse())
	{
		window.ClearWindow();
		test.SphereRotation(camera);
		//test.SelectionRender(camera);
		window.ProcessInputs();
		if(Window::mouseClicked)
		{
			window.SwapBuffer();
			window.ClearWindow2();
			test.SelectionRender(camera);
			Window::processSelection(window.GetMouseX(),window.GetMouseY());
			Window::mouseClicked=false;
		}
		window.SwapBuffer();
	}


	//	grid.DeleteDrawingData();


}
//
//void processInput(GLFWwindow *window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	// make sure the viewport matches the new window dimensions; note that gridSize and 
//	// cellCount will be significantly larger than specified on retina displays.
//	glViewport(0, 0, width, height);
//}