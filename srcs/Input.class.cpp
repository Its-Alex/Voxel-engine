#include "Input.class.hpp"

/* CONSTRUCTORS */

Input::Input(void) {
	for(int count = -1; count <= GLFW_KEY_LAST; count++)
		this->_keyboardKeys[count] = 0;
	return;
}

Input::Input(Input const & src) {
	*this = src;
	return;
}

Input::~Input(void) {
	return;
}

/* MEMBERS */

void	Input::keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	(void)window;
	(void)scancode;
	(void)mods;
	this->_keyboardKeys[key] = action;
}

/* OPERATORS */

Input& Input::operator=(Input const & rhs) {
	(void)rhs;
	return *this;
}