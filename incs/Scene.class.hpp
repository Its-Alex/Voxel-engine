#ifndef SCENE_CLASS_HPP
# define SCENE_CLASS_HPP

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

# include "Shaders.class.hpp"
# include "Window.class.hpp"

class Scene
{
	public:
		Scene(std::string title, int width, int height);
		~Scene();

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