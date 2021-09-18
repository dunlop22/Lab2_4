#define _CRT_SECURE_NO_WARNINGS
#include "obchee.h"
#include <conio.h>

obchee new_obchee_info()
{
	obchee obchee_create;
	
		cout << "���������� ����� ���������� �� ����������\n\n������� ������ ����������: ";
		gets_s(obchee_create.name);
		while (strlen(obchee_create.name) == 0)
		{
			printf("������� ������� ������ ����������, ���������� ���: ");
			gets_s(obchee_create.name);
		}

		cout << "������� ��� ������� (2WD/4WD): ";
		gets_s(obchee_create.tip_privoda);
		while (strlen(obchee_create.tip_privoda) == 0)
		{
			printf("������� ������ ��� �������, ���������� ���: ");
			gets_s(obchee_create.tip_privoda);
		}

		cout << "������� ��� ������� (������/������/�������): ";
		gets_s(obchee_create.tip_topliva);
		while (strlen(obchee_create.tip_topliva) == 0)
		{
			printf("������� ������ ��� �������, ���������� ���: ");
			gets_s(obchee_create.tip_topliva);
		}

		cout << "������� ���������� ���������� ����: ";
		while (scanf("%lf", &obchee_create.kolvo_mest) != 1 || obchee_create.kolvo_mest < 0)
		{
			printf("������� �������� �������� ���������� ���������� ����, ���������� ���: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "������� ����� ������� �� 100��/�: ";
		while (scanf("%lf", &obchee_create.razgon_do_100) != 1 || obchee_create.razgon_do_100 < 0)
		{
			printf("������� �������� �������� ������� �� 100��/�, ���������� ���: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "������� ����� ����������: ";
		while (scanf("%lf", &obchee_create.massa) != 1 || obchee_create.massa < 0)
		{
			printf("������� �������� �������� �����, ���������� ���: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "������� ����� ��������� � ������: ";
		while (scanf("%lf", &obchee_create.obem_benzobaka) != 1 || obchee_create.obem_benzobaka < 0)
		{
			printf("������� �������� �������� ������ ���������, ���������� ���: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');
		return obchee_create;
}

obchee new_obchee(double kolvo_mest, double massa, char name[20], double razgon_do_100, char tip_privoda[20], char tip_topliva[20], double obem_benzobaka)
{
	obchee obchee_create;
	strcpy(obchee_create.name, name);
	strcpy(obchee_create.tip_privoda, tip_privoda);
	strcpy(obchee_create.tip_topliva, tip_topliva);
	obchee_create.massa = massa;
	obchee_create.obem_benzobaka = obem_benzobaka;
	obchee_create.razgon_do_100 = razgon_do_100;
	obchee_create.kolvo_mest = kolvo_mest;
	return obchee_create;
}

void prosmotr_obchee(obchee obchee1)
{
	if (obchee1.obem_benzobaka >= 0)
	{
		cout << "\n\n����� ����������:\n������: " << obchee1.name;
		cout << "\n��� �������: " << obchee1.tip_privoda;
		cout << "\n��� �������: " << obchee1.tip_topliva;
		cout << "\n���������� ���������� ����: " << obchee1.kolvo_mest;
		cout << "\n����� ������� �� 100��/�: " << obchee1.razgon_do_100;
		cout << "\n����� ���������: " << obchee1.obem_benzobaka;
		cout << "\n�����: " << obchee1.massa;
	}
	else
	{
		cout << "����� ���������� �����������";
	}
	
}

void obchee_name(obchee* obchee)
{
	if (&obchee->massa >= 0)
	{
		system("cls");
		cout << "������� ����� �������� ������: ";
		gets_s(obchee->name);
		while (strlen(obchee->name) == 0)
		{
			printf("������� ������� ������ ����������, ���������� ���: ");
			gets_s(obchee->name);
		}
	}
	else
	{
		cout << "����� ���������� �� �������.\n\n������� ����� ������� ��� �������� � �������� ����.";
		_getch();
	}
}