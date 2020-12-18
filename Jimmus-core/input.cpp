#include "input.h"
#include <iostream>

namespace jimmus {
	namespace graphics {

		Input::Input() {

		}

		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
			Window* win = (Window*)glfwGetWindowUserPointer(window);
		}
	}
}