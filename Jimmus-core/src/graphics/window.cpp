#include "window.h"
#include <iostream>

namespace jimmus {	namespace graphics {

	void window_resize(GLFWwindow* window, int width, int height);

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

		m_Input = new Input();
		if (!m_Input) {
			std::cout << "Failed to create Input Handler!" << std::endl;
			return false; 
		}

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
		if (!m_Window) {
			std::cout << "Failed to create GLFW Window!" << std::endl;
			return false;
		}
		
		if (initGlew() != GLEW_OK) {
			std::cout << "Could not initialize GLEW!" << std::endl;
			return false;
		}

		return true;
	}

	bool Window::initGlew() {
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, this);
		glfwSetWindowSizeCallback(m_Window, window_resize);
		glfwSetKeyCallback(m_Window, Input::keyCallback);
		glfwSetMouseButtonCallback(m_Window, Input::mouseButtonCallback);
		glfwSetCursorPosCallback(m_Window, Input::cursorPositionCallback);
		std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;
		return glewInit();
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
	void window_resize(GLFWwindow* window, int width, int height) {
		glViewport(0, 0, width, height);
	}
}}