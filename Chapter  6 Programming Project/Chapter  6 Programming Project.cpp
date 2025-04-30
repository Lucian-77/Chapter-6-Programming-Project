// Chapter  6 Programming Project.cpp : This file contains the 'Fahrenheit to Celcius' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <windows.h>

float f = 0.0f;

float cel(float f);

int main()
{
	std::cout << std::setw(24) << std::left << "  Fahrenheit" << std::right << "Celcius  \n-----------------------------------\n";
	for (f = 1; f < 20; f++) {
		std::cout << std::fixed << std::setprecision(2) << std::setw(13) << std::left << f << std::right << cel(f) << '\n';
	}
}

float cel(float f) {
	return (5 * (f - 32)) / 9;
}