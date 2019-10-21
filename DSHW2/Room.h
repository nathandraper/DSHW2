#ifndef ROOM_H
#define ROOM_H

#include <string>

using namespace std;

// room class responsible for the dimensions, locations, and graphical diagram for each room
// TODO: account for doors/windows
// TODO: figure out how to do hallways (may not be regularly shaped and may require other dimensions
class Room
{
private:
	bool priv;
	int x;
	int y;
	int width;
	int height;
	string function;
	string diagram;

	void makeDiagram();

public:
	Room();
	Room(unsigned x, unsigned y, unsigned width, unsigned height, unsigned num, string function, bool priv);

	void resize(unsigned, unsigned);
	void move(unsigned, unsigned);
	void setFunction(string);
	void setPriv(bool);

	bool isPrivate();
	int getX();
	int getY();
	int getWidth();
	int getHeight();
	string getFunction();
	string getDiagram();
	int squareFeet();

};

#endif

