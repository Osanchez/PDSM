#pragma once
#include <string>

using namespace std;

class Menu
{
public:
	Menu();

	void printTitle(); //prints title screen
	void printIntro(); //prints intro screen
	void printRules(); //prints rules screen
	void printControls(); //prints controls screen
};