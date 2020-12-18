#include "input.h"
#include <iostream>

namespace jimmus {
	namespace graphics {

		Input::Input() {
			for (int i = 0; i < MAX_KEYS; i++) {
				m_Keys[i] = false;
			}
			for (int i = 0; i < MAX_BUTTONS; i++) {
				m_MouseButtons[i] = false; 
			}
		}

		bool Input::isKeyPressed(unsigned int keycode) const {
			if (keycode >= MAX_KEYS || keycode < 0) return false;
			else return m_Keys[keycode];
		}

		bool Input::isMouseButtonPressed(unsigned int button) const {
			if (button >= MAX_BUTTONS || button < 0) return false;
			else return m_MouseButtons[button];
		}

		void Input::getMousePosition(double& x, double& y) const {
			x = mx;
			y = my;
		}

		bool Input::setKeyAction(unsigned int keycode, bool action) {
			if (keycode >= MAX_KEYS || keycode < 0) return false;
			else m_Keys[keycode] = action;
			// Test key input.
			// std::cout << m_keys[keycode] << std::endl;
			return true;
		}

		bool Input::setMouseButtonAction(unsigned int button, bool action) {
			if (button >= MAX_BUTTONS || button < 0) return false;
			else m_MouseButtons[button] = action;
			// Test mouse input.
			// std::cout << m_MouseButtons[button] << std::endl;
			return true;
		}

		void Input::setCursorPosition(double x, double y) {
			// Test cursor input
			// std::cout << x << ", " << y << std::endl;
			mx = x; 
			my = y; 
		}

		void Input::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_Input->setKeyAction(key, action != GLFW_RELEASE);
		}

		void Input::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_Input->setMouseButtonAction(button, GLFW_RELEASE);
		}

		void Input::cursorPositionCallback(GLFWwindow* window, double xpos, double ypos) {
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_Input->setCursorPosition(xpos, ypos);
		}

	}
}