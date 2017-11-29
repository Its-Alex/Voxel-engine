#include "Window.class.hpp"

static void	GlfwError(int code, const char *error)
{
std::cout << "Error GLFW [" << code << "]: " << error << std::endl;
}

Window::Window(std::string title, int width, int height) : mTitle(title),
mWidth(width), mHeight(height)
{}

Window::~Window()
{
	glfwDestroyWindow(mWindow);
    glfwTerminate();
}

bool		Window::init()
{
	// Set function to return errors
	glfwSetErrorCallback(GlfwError);
	
    if (!glfwInit()) {
        return (false);
    }

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	mWindow = glfwCreateWindow(mWidth, mHeight, mTitle.c_str(), NULL, NULL);
	if(!mWindow){
		std::cerr << "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials." << std::endl;
		glfwTerminate();
		return (false);
	}

	glfwMakeContextCurrent(mWindow);

	// Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		std::cerr << "Failed to initialize GLEW" << std::endl;
		glfwTerminate();
		return (false);
	}

	glfwSetInputMode(mWindow, GLFW_STICKY_KEYS, GL_TRUE);
	std::cout << "GLFW initialize!" << std::endl;
	return (true);
}

/*
** Check if the ESC key was pressed or the mWindow was closed
*/
bool		Window::isDone()
{
	if (glfwGetKey(mWindow, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		   glfwWindowShouldClose(mWindow) == 0)
		return (true);
	else
		return (false);
}

/*
** Event system
*/
void		Window::update()
{
	// Swap buffers
	glfwSwapBuffers(mWindow);
	glfwPollEvents();
}