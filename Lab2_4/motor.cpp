#include "motor.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>

using namespace std;
motor new_motor_info()
{
	motor motor_create;
	cout << "������� ���������� ���������: ";
	gets_s(motor_create.name);
	while (strlen(motor_create.name) == 0)
	{
		printf("������� ������� ���������� ���������, ���������� ���: ");
		gets_s(motor_create.name);
	}
	cout << "������� ������� ����� ��������� � ������: ";
	while (scanf("%lf", &motor_create.rab_obem) != 1 || motor_create.rab_obem < 0)
	{
		printf("������� ������� �������� ������ ���������, ���������� ���: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');

	cout << "������� ���������� ���������� ���: ";
	while (scanf("%lf", &motor_create.koni) != 1 || motor_create.koni < 0)
	{
		printf("������� ������� �������� ���������� ��������� ���, ���������� ���: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');

	cout << "������� ������� ������ ������� �� 100�� � ������: ";
	while (scanf("%lf", &motor_create.rasxod) != 1 || motor_create.rasxod < 0)
	{
		printf("������� ������� �������� ������� �� 100��, ���������� ���: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');

	cout << "������� ���������� ���������: ";
	while (scanf("%lf", &motor_create.kol_vo_cilindr) != 1 || motor_create.kol_vo_cilindr < 0)
	{
		printf("������� ������� �������� ���������� ���������, ���������� ���: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');

	cout << "������� ���������� �������� �� ���� �������: ";
	while (scanf("%lf", &motor_create.klapan) != 1 || motor_create.klapan < 0)
	{
		printf("������� ������� �������� ���������� ��������, ���������� ���: ");
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
		cout << "\n\n��������� � ���������:\n���������� ���������: " << motorishe.name;
		cout << "\n������� �����: " << motorishe.rab_obem;
		cout << "\n�������� (�.�.): " << motorishe.koni;
		cout << "\n������� ������ �� 100��: " << motorishe.rasxod;
		cout << "\n���������� ���������: " << motorishe.kol_vo_cilindr;
		cout << "\n���������� �������� �� 1 �������: " << motorishe.klapan;
	}
	else
	{
		cout << "���������� � ��������� �����������";
	}
}

void motor_force(motor* motorishe)
{
	if (motorishe->kol_vo_cilindr >= 0)
	{
		system("cls");
		double force;
		cout << "������� ���������� �������������� ��� (���-�� ����� ���� �������������): ";
		while (scanf("%lf", &force) != 1 || force + motorishe->koni < 0)
		{
			printf("������� ������� �������� ���������� ��������� ���, ���������� ���: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');
		motorishe->koni = motorishe->koni + force;
	}
	else
	{
		cout << "�� ������ ��������� ��� ���������� ���.\n\n������� ����� ������� ��� �������� � �������� ����.";
		_getch();
	}
	
}
