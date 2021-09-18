#pragma once
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

struct obchee
{
    char name[20];
    char tip_privoda[20];
    char tip_topliva[20];
    double massa;
    double obem_benzobaka;
    double kolvo_mest;
    double razgon_do_100;
}; 

obchee new_obchee_info();
obchee new_obchee(double kolvo_mest, double massa, char name[20], double razgon_do_100, char tip_privoda[20], char tip_topliva[20], double obem_benzobaka);
void prosmotr_obchee(obchee obchee1);
void obchee_name(obchee* obchee);