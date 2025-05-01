// Chapter  6 Programming Project.cpp : This file contains the 'Fahrenheit to Celcius' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <windows.h>

float fS, three = 3.00;
int x, y = 3;

float finalScore(float s1, float s2, float s3, float s4, float s5);
float ver(float& s1, float& s2, float& s3, float& s4, float& s5);
void setC(int x, int y);

int main()
{
    std::cout << std::setw(38) << std::right << "Enter each judge's score\n" << "----------------------------------------------------\n" << std::setw(11) << std::left << "Judge 1:" << std::setw(11)
        << std::left << "Judge 2:" << std::setw(11) << std::left << "Judge 3:" << std::setw(11) << std::left << "Judge 4:" << std::right << "Judge 5:\n";
    float s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0;
    setC(2, y);
    std::cin >> s1;
    setC(13, y);
    std::cin >> s2;
    setC(24, y);
    std::cin >> s3;
    setC(35, y);
    std::cin >> s4;
    setC(46, y);
    std::cin >> s5;
    ver(s1, s2, s3, s4, s5);
    finalScore(s1, s2, s3, s4, s5);
    std::cout << std::fixed << std::setprecision(2) << "\n\nThis contestants final score is " << fS << '\n\n';
}

float finalScore(float s1, float s2, float s3, float s4, float s5) {
    std::vector<float> scores = { s1, s2, s3, s4, s5 };
    std::sort(scores.begin(), scores.end());
    scores.erase(scores.begin() + 4);
    scores.erase(scores.begin() + 0);
    fS = (std::accumulate(scores.begin(), scores.end(), 0.0)) / three;
    return fS;
}
float ver(float& s1, float& s2, float& s3, float& s4, float& s5) {
    while (std::cin.fail() || s1 < 0 || s2 < 0 || s3 < 0 || s4 < 0 || s5 < 0 || s1 > 10 || s2 > 10 || s3 > 10 || s4 > 10 || s5 > 10) {
        system("cls");
        std::cout << std::setw(38) << std::right << "Enter each judge's score\n" << "----------------------------------------------------\n" << std::setw(11) << std::left << "Judge 1:" 
            << std::setw(11) << std::left << "Judge 2:" << std::setw(11) << std::left << "Judge 3:" << std::setw(11) << std::left << "Judge 4:" << std::right 
            << "Judge 5:\n\n*Please input valid judging scores*";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        setC(2, y);
        std::cin >> s1;
        setC(13, y);
        std::cin >> s2;
        setC(24, y);
        std::cin >> s3;
        setC(35, y);
        std::cin >> s4;
        setC(46, y);
        std::cin >> s5;
    }
    return s1, s2, s3, s4, s5;
}
void setC(int x, int y)
{
    HANDLE handle;
    COORD coordinates;
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(handle, coordinates);
}