// Chapter  6 Programming Project.cpp : This file contains the 'Rectangle Properties' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>

float perim(float L, float W);
float area(float L, float W);
float ver(float& L, float& W);
void setC(int, int);

int x = 20, y = 2;
int nL = 0, nS = 40;

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
        std::cout << std::setw(21) << std::left << "\nPerimeter:" << std::right << "Area:\n" << std::fixed << std::setprecision(2) << std::setw(20) << std::left << p << std::right << a << '\n' <<
            "\nWould you like to process another triangle?\n" << "Y or N: ";
        std::cin >> d;
        std::cout << '\n';
        system("cls");
    } while (d == 'Y' || d == 'y');
    if (d == 'N' || d == 'n') {
        std::cout << "Goodbye\n";
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
float ver(float& L, float& W) {
    int c = 0;
    while (std::cin.fail() || L < 0 || W < 0 ) {
        if (std::cin.fail()) {
            ++y;
            system("cls");
            std::cout << "Enter the side lengths of your triangle\n" << "*Please enter numeric values*\n" << std::setw(20) << std::left << "Length:" << std::right << "Width:\n";
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cin >> L;
            setC(x, y);
            std::cin >> W;
            --y;
            c++;
        }
        if (L < 0 && W < 0) {
            if (c == 1) {
                y++;
            }
            y += 3;
            std::cout << "Please enter positive side lengths\n" << std::setw(20) << std::left << "Length:" << std::right << "Width:\n";
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cin >> L;
            setC(x, y);
            std::cin >> W;
        }
        if (L < 0) {
            ++y;
            std::cout << "Please enter a posetive length: ";
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cin >> L;
        }
        if (W < 0) {
            ++y;
            std::cout << "Please enter a posetive width: ";
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cin >> W;
        }
        if (c) {
            y = 3;
        }
    }
    y = 2;
    return L, W;
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