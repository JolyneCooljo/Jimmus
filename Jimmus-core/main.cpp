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

		// This does nothing other than verify that GLEW works.
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
		
		window.update();
	}

	// comment out line 17 to close on x button click
	system("PAUSE");
	return 0;
}