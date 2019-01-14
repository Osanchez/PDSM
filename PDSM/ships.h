#pragma once
#include "stdafx.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

//Base Ship Definition
class Ship
{
public:
	Ship(); //default constructor
	Ship(string, char, int); //contructer that takes data and creates ship

	void setName(string); //sets name of ship
	string getName(); //gets name of ship
	void setIcon(char); //sets icon of ship
	char getIcon(); //gets icon of ship
	void setSize(int); //sets size of ship
	int getSize(); //gets size of ship

private:
	string name;
	char icon;
	int size;
};

//Fleet Array Object
class Fleet
{
public:
	Fleet(); //constructor that creates the fleet and stores it as an array

	Ship fleet[5];
};