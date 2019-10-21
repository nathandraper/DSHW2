#ifndef HOUSE_H
#define HOUSE_H

#include "LayoutNode.h"
#include "Room.h"
#include "Diagram.h"

// main class of the program
// maintains the state of the floor layout with a LayoutNode linked list containing rooms (in order added)
// updates the diagram class when rooms are added or deleted
// holds information about the entire house such as the allotted public and private space
class House
{
private:
	LayoutNode layoutHead;
	Diagram diagram;
	int width;
	int height;
	int publicSpace;
	int privateSpace;

public:
	House();
	House(unsigned, unsigned);
	void addRoom(Room*);
	void addRoom(unsigned x, unsigned y, unsigned width, unsigned height, unsigned num, string function, bool priv = false);
	void deleteRoom(unsigned);
	void resize(unsigned, unsigned);
	int squareFeet();
};

#endif
