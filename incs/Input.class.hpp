#ifndef INPUT_CLASS_HPP
# define INPUT_CLASS_HPP

#include <iostream>

class Input {
public:
	Input(void);
	Input(Input const & src);
	virtual ~Input(void);

	Input& operator=(Input const & rhs);
private:
	
};

#endif