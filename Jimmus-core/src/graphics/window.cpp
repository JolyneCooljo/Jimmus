#include "window.h"
#include <iostream>

namespace jimmus {	namespace graphics {

	void windowResize(GLFWwindow* window, int width, int height);

	Window::Window(const char* title, int width, int height) {
		m_Title = title;
		m_Width = width;
		m_Height = height;
		if (!init())
			glfwTerminate();
	}

	Window::~Window() {
		glfwTerminate();
	}

	bool Window::init() {
		if (!glfwInit()) {
			std::cout << "Failed to Initilize GLFW" << std::endl;
			return false;
		}

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
		if (!m_Window) {
			std::cout << "Failed to created GLFW Window!" << std::endl;
			return false;
		}
		
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowSizeCallback(m_Window, windowResize);
		return true;
	}

	void Window::clear() const {
		return glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	bool Window::closed() const {
		return glfwWindowShouldClose(m_Window) == 1;
	}

	void Window::update() {
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	// possibility that m_Width and m_Height don't get updated; will need to change if it becomes an issue
	void windowResize(GLFWwindow* window, int width, int height) {
		glViewport(0, 0, width, height);
	}
}}