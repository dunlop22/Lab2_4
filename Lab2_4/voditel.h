#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct voditel
{
    char name[20];
    double age;
    double stag;
    char pol[20];
    char covid_19[20];
};

voditel new_voditel_info();
voditel new_voditel(double age, double stag, char name[20], char pol[20], char covid_19[20]);
void prosmotr_voditel(voditel vod);
void voditel_covid(voditel* vod, char covid[20]);

