#ifndef LAYOUTNODE_H
#define LAYOUTNODE_H

#include "Room.h"

// holds the floor layout in a singly-linked linked list structure
// each node contains a pointer to a room object and a pointer to the next node
class LayoutNode {
private:
	Room* room;
	LayoutNode* next;

public:
	LayoutNode();
	LayoutNode(Room*);
	void addRoom(Room*); // should only be called on head node
	void deleteRoom(unsigned); // should only be called on head node
	void insertRoom(Room*); // should only be called on head node

	void setRoom(Room*);
	void setNext(LayoutNode*);

	Room* getRoom();
	LayoutNode* getNext();
};

#endif
