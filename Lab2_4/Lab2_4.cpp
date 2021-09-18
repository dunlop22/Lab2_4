#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "voditel.h"
#include <windows.h>
#include <locale.h>
#include <conio.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    new_voditel_info();
    std::cout << "Hello World!\n";
}
