#ifndef DIAGRAMEMPTY_H
#define DIAGRAMEMPTY_H

#include <exception>

class DiagramEmpty : public std::exception {
public :
	const char* what() const throw() override {
		return "Error: the floor diagram has no size.";
	}
};

#endif
