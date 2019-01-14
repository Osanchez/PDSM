#include "stdafx.h"
#include <string>

#include "captains.h"

using namespace std;

Captain::Captain()
{
	name = "Captain";
	SP = 17;
}

Captain::Captain(string newName, int newSP)
{
	name = newName;
	SP = newSP;
}

void Captain::setName(string newName)
{
	name = newName;
}

string Captain::getName()
{
	return name;
}

void Captain::setSP(int newSP)
{
	SP = newSP;
}

int Captain::getSP()
{
	return SP;
}