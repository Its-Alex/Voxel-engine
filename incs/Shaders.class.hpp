#ifndef SHADERS_CLASS_HPP
# define SHADERS_CLASS_HPP

# include <stdio.h>
# include <stdlib.h>
# include <string>
# include <vector>
# include <iostream>
# include <fstream>

//  Include OpenGL
# include <GL/glew.h>
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

		GLuint		mVertexShaderID;
		GLuint		mFragmentShaderID;
};

#endif