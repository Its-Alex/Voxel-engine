#ifndef GLFW_HPP
# define GLFW_HPP

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

# include "Shaders.hpp"

class Glfw
{
	public:
		Glfw(std::string title, int width, int height);
		~Glfw();

		bool	init();
		bool	isDone();
		void	update();
		GLuint	getProgramID();
		
	private:
		GLFWwindow		*mWindow;
		GLuint			mProgramID;
		std::string 	mTitle;
		int				mWidth;
		int				mHeight;
};

#endif