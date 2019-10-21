#include "Room.h"
#include <string>

using namespace std;

// helper function to make labels for diagram string
string makeLabel(string label, unsigned width);

Room::Room(){
	this->priv = false;
	this->x = 0;
	this->y = 0;
	this->width = 0;
	this->height = 0;
	this->function = "";
	this->diagram = "";
}

Room::Room(unsigned x, unsigned y, unsigned width, unsigned height, unsigned num, string function, bool priv = false){
	this->priv = priv;
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->function = function;
	this->diagram = "";
	
	this->makeDiagram();
}

// assume a minimum width of 10, minimum height of 5
// might have to change this for hallways
// currently, I have designed the room diagram string to simply be a labeled box sort of like this:
// ___________________
// |kitchen          |
// |10x10            |
// |public           |
// ___________________
//
// TODO: account for windows/doors
// TODO: hallways will need smaller dimensions
void Room::makeDiagram() {
	string diagram;
	string dimensions;

	// upper wall
	diagram.append(this->width, '-');
	
	// label with function
	diagram.append(makeLabel(this->function, this->width));

	// label with dimensions
	dimensions = to_string(this->width);
	dimensions.append("x");
	dimensions.append(to_string(this->height));
	diagram.append(makeLabel(dimensions, this->width));

	// label with access
	if (this->priv) {
		diagram.append(makeLabel("private", this->width));
	}
	else {
		diagram.append(makeLabel("public", this->width));
	}
	
	// fill with space
	for (int i = 3; i < this->height; i++) {
		diagram.append("|");
		diagram.append(this->width, ' ');
		diagram.append("|");
	}

	// lower wall
	diagram.append(this->width, '-');

	this->diagram = diagram;
}

void Room::resize(unsigned width, unsigned height) {
	this->width = width;
	this->height = height;
	this->makeDiagram();
}

void Room::move(unsigned x, unsigned y) {
	this->x = x;
	this->y = y;
}

void Room::setFunction(string function) {
	this->function = function;
	this->makeDiagram();
}

void Room::setPriv(bool priv) {
	this->priv = priv;
	this->makeDiagram();
}

// getters
bool Room::isPrivate() {
	return this->priv;
}

int Room::getX() {
	return this->x;
}

int Room::getY() {
	return this->y;
}

int Room::getWidth() {
	return this->width;
}

int Room::getHeight() {
	return this->height;
}

string Room::getFunction() {
	return this->function;
}

string Room::getDiagram() {
	return this->diagram;
}

int Room::squareFeet() {
	return this->width * this->height;
}

string makeLabel(string label, unsigned width) {
	string str = "";

	str.append("|");
	str.append(label);
	str.append(width - label.size(), ' ');

	return str;
}
