#include "motor.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>

using namespace std;
motor new_motor_info()
{
	motor motor_create;
	cout << "Введите маркировку двигателя: ";
	gets_s(motor_create.name);
	while (strlen(motor_create.name) == 0)
	{
		printf("Неверно введена маркировка двигателя, попробуйте еще: ");
		gets_s(motor_create.name);
	}
	cout << "Введите рабочий объем двигателя в литрах: ";
	while (scanf("%lf", &motor_create.rab_obem) != 1 || motor_create.rab_obem < 0)
	{
		printf("Неверно введено значение объема двигателя, попробуйте еще: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');

	cout << "Введите количество лошадинных сил: ";
	while (scanf("%lf", &motor_create.koni) != 1 || motor_create.koni < 0)
	{
		printf("Неверно введено значение количества лошадиных сил, попробуйте еще: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');

	cout << "Введите средний расход топлива на 100км в литрах: ";
	while (scanf("%lf", &motor_create.rasxod) != 1 || motor_create.rasxod < 0)
	{
		printf("Неверно введено значение расхода на 100км, попробуйте еще: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');

	cout << "Введите количество цилиндров: ";
	while (scanf("%lf", &motor_create.kol_vo_cilindr) != 1 || motor_create.kol_vo_cilindr < 0)
	{
		printf("Неверно введено значение количества цилиндров, попробуйте еще: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');

	cout << "Введите количество клапанов на один цилиндр: ";
	while (scanf("%lf", &motor_create.klapan) != 1 || motor_create.klapan < 0)
	{
		printf("Неверно введено значение количества клапанов, попробуйте еще: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');

	return motor_create;
}

motor new_motor(double koni, double rasxod, char name[20], double rab_obem, double kol_vo_cilindr, double klapan)
{
	motor motor_create;
	strcpy(motor_create.name, name);
	motor_create.rab_obem = rab_obem;
	motor_create.koni = koni;
	motor_create.rasxod = rasxod;
	motor_create.kol_vo_cilindr = kol_vo_cilindr;
	motor_create.klapan = klapan;
	return motor_create;
}

void prosmotr_motor(motor motorishe)
{
	if (motorishe.koni >= 0)
	{
		cout << "\n\nИНФОРАЦИЯ О ДВИГАТЕЛЕ:\nМаркировка двигателя: " << motorishe.name;
		cout << "\nРабочий объем: " << motorishe.rab_obem;
		cout << "\nМощность (л.с.): " << motorishe.koni;
		cout << "\nСредний расход на 100км: " << motorishe.rasxod;
		cout << "\nКоличество цилиндров: " << motorishe.kol_vo_cilindr;
		cout << "\nКоличество клапанов на 1 цилиндр: " << motorishe.klapan;
	}
	else
	{
		cout << "Информация о двигателе отсутствует";
	}
}

void motor_force(motor* motorishe)
{
	if (motorishe->kol_vo_cilindr >= 0)
	{
		system("cls");
		double force;
		cout << "Введите количество дополнительных сил (кол-во может быть отрицательным): ";
		while (scanf("%lf", &force) != 1 || force + motorishe->koni < 0)
		{
			printf("Неверно введено значение количества лошадиных сил, попробуйте еще: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');
		motorishe->koni = motorishe->koni + force;
	}
	else
	{
		cout << "Не найден двигатель для добавления сил.\n\nНажмите любую клавишу для возврата в основное меню.";
		_getch();
	}
	
}
