#include "glfw.hpp"

static void	GlfwError(int code, const char *error)
{
	std::cout << "Error GLFW [" << code << "]: " << error << std::endl;
}

			Glfw::Glfw(std::string title, int width, int height) : mTitle(title),
	mWidth(width), mHeight(height)
{}

			Glfw::~Glfw()
{
	glfwDestroyWindow(mWindow);
    glfwTerminate();
}

bool		Glfw::init()
{
	glfwSetErrorCallback(GlfwError);
	
    if (!glfwInit()) {
        return (false);
    }

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	mWindow = glfwCreateWindow(mWidth, mHeight, mTitle.c_str(), NULL, NULL);
	if(mWindow == NULL ){
		fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
		getchar();
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(mWindow);

	// Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return -1;
	}

	glfwSetInputMode(mWindow, GLFW_STICKY_KEYS, GL_TRUE);
	std::cout << "GLFW initialize!" << std::endl;

	// Create and compile our GLSL program from the shaders
	Shaders Shaders("SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader");
	mProgramID = Shaders.Load();

	return (true);
}

bool		Glfw::isDone()
{
	if (glfwGetKey(mWindow, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		   glfwWindowShouldClose(mWindow) == 0)
		return (true);
	else
		return (false);
}

GLuint		Glfw::getProgramID()
{
	return (mProgramID);
}

void		Glfw::update()
{
	// Swap buffers
	glfwSwapBuffers(mWindow);
	glfwPollEvents();
}