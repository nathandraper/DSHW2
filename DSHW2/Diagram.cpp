#include "Diagram.h"
#include "DiagramEmpty.h"
#include "Room.h"

const char EMPTY_CHAR = '*';

Diagram::Diagram() {
	diagram = "";
	width = 0;
	height = 0;
}

Diagram::Diagram(unsigned width, unsigned height) {
	this->width = width;
	this->height = height;
	this->diagram = string(width * height, EMPTY_CHAR);

}

// modifies the diagram string to include the room string at the position specified by room
// TODO: the function should not override walls/doors from adjacent rooms (or should it?)
void Diagram::addRoom(Room& room) {
	unsigned pos;
	unsigned line = room.getY() - 1;
	const unsigned roomWidth = room.getWidth();
	const unsigned roomHeight = room.getHeight();
	const unsigned x = room.getX();
	const string roomDiagram = room.getDiagram();

	while (line < roomHeight) {
		pos = line * this->width + x;
		this->diagram.replace(pos, roomWidth, roomDiagram, line * roomWidth, roomWidth);

		line++;
	}
}

// removes the room string at the position specified by the room from the diagram string
// replaces the room's substrings with the EMPTY_CHAR character
// TODO: the function should not delete walls/doors from adjacent rooms
void Diagram::deleteRoom(Room& room) {
	unsigned pos;
	unsigned line = room.getY() - 1;
	const unsigned roomWidth = room.getWidth();
	const unsigned roomHeight = room.getHeight();
	const unsigned x = room.getX();

	while (line < roomHeight) {
		pos = line * this->width + x;
		this->diagram.replace(pos, roomWidth, roomWidth, EMPTY_CHAR);

		line++;
	}
}

// output the diagram string to a stream (file or cout) separated correctly by newlines
void Diagram::printDiagram(fstream& stream) {
	if (this->width < 1 || this->height < 1) {
		throw DiagramEmpty();
	}

	unsigned line = 0;

	while (line < this->height) {
		stream << this->diagram.substr(line * this->width, this->width) << endl;
		line++;
	}
}

