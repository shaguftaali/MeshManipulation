#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window
{
public:
	Window();

	void ClearWindow();

	void ClearWindow2();

	void SwapBuffer();

	bool IsWindowColse();

	void ProcessInputs();

	double GetMouseX();

	double GetMouseY();

	double GetLastMouseX();

	double GetLastMouseY();

	static  bool mouseClicked;
	static void processSelection(int xpos, int ypos);
private:
	// settings
	const unsigned int SCR_WIDTH = 800;
	const unsigned int SCR_HEIGHT = 800;
	GLFWwindow *window;
	
	static  double m_mouseX;
	static  double m_mouseY;

	static  double m_lastMouseX;
	static  double m_lastMouseY;


	static  void mouseCallback(GLFWwindow* a_window, double xPos, double yPos);
	/*static void processSelection(int xpos, int ypos);*/

	static  void processInput(GLFWwindow *window);
};
