#include "window.h"
#include <iostream>

namespace jimmus {	namespace graphics {

	void window_resize(GLFWwindow* window, int width, int height);

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

	Window::Window(const char* title, int width, int height) {
		m_Title = title;
		m_Width = width;
		m_Height = height;
		if (!init())
			glfwTerminate();

		for (int i = 0; i < MAX_KEYS; i++) {
			m_Keys[i] = false;
		}

		for (int i = 0; i < MAX_BUTTONS; i++) {
			m_MouseButtons[i] = false;
		}
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
			std::cout << "Failed to create GLFW Window!" << std::endl;
			return false;
		}
		
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, this);
		glfwSetWindowSizeCallback(m_Window, window_resize);
		glfwSetKeyCallback(m_Window, key_callback);
		glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
		glfwSetCursorPosCallback(m_Window, cursor_position_callback);
		
		std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;

		if (glewInit() != GLEW_OK) {
			std::cout << "Could not initialize GLEW!" << std::endl;
			return false;
		}
		return true;
	}

	bool Window::isKeyPressed(unsigned int keycode) const {
		// TODO log this when logging system is implemented
		if (keycode >= MAX_KEYS)
			return false;

		return m_Keys[keycode];
	}

	bool Window::isMouseButtonPressed(unsigned int button) const {
		// TODO log this when logging system is implemented
		if (button >= MAX_BUTTONS)
			return false;

		return m_MouseButtons[button];
	}

	void Window::getMouseCursorPosition(double& x, double& y) const {
		x = mx;
		y = my;
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

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
		Window* win = (Window*) glfwGetWindowUserPointer(window);
		win->m_Keys[key] = action != GLFW_RELEASE;
	}

	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->m_MouseButtons[button] = action != GLFW_RELEASE;
	}

	void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->mx = xpos;
		win->my = ypos;
	}
}}