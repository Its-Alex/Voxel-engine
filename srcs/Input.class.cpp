#include "Input.class.hpp"

/* CONSTRUCTORS */

Input::Input(void) {
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

/* OPERATORS */

Input& Input::operator=(Input const & rhs) {
	(void)rhs;
	return *this;
}