#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>

#include "maps.h"
#include "ships.h"
#include "constants.h"
#include "captains.h"
#include <windows.h>

using namespace std;

//Base Map Definition
Map::Map() //Creates map with default character
{
	for (int height = 0; height < mapHeight; height++)
	{
		for (int width = 0; width < mapWidth; width++)
		{
			map[height][width] = water;
		}
	}
}

void Map::setSelecting(bool newSelecting)
{
	selecting = newSelecting;
}

bool Map::getSelecting()
{
	return selecting;
}

void Map::printMap() //Prints the map
{
	for (int width = 0; width < maxWidth; width++)
		cout << topBorder;
	cout << endl; //prints the top border icon times the amount of character per line

	for (int height = 0; height < mapHeight; height++)
	{
		cout << sideBorder;
		for (int width = 0; width < mapWidth; width++)
		{
			cout << " " << map[height][width] << " ";
		}
		cout << sideBorder << endl;
	} //prints edge border, then space-icon-space patterns, and ends with edge border

	for (int width = 0; width < maxWidth; width++)
		cout << bottomBorder;
	cout << endl; //prints the bottom border icon times the amount of character per line
}

void Map::placeShip(int y, int x, Ship ship, string direction)
{
	if (direction == "Up")
	{
		for (int icons = ship.getSize(); icons > 0; icons--)
		{
			map[y - icons][x] = ship.getIcon();
		}
	}

	else if (direction == "Right")
	{
		for (int icons = ship.getSize(); icons > 0; icons--)
		{
			map[y][x + icons] = ship.getIcon();
		}
	}

	else if (direction == "Down")
	{
		for (int icons = ship.getSize(); icons > 0; icons--)
		{
			map[y + icons][x] = ship.getIcon();
		}
	}

	else if (direction == "Left")
	{
		for (int icons = ship.getSize(); icons > 0; icons--)
		{
			map[y][x - icons] = ship.getIcon();
		}
	}
}

void Map::placeGuess(int y, int x, Map shipMap)
{
	if (map[y][x] == cursor)
	{
		if (shipMap.map[y][x] != water)
		{
			map[y][x] = hit;
			shipMap.map[y][x] = hit;
			selecting = false;
		}

		else if (shipMap.map[y][x] == water)
		{
			map[y][x] = miss;
			shipMap.map[y][x] = miss;
			selecting = false;
		}
	}

	else if (map[y][x] == hit || map[y][x] == miss)
	{
		cout << "You already guessed there!" << endl;
		system("pause");
	}

	else
		cout << "Invalid coordinates!" << endl;
}

void Map::placeCursor(char cursor)
{
	int y = 0;
	int x = 0;
	bool placed = false;

	while (placed == false)
	{
		y = rand() % mapHeight;
		x = rand() % mapWidth;

		if (map[y][x] == water)
		{
			map[y][x] = cursor;
			placed = true;
		}
	}
}

bool Map::checkSpaces(int y, int x, string direction, int size) //checks for water marks in specific direction
{
	if (direction == "Up")
	{
		bool checks = true;
		for (int spaces = size; spaces > 0; spaces--)
		{
			if (map[y - spaces][x] != water)
			{
				checks = false;
				spaces = 0;
			}
		}
		return checks;
	}

	else if (direction == "Down")
	{
		bool checks = true;
		for (int spaces = size; spaces > 0; spaces--)
		{
			if (map[y + spaces][x] != water)
			{
				checks = false;
				spaces = 0;
			}
		}
		return checks;
	}

	else if (direction == "Right")
	{
		bool checks = true;
		for (int spaces = size; spaces > 0; spaces--)
		{
			if (map[y][x + spaces] != water)
			{
				checks = false;
				spaces = 0;
			}
		}
		return checks;
	}

	else if (direction == "Left")
	{
		bool checks = true;
		for (int spaces = size; spaces > 0; spaces--)
		{
			if (map[y][x - size] != water)
			{
				checks = false;
				spaces = 0;
			}
		}
		return checks;
	}
}

void Map::moveCursor(string move, Captain &captain)
{
	system("CLS");
	int y, x;
	int nextPoint;
	selecting = true;

	for (int height = 0; height < mapHeight; height++)
	{
		for (int width = 0; width < mapWidth; width++)
		{
			if (map[height][width] == cursor)
			{
				y = height;
				x = width;
			}
		}
	} //scans the entire map for the cursor

	if (move == "w") //if player wants to move up
	{
		nextPoint = y - 1;
		if (map[nextPoint][x] == water)
		{
			map[nextPoint][x] = cursor;
			map[nextPoint + 1][x] = water;
		}
	}

	else if (move == "s") //if player wants to move down
	{
		nextPoint = y + 1;
		if (map[nextPoint][x] == water)
		{
			map[nextPoint][x] = cursor;
			map[nextPoint - 1][x] = water;
		}
	}

	else if (move == "d") //if player wants to move left
	{
		nextPoint = x + 1;
		if (map[y][nextPoint] == water)
		{
			map[y][nextPoint] = cursor;
			map[y][nextPoint - 1] = water;
		}
	}

	else if (move == "a") //if player wants to move right
	{
		nextPoint = x - 1;
		if (map[y][nextPoint] == water)
		{
			map[y][nextPoint] = cursor;
			map[y][nextPoint + 1] = water;
		}
	}

	else if (move == "l") //player wants to toggle directions
	{
		if (captain.direction == "Up")
			captain.direction = "Right";
		else if (captain.direction == "Right")
			captain.direction = "Down";
		else if (captain.direction == "Down")
			captain.direction = "Left";
		else if (captain.direction == "Left")
			captain.direction = "Up";
	}

	else if (move == "SPACE") //if player wants to select current location
	{
		captain.currentY = y;
		captain.currentX = x;
		selecting = false;
	}
}