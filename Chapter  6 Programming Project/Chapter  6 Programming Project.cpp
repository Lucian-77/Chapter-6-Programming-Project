// Chapter  6 Programming Project.cpp : This file contains the 'Fahrenheit to Celcius' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <limits>
#include <windows.h>

int north = 0, south = 0, east = 0, west = 0;
int x = 6, y = 2;
std::string region;

float input(int x);
void setC(int x, int y);
std::string analize(int& north, int& south, int& east, int& west);
void disp(std::string region);

int main()
{
	std::cout << "How many accidents occured in each region of the city last year\n" << std::setw(10) << "North" << std::setw(10) << "South" << std::setw(10) << "East" << std::setw(10) << "West\n";
	input(x);
	analize(north, south, east, west);
	disp(region);
}

float input(int x) {
	for (int i = 1; i <= 4; i++) {
		switch (i) {
		case 1: setC(x, y);
			std::cin >> north;
			break;
		case 2: x += 10;
			setC(x, y);
			std::cin >> south;
			break; 
		case 3: x += 11;
			setC(x, y);
			std::cin >> east;
			break;
		case 4: x += 9;
			setC(x, y);
			std::cin >> west;
		}
	} 
	return north, south, east, west;
}
std::string analize(int& north, int& south, int& east, int& west) {
	std::vector<int> data = { north, south, east, west };
	int minV = *std::min_element(data.begin(), data.end());
	if (minV == data[0]) {
		region = "North";
	}
	if (minV == data[1]) {
		region = "South";
	}
	if (minV == data[2]) {
		region = "East";
	}
	if (minV == data[3]) {
		region = "West";
	}
	return region;
}
void disp(std::string region){
	std::cout << "\n\nThe region with the least accidents was " << region << "\n\n";
}
void setC(int x = 0, int y = 0)
{
	HANDLE handle;
	COORD coordinates;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	coordinates.X = x;
	coordinates.Y = y;
	SetConsoleCursorPosition(handle, coordinates);
}