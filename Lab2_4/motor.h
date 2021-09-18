#pragma once
struct motor
{
	char name[20];
	double rab_obem;
	double koni;
	double rasxod;
	double kol_vo_cilindr;
	double klapan;
};

motor new_motor_info();
motor new_motor(double koni, double rasxod, char name[20], double rab_obem, double kol_vo_cilindr, double klapan);
void prosmotr_motor(motor motorishe);
void motor_force(motor* motorishe);