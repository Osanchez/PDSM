// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

#include "maps.h"
#include "ships.h"
#include "menus.h"
#include "constants.h"
#include "captains.h"
#include <windows.h>

using namespace std;


string static readKeys() //switches console mode to read keys and once done goes back to normal
{
	HANDLE hstdin;
	DWORD  mode;

	hstdin = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(hstdin, &mode);
	SetConsoleMode(hstdin, ENABLE_ECHO_INPUT | ENABLE_PROCESSED_INPUT);

	cin.clear();
	int key = cin.get();
	SetConsoleMode(hstdin, mode);

	if (key == 97)
		return "a";
	else if (key == 100)
		return "d";
	else if (key == 119)
		return "w";
	else if (key == 115)
		return "s";
	else if (key == 32)
		return "SPACE";
	else if (key == 105)
		return "l";
	else
		return " ";
}

int main()
{
	//Prints Introduction Screens
	Menu menu;
	menu.printIntro();
	system("pause");
	system("cls");
	menu.printRules();
	system("pause");
	system("cls");
	menu.printControls();
	system("pause");
	system("cls");

	//Creates Ships for both sides and stores as object arrays
	Fleet playerFleet;
	Fleet enemyFleet;

	//Prepeares Player's maps
	Captain player("Player", 17);
	Map playerShipMap;
	Map playerChoiceMap;
	string move;

	for (int ships = 0; ships < 5; ships++) //for every ship in the array of fleet
	{
		playerShipMap.placeCursor(cursor); //place cursor

		while (playerShipMap.getSelecting() != false) //until the player is done choosing
		{
			playerShipMap.printMap();
			move = readKeys();
			playerShipMap.moveCursor(move, player); //move cursor around and save coords to Captain X and Y
		}

		playerShipMap.placeShip(player.currentX, player.currentY, playerFleet.fleet[ships], player.direction);
	}
	
	system("pause");
	return 0;
}

