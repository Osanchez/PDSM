#pragma once
#include "stdafx.h"
#include <string>

using namespace std;

class Captain
{
public:
	Captain(); //default constructor
	Captain(string, int); //custom constructor

	int currentY = 0; //stores current coords from cursor
	int currentX = 0; //stores current coords from cursor
	string direction = "Up"; //stores current direction

	void setName(string); //sets name of captain
	string getName(); //returns name of captain

	void setSP(int); //sets SP of captain
	int getSP(); //returns SP of captain

private:
	int SP = 17; //total amount of "sizes" for all ships
	string name; //name of captain
};