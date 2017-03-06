#ifndef SHADERS_HPP
# define SHADERS_HPP

# include <stdio.h>
# include <stdlib.h>
# include <string>
# include <vector>
# include <iostream>
# include <fstream>

//  Include OpenGL
# include <GL/glew.h>

# include <GLFW/glfw3.h>
# include <glm/glm.hpp>

class Shaders
{
	public:
		Shaders(std::string vertexFilePath, std::string fragmentFilePath);
		~Shaders();

		GLuint Load();
		
	private:
		std::string mVertexPath;
		std::string mFragmentPath;
};

#endif