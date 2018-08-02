#include "..\..\Includes\UI\Window.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h> 
#include <iostream>

double Window:: m_mouseX=0;
double Window::m_mouseY = 0;

double Window::m_lastMouseX = 0;
double Window::m_lastMouseY = 0;
bool Window::mouseClicked=false;


void framebuffer_size_callback(GLFWwindow * window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that gridSize and 
	// cellCount will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}


void Window::processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if(glfwGetMouseButton(window,GLFW_MOUSE_BUTTON_1)==GLFW_PRESS)
	{
		//std::cout<<"mouse input "<<std::endl;
		mouseClicked=true;
		//processSelection(m_mouseX, m_mouseY);
	}
}
void Window::processSelection(int xpos, int ypos)
{

	unsigned char res[4];
	GLint viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);
	glReadPixels(xpos, viewport[3] - ypos, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, &res);
	//std::cout << "xpos " << xpos<< "   ypos "<<ypos << std::endl;
	switch (res[0])
	{
	case 0:
		printf("Nothing Picked\n");
		break;;

	case  1:
		std::cout << "sphere picked " << (int)res[0] << std::endl;
		//printf("%c \t %3d \t", ch, ch);
		break;

	default:
		//printf("res : \n",res[0]);
		std::cout<<"res "<<(int)res[0]<<std::endl;
	}

}
 void Window::mouseCallback(GLFWwindow* a_window, double xPos, double yPos)
{
	 Window::m_lastMouseX = Window::m_mouseX;
	 Window::m_lastMouseY = Window::m_mouseY;

	Window::m_mouseX=xPos;
	Window::m_mouseY = yPos;

	

}

Window::Window()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return ;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetCursorPosCallback(window, Window::mouseCallback);
	glewInit();

	/*Shader ourShader("D:/Shagufta/OpenGL_Workspace/SphearParentChild/SphearParentChild/Shaders/LightVertexShader.vs", "D:/Shagufta/OpenGL_Workspace/SphearParentChild/SphearParentChild/Shaders/LightFragmentShader.fs");*/

	
	glEnable(GL_DEPTH_TEST);

}

void Window::ClearWindow()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	//glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	
}

void Window::ClearWindow2()
{
	//glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



}

void Window::SwapBuffer()
{
	glfwSwapBuffers(window);
	glfwPollEvents();
}

bool Window::IsWindowColse()
{
	return glfwWindowShouldClose(window);
}

void Window::ProcessInputs()
{
	processInput(window);
}

double Window::GetMouseX()
{
	return m_mouseX;
}

double Window::GetMouseY()
{
	return  m_mouseY;
}

double Window::GetLastMouseX()
{
	return m_lastMouseX;
}

double Window::GetLastMouseY()
{
	return m_lastMouseY;
}





