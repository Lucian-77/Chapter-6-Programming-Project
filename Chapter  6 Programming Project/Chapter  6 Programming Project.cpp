// Chapter  6 Programming Project.cpp : This file contains the 'Fahrenheit to Celcius' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>
#include <windows.h>

float sqFt = 0.0f;
int x = 0, y = 6;

float squareFeet(float nOR);
void calcData(float sqFt, float pCost);
void setC(int x, int y);

int main()
{
	std::cout << "How much does the paint color cost per gallon: $";
	float pCost;
	std::cin >> pCost;
	std::cout << "\nHow many rooms do you want painted: ";
	float nOR;
	std::cin >> nOR;
	squareFeet(nOR);
	calcData(sqFt, pCost);
}

float squareFeet(float nOR) {
	std::cout << "\nHow many square feet is each room?\n";
	std::vector<float> sqFtV = { 0 };
	for (int i = 1; i <= nOR; i++) {
		std::cout << "Room " << i << ":     ";
	}
	for (int i = 1; i <= nOR; i++) {
		float sF;
		setC(x, y);
		std::cin >> sF;
		sqFtV.push_back(sF);
		x += 12;
	}
	return sqFt = std::accumulate(sqFtV.begin(), sqFtV.end(), 0.0);
}
void calcData(float sqFt, float pCost) {
	float gPaint = sqFt / 110;
	float hLabor = (sqFt / 110) * 8;
	float tPCost = (sqFt / 110) * pCost;
	float lCost = (sqFt / 110) * 25;
	float tCost = (sqFt / 110) * (pCost + 200);
	std::cout << "\n------------------------------------------"
		<< std::fixed << std::setprecision(2) << std::setw(21) << std::left << "\n| Paint required" << std::setw(4)  << "||" << std::setw(8) << gPaint << " Gallons |\n"
		<< std::setw(21) << std::left << "\n| Labor required" << std::setw(4) << "||" << std::setw(10) << std::left << hLabor << std::left << " Hours |\n"
		<< std::setw(21) << std::left << "\n| Cost of labor" << std::setw(4) << "||" << std::setw(12) << std::left << lCost << " USD |\n"
		<< std::setw(21) << std::left << "\n| Cost of Paint" << std::setw(4) << "||" << std::setw(12) << std::left << tPCost << " USD |\n"
		<< std::setw(21) << std::left << "\n| Total cost" << std::setw(4) << "||" << std::setw(12) << std::left << tCost << " USD |\n"
		<< "------------------------------------------\n\n";
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