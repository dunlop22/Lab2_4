#pragma once
struct koleso
{
	double shirina;
	double visota;
	double diametr;
	char tip_diska[20];
};

void koleso_diamter(koleso* koleso1);
void prosmotr_koleso(koleso koleso_1);
koleso new_koleso(double shirina, double visota, double diametr, char tip_diska[20]);
koleso new_koleso_info();