// Chapter  6 Programming Project.cpp : This file contains the 'Rectangle Properties' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <windows.h>

float perim(float L, float W);
float area(float L, float W);
float ver(float L, float W);
void setC(int, int);

int x = 20, y = 2;

int main()
{
    char d;
    do {
        std::cout << "Enter the side lengths of your triangle\n" << std::setw(20) << std::left << "Length:" << std::right << "Width:\n";
        float L, W;
        std::cin >> L;
        setC(x, y);
        std::cin >> W;
        ver(L, W);
        float p = perim(L, W);
        float a = area(L, W);
        std::cout << std::setw(20) << std::left << "\nPerimeter:" << std::right << "Area:\n" << std::fixed << std::setprecision(2) << std::setw(15) << std::right << p << std::left << a << '\n';
        std::cout << "\nWould you like to process another triangle?\n" << "Y or N: ";
        std::cin >> d;
        std::cout << '\n';
        y = y + 5;
    } while (d == 'Y' || d == 'y');
    if (d == 'N' || d == 'n') {
        return 0;
    }

    return 0;
}

float perim(float L, float W) {
    return 2 * L + 2 * W;
}
float area(float L, float W) {
    return L * W;
}
float ver(float L, float W) {
    while (L < 0 || W < 0) {
        if (L < 0) {
            std::cout << "Please enter a posetive length: ";
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cin >> L;
            return L;
        }
        if (W < 0) {
            std::cout << "Please enter a posetive width: ";
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cin >> W;
            return W;
        }
        if(L < 0 && W < 0) {
            std::cout << "Please enter positive side lengths\n" << std::setw(20) << std::left << "Length:" << std::right << "Width:";
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cin >> L;
            std::cin.clear();
            std::cin.ignore(256, '\n');
            setC(x, y);
            std::cin >> W;
            return L, W;
        }
    }
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