#include "LayoutNode.h"
#include "Room.h"
#include "NoSuchRoom.h"

LayoutNode::LayoutNode() {
	this->room = nullptr;
	this->next = nullptr;
}

LayoutNode::LayoutNode(Room* room) {
	this->room = room;
	this->next = nullptr;
}

void LayoutNode::addRoom(Room* room) {
	LayoutNode* curr = this;
	LayoutNode* newNode = new LayoutNode(room);

	while (curr->getNext()) {
		curr = curr->getNext();
	}
	curr->setNext(newNode);

}

// room numbers are zero based
void LayoutNode::deleteRoom(unsigned number) {
	LayoutNode* curr = this;
	LayoutNode* prev = this;
	while (number >= 0) {
		if (!curr->getNext()) {
			throw NoSuchRoom();
		}
		prev = curr;
		curr = curr->next;
		number--;
	}

	prev->setNext(curr->next);
	delete curr->getRoom();
	delete curr;
}

// TODO: implement
void LayoutNode::insertRoom(Room*) {}

void LayoutNode::setRoom(Room* room) {
	this->room = room;
}

void LayoutNode::setNext(LayoutNode* next) {
	this->next = next;
}

Room* LayoutNode::getRoom() {
	return this->room;
}
LayoutNode* LayoutNode::getNext() {
	return this->next;
}