#pragma once
//Defines all the properties of maps and their inheritance.

#include <string>

#include "ships.h"
#include "captains.h"

using namespace std;

//Base Map Definition
class Map
{
public:
	Map(); //constructor that inputs default character

	void printMap(); //prints the map

	void placeCursor(char); //places cursor in specific coordinates
	void placeShip(int, int, Ship, string); //places ship in specific coordinates
	void placeGuess(int, int, Map); //places guess in specific coordinates

	void setSelecting(bool); //sets selecting true or false
	bool getSelecting(); //returns selecting bool

	void moveCursor(string, Captain &); //moves cursor around to select a coordinate
	bool checkSpaces(int, int, string, int); //checks to see if spaces are empty

	char map[10][20]; //hard coded numbers for now because this is easier
	bool selecting; //to determine when player is selecting a coord
};