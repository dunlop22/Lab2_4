#include "koleso.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
using namespace std;

koleso new_koleso_info()
{
	koleso kolesa;
	system("cls");
	cout << "���������� ���������� � ������� ����������\n\n������� ������ ������: ";
	while (scanf("%lf", &kolesa.shirina) != 1 || kolesa.shirina < 0)
	{
		printf("������� ������� �������� ������ ������, ���������� ���: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');

	cout << "������� ������ ������: ";
	while (scanf("%lf", &kolesa.visota) != 1 || kolesa.visota < 0)
	{
		printf("������� ������� �������� ������ ������, ���������� ���: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');

	cout << "������� ������� ������ � ������: ";
	while (scanf("%lf", &kolesa.diametr) != 1 || kolesa.diametr < 0)
	{
		printf("������� ������� �������� �������� ������, ���������� ���: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');

	cout << "������� ��� ��������� ����� (���������/�����/�����): ";
	gets_s(kolesa.tip_diska);
	while (strlen(kolesa.tip_diska) == 0)
	{
		printf("������� ������ ��� ��������� �����, ���������� ���: ");
		gets_s(kolesa.tip_diska);
	}
	return kolesa;
}

//������� �������� ������
koleso new_koleso(double shirina, double visota, double diametr, char tip_diska[20])
{
	koleso koleso_create;
	strcpy(koleso_create.tip_diska, tip_diska);
	koleso_create.shirina = shirina;
	koleso_create.visota = visota;
	koleso_create.diametr = diametr;
	return koleso_create;
}

//������� ������ ���������� � ������
void prosmotr_koleso(koleso koleso_1)
{
	if (koleso_1.visota >= 0)
	{
		cout << "\n\n���������� � �������\n������ ������: " << koleso_1.shirina;
		cout << "\n������� ������: " << koleso_1.diametr;
		cout << "\n������ ������: " << koleso_1.visota;
		cout << "\n��� �����: " << koleso_1.tip_diska;
	}
	else
	{
		cout << "���������� � ������ ��� �� ���� ���������";
	}
}

void koleso_diamter(koleso* koleso1)
{
	if (koleso1->visota >= 0)
	{
		double diametr;
		cout << "������� ����� ������� ������ (����� ���� �������������): ";
		while (scanf("%lf", &diametr) != 1 || diametr < 0)
		{
			printf("������� ������� �������� ��������, ���������� ���: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');
		koleso1->diametr = diametr;
	}
	else
	{
		cout << "���������� � ������ ��� �� ���� ���������";
	}
}