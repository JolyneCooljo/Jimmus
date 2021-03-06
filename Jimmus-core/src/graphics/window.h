#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "input.h"

namespace jimmus { namespace graphics {
		class Window {
			friend class Input;
			private:
				const char* m_Title;
				int m_Width, m_Height;
				GLFWwindow* m_Window;
				Input* m_Input; 
				bool m_Closed;
			public:
				Window(const char* title, int width, int height);
				~Window();
				bool closed() const;
				void update();
				void clear() const;
				inline int getWidth() const { return m_Width; }
				inline int getHeight() const { return m_Height; }
			private:
				bool init();
				bool initGlew();
		};
 	
}}