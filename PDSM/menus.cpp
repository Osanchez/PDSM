#include "stdafx.h"
#include <string>
#include <iostream>
#include <iomanip>

#include "menus.h"
#include "constants.h"

using namespace std;

Menu::Menu()
{
}

void Menu::printTitle()
{
	for (int width = 0; width < maxWidth; width++)
		cout << topBorder;
	cout << endl; //prints the top border icon times the amount of character per line

	cout << " Marine Solider: Captain! We're being attacked by an unkown enemy! " << endl;
	cout << " " << endl;
	cout << " Captain: Sounds like we got trouble... " << endl;
	cout << " " << endl;
	cout << " Marine Solider: What are gonna do? " << endl;
	cout << " " << endl;
	cout << " Captain: We'll quickscope until we can get a killstreak. " << endl;
	cout << " " << endl;
	cout << " Marine Solider: Sir? What good will that do us? " << endl;
	cout << " " << endl;
	cout << " Captain: With enough kills we can send a lightning strike! " << endl;
	cout << " " << endl;
	cout << " Marine Solider: Um... Ok? " << endl;

	for (int width = 0; width < maxWidth; width++)
		cout << bottomBorder;
	cout << endl; //prints the bottom border icon times the amount of character per line
}

void Menu::printIntro()
{
	for (int width = 0; width < maxWidth; width++)
		cout << topBorder;
	cout << endl; //prints the top border icon times the amount of character per line

	cout << " Marine Solider: Captain! We're being attacked by an unkown enemy! " << endl;
	cout << " " << endl;
	cout << " Captain: Sounds like we got trouble... " << endl;
	cout << " " << endl;
	cout << " Marine Solider: What are gonna do? " << endl;
	cout << " " << endl;
	cout << " Captain: We'll quickscope until we can get a killstreak. " << endl;
	cout << " " << endl;
	cout << " Marine Solider: Sir? What good will that do us? " << endl;
	cout << " " << endl;
	cout << " Captain: With enough kills we can send a lightning strike! " << endl;
	cout << " " << endl;
	cout << " Marine Solider: Um... Ok? " << endl;

	for (int width = 0; width < maxWidth; width++)
		cout << bottomBorder;
	cout << endl; //prints the bottom border icon times the amount of character per line
}

void Menu::printRules()
{
	for (int width = 0; width < maxWidth; width++)
		cout << topBorder;
	cout << endl; //prints the top border icon times the amount of character per line

	cout << " " << endl;
	cout << " How To Be MLG: " << endl;
	cout << " " << endl;
	cout << " Place your ships on the map to start your fleet." << endl;
	cout << " " << endl;
	cout << " Select a coordinate to send a missile to it." << endl;
	cout << " " << endl;
	cout << " If you hit an enemy ship your radar will show an X." << endl;
	cout << " " << endl;
	cout << " If you you miss a strike your radar will show an O." << endl;
	cout << " " << endl;
	cout << " Careful now! The enemy will retaliate after every strike." << endl;
	cout << " " << endl;

	for (int width = 0; width < maxWidth; width++)
		cout << bottomBorder;
	cout << endl; //prints the bottom border icon times the amount of character per line
}

void Menu::printControls()
{
	for (int width = 0; width < maxWidth; width++)
		cout << topBorder;
	cout << endl; //prints the top border icon times the amount of character per line

	cout << " " << endl;
	cout << " Controls: " << endl;
	cout << " " << endl;
	cout << " W - Up; A - Left; S - Down; D - Right" << endl;
	cout << " " << endl;
	cout << " SPACEBAR - Strike coordinate" << endl;
	cout << " " << endl;
	cout << " ENTER - Open console" << endl;
	cout << " " << endl;
	cout << " C - Reopens control screen" << endl;
	cout << " " << endl;
	cout << " ESC - Exit game" << endl;
	cout << " " << endl;

	for (int width = 0; width < maxWidth; width++)
		cout << bottomBorder;
	cout << endl; //prints the bottom border icon times the amount of character per line
}