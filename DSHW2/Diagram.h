#ifndef DIAGRAM_H
#define DIAGRAM_H

#include <string>
#include <fstream>
#include "room.h"

using namespace std;

// maintains the human readable representation of the floor layout
// holds a single diagram string and will output to terminal or a file with formatting
// TODO: hallways, doors, and windows
class Diagram
{
private:
	string diagram;
	unsigned width;
	unsigned height;

public:
	Diagram();
	Diagram(unsigned, unsigned);
	void addRoom(Room&);
	void deleteRoom(Room&);
	void printDiagram(fstream&);

};

#endif

