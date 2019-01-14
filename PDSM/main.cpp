// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <iomanip>

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
	else if (key == 108)
		return "l";
	else
		return " ";
}

bool static validateCoord(int y, int x, string direction, int size) //takes in one part of the coord, axis, and ship to validate coordinates
{
	if (direction == "Right")
	{
		if ((x + size) <= mapWidth)
			return true;
		else
			return false;
	}

	else if (direction == "Up")
	{
		if ((y - size) >= 0)
			return true;
		else
			return false;
	}

	else if (direction == "Left")
	{
		if ((x - size) >= 0)
			return true;
		else
			return false;
	}

	else if (direction == "Down")
	{
		if ((y + size) <= mapHeight)
			return true;
		else
			return false;
	}
}

void static playerPrepPhase(Map &playerShipMap, Captain &player, Fleet &playerFleet)
{
	string move;
	int shipsDone = 0;
	bool valid, checks;
	//sets up variables

	playerShipMap.placeCursor(cursor); //places cursor randomly in the map

	while (shipsDone < maxShips) //while there are ships to be placed
	{

		playerShipMap.setSelecting(true); //set the "selecting" variable to true
		while (playerShipMap.getSelecting() != false) //until the player is done choosing
		{
			system("cls");
			playerShipMap.printMap();
			cout << ">>> Placing " << playerFleet.fleet[shipsDone].getName() << " - " << playerFleet.fleet[shipsDone].getSize() << " Spaces going " << player.direction << endl;
			move = readKeys();
			playerShipMap.moveCursor(move, player); //move cursor around and save coords to Captain X and Y
		} //loops until player chooses a coordinate
		
		valid = validateCoord(player.currentY, player.currentX, player.direction, playerFleet.fleet[shipsDone].getSize());
		checks = playerShipMap.checkSpaces(player.currentY, player.currentX, player.direction, playerFleet.fleet[shipsDone].getSize());

		if (valid == true && checks == true) //if y and x coords are valid
		{
			playerShipMap.placeShip(player.currentY, player.currentX, playerFleet.fleet[shipsDone], player.direction);
			shipsDone++;
			system("cls");
			playerShipMap.printMap();
		}

		else
		{
			playerShipMap.printMap();
			cout << ">>> Error: Invalid placement!" << endl;
			system("pause");
		}

	} //did nested while loop because for loop was giving issues for some reason
}

void static enemyPrepPhase(Map &enemyShipMap, Captain &enemy, Fleet &enemyFleet)
{
	int shipsDone = 0;
	bool valid, checks;
	int randDirection;
	//sets up variables

	while (shipsDone < maxShips) //while there are ships to be placed
	{
		enemy.currentY = rand() % mapHeight;
		enemy.currentX = rand() % mapWidth;

		randDirection = rand() % 4; //choose randomly out of "up, down, left, and right"
		if (randDirection == 1)
			enemy.direction = "Up";
		else if (randDirection == 2)
			enemy.direction = "Down";
		else if (randDirection == 3)
			enemy.direction == "Right";
		else if (randDirection == 4)
			enemy.direction == "Left";

		valid = validateCoord(enemy.currentY, enemy.currentX, enemy.direction, enemyFleet.fleet[shipsDone].getSize());
		checks = enemyShipMap.checkSpaces(enemy.currentY, enemy.currentX, enemy.direction, enemyFleet.fleet[shipsDone].getSize());

		if (valid == true && checks == true) //if y and x coords are valid
		{
			enemyShipMap.placeShip(enemy.currentY, enemy.currentX, enemyFleet.fleet[shipsDone], enemy.direction);
			shipsDone++;
		}

	} //did nested while loop because for loop was giving issues for some reason
}

void static attack(Captain &attacker, Map &attackerMap, Captain &defender, Map &defenderMap)
{
	string move;

	while (attackerMap.getSelecting() != false) //until the player is done choosing
	{
		system("cls");
		attackerMap.printMap();
		cout << ">>> Choose position to fire cannon: " << attacker.currentY << ", " << attacker.currentX << endl;
		move = readKeys();
		attackerMap.moveCursor(move, attacker); //move cursor around and save coords to Captain X and Y
	} //loops until player chooses a coordinate
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
	Captain player;
	Map playerShipMap;
	Map playerChoiceMap;
	playerPrepPhase(playerShipMap, player, playerFleet);
	cout << ">>> Enemy is now placing ships..." << endl;
	system("pause");

	//Prepare's Enemy's maps
	Captain enemy;
	Map enemyShipMap;
	Map enemyChoiceMap;
	enemyPrepPhase(enemyShipMap, enemy, playerFleet);

	system("cls");
	enemyShipMap.printMap();

	system("pause");
	system("cls");
	return 0;
}

