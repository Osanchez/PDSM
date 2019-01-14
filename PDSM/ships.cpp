#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>

#include "ships.h"

using namespace std;

//Base Ship Definition
Ship::Ship()
{
	name = "Ship";
	icon = '+';
	size = 1;
}

Ship::Ship(string newName, char newIcon, int newSize)
{
	setName(newName);
	setIcon(newIcon);
	setSize(newSize);
}

void Ship::setName(string newName)
{
	name = newName;
}

string Ship::getName()
{
	return name;
}

void Ship::setIcon(char newIcon)
{
	icon = newIcon;
}

char Ship::getIcon()
{
	return icon;
}

void Ship::setSize(int newSize)
{
	size = newSize;
}

int Ship::getSize()
{
	return size;
}

//Fleet Definition
Fleet::Fleet()
{
	Ship destroyer("Destroyer", 'D', 2);
	Ship submarine("Submarine", 'S', 2);
	Ship cruiser("Cruiser", 'Z', 3);
	Ship battleship("Battleship", 'B', 4);
	Ship carrier("Carrier", 'R', 5);
	//creates all ships for captain

	fleet[0] = destroyer;
	fleet[1] = submarine;
	fleet[2] = cruiser;
	fleet[3] = battleship;
	fleet[4] = carrier;
	//stores the ships as an array
}