#include "Window.h"

namespace buch {	namespace graphics {

	void windowResize(GLFWwindow* window, int width, int height);

	Window::Window(const char* title, int width, int height) 
	{
		m_Title = title;
		m_Width = width;
		m_Height = height;
		if (!init())
			glfwTerminate();
	}

	Window::~Window() 
	{
		glfwTerminate();
	}

	bool Window::closed() const
	{
		return glfwWindowShouldClose(m_Window) == 1;
	}

	void Window::clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::update()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	bool Window::init() 
	{
		if (!glfwInit()) {
			std::cout << "ERROR_GLFW1: GLFW could not be initialized" << std::endl;
			return false;
		}

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
		if (!m_Window) {
			glfwTerminate();
			std::cout << "ERROR_GLFW2: Window could not be created" << std::endl;
			return false;
		}
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowSizeCallback(m_Window, windowResize);
		return true;
	}

	void windowResize(GLFWwindow* window, int width, int height) 
	{
		glViewport(0, 0, width, height);
	}

}	}