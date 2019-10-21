#include "House.h"
#include "LayoutNode.h"
#include <string>

House::House() {
	this->width = 0;
	this->height = 0;
}

House::House(unsigned width, unsigned height) {
	this->width = width;
	this->height = height;

	this->layoutHead = LayoutNode();
}

void House::addRoom(Room* room) {
	this->layoutHead.addRoom(room);
}

//TODO: maybe implement this overload
void addRoom(unsigned x, unsigned y, unsigned width, unsigned height, unsigned num, string function, bool priv = false){}

void House::deleteRoom(unsigned num) {
	this->layoutHead.deleteRoom(num);
}
void House::resize(unsigned width, unsigned height) {
	this->width = width;
	this->height = height;
}
int House::squareFeet() {
	return this->width * this->height;
}
