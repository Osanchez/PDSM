#pragma once
#include <string>
using namespace std;

//GLOBAL CONSTANTS

//Marker Icons
const char hit = 'X';
const char miss = 'O';
const char water = 247; //double tilde
const char cursor = '*';
//Border Icons
const string topBorder = "=";
const string bottomBorder = "=";
const string sideBorder = "|";
//Dimensions
const int mapWidth = 20;
const int mapHeight = 10;
const int maxWidth = (mapWidth * 3) + 2;
//Misc
const int maxShips = 5;