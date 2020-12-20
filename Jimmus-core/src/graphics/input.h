#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "window.h"

namespace jimmus { 
	namespace graphics {
		#define MAX_KEYS 1024
		#define MAX_BUTTONS 32
		class Input {
			friend class Window;
			private:
				bool m_Keys[MAX_KEYS];
				bool m_MouseButtons[MAX_BUTTONS];
				double mx, my;
			public:
				Input(); 
				bool isKeyPressed(unsigned int keycode) const;
				bool isMouseButtonPressed(unsigned int button) const;
				void getMousePosition(double& x, double& y) const;
				bool setKeyAction(unsigned int keycode, bool action);
				bool setMouseButtonAction(unsigned int button, bool action);
				void setCursorPosition(double x, double y);
			private:
				static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
				static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
				static void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
		};
	}
}