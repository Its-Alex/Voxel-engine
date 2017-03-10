#ifndef Window_HPP
# define Window_HPP

# include <stdio.h>
# include <stdlib.h>
# include <string>
# include <vector>
# include <iostream>
# include <fstream>

//  Include OpenGL
# include <GL/glew.h>
# include <GLFW/glfw3.h>

class Window
{
	public:
		Window(std::string title, int width, int height);
		~Window();

		bool	init();
		bool	isDone();
		void	update();
		GLuint	getProgramID();
		
	private:
		GLFWwindow		*mWindow;

		std::string 	mTitle;
		int				mWidth;
		int				mHeight;
};

#endif