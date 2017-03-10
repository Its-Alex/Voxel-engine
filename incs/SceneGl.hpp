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
# include <glm/glm.hpp>
# include <glm/gtx/transform.hpp>

# include "Shaders.hpp"
# include "Window.hpp"

class SceneGl
{
	public:
		SceneGl(std::string title, int width, int height);
		~SceneGl();

		bool	Loop();

	private:
		Window			mWindow;
		std::string 	mTitle;
		int				mWidth;
		int				mHeight;

		GLuint			mVertexArrayID;
		GLuint			mVertexBuffer;
		GLuint			mProgramID;
};

#endif