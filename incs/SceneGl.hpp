#ifndef SCENEGL_HPP
# define SCENEGL_HPP

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
# include "glfw.hpp"

class SceneGl
{
	public:
		SceneGl(std::string title, int width, int height);
		~SceneGl();

		bool	Loop();

	private:
		Glfw			mWindow;
		std::string 	mTitle;
		int				mWidth;
		int				mHeight;

		GLuint			mVertexArrayID;
		GLuint			mVertexBuffer;
		GLuint			mProgramID;
};

#endif