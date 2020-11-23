#include "src/graphics/window.h"

// method used for testing execution
int main() {

	using namespace jimmus;
	using namespace graphics;

	Window window("Jimmus", 960, 640);
	glClearColor(0.2f, 0.3f, 0.8f, 0.1f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	std::cout << glGetString(GL_VERSION) << std::endl;

	while (!window.closed()) {
		// use to check width and height
		// std::cout << window.getWidth() << ", " << window.getHeight() << std::endl;
		window.clear();
		double x, y;
		window.getMouseCursorPosition(x, y);

		if (window.isKeyPressed(GLFW_KEY_A)) {
			std::cout << "Pressed" << std::endl;
		}

		if (window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT)) {
			std::cout << "Clicked" << std::endl;
		}

		std::cout << "Cursor Position X,Y: " << x << ", " << y << std::endl;

		// This does nothing other than verify that GLEW works.
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
		
		window.update();
	}

	system("PAUSE");
	return 0;
}