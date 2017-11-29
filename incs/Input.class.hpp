#ifndef INPUT_CLASS_HPP
# define INPUT_CLASS_HPP

# include <iostream>
# include <GLFW/glfw3.h>

class Input {
public:
	Input(void);
	Input(Input const & src);
	virtual ~Input(void);

	void	keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

	Input& operator=(Input const & rhs);
private:
	int _keyboardKeys[GLFW_KEY_LAST];
};

#endif