#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "src/graphics/window.h"

namespace jimmus {
	namespace graphics {
#define MAX_KEYS 1024
#define MAX_BUTTONS 32
		class Input {
		private:
			static bool m_Keys[MAX_KEYS];
			static bool m_MouseButtons[MAX_BUTTONS];
			static double mx, my;
		public:
		private:
			static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		};
	}
}