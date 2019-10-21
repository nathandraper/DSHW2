#ifndef NOSUCHROOM_H
#define NOSUCHROOM_H

#include <exception>

class NoSuchRoom : public std::exception {
public:
	const char* what() const throw() override {
		return "Error: room does not exist";
	}
};

#endif
