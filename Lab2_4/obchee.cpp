#define _CRT_SECURE_NO_WARNINGS
#include "obchee.h"
#include <conio.h>

obchee new_obchee_info()
{
	obchee obchee_create;
	
		cout << "Добавление общей информации об автомобиле\n\nВведите модель автомобиля: ";
		gets_s(obchee_create.name);
		while (strlen(obchee_create.name) == 0)
		{
			printf("Неверно введена модель автомобиля, попробуйте еще: ");
			gets_s(obchee_create.name);
		}

		cout << "Введите тип привода (2WD/4WD): ";
		gets_s(obchee_create.tip_privoda);
		while (strlen(obchee_create.tip_privoda) == 0)
		{
			printf("Неверно введен тип привода, попробуйте еще: ");
			gets_s(obchee_create.tip_privoda);
		}

		cout << "Введите тип топлива (бензин/дизель/электро): ";
		gets_s(obchee_create.tip_topliva);
		while (strlen(obchee_create.tip_topliva) == 0)
		{
			printf("Неверно введен тип топлива, попробуйте еще: ");
			gets_s(obchee_create.tip_topliva);
		}

		cout << "Введите количество посадочных мест: ";
		while (scanf("%lf", &obchee_create.kolvo_mest) != 1 || obchee_create.kolvo_mest < 0)
		{
			printf("Неверно введенно значение количества посадочных мест, попробуйте еще: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "Введите время разгона до 100км/ч: ";
		while (scanf("%lf", &obchee_create.razgon_do_100) != 1 || obchee_create.razgon_do_100 < 0)
		{
			printf("Неверно введенно значение разгона до 100км/ч, попробуйте еще: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "Введите массу автомобиля: ";
		while (scanf("%lf", &obchee_create.massa) != 1 || obchee_create.massa < 0)
		{
			printf("Неверно введенно значение массы, попробуйте еще: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		cout << "Введите объем бензобака в литрах: ";
		while (scanf("%lf", &obchee_create.obem_benzobaka) != 1 || obchee_create.obem_benzobaka < 0)
		{
			printf("Неверно введенно значение объема бензобака, попробуйте еще: ");
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
		cout << "\n\nОБЩАЯ ИНФОРМАЦИЯ:\nМодель: " << obchee1.name;
		cout << "\nТип привода: " << obchee1.tip_privoda;
		cout << "\nТип топлива: " << obchee1.tip_topliva;
		cout << "\nКоличество посадочных мест: " << obchee1.kolvo_mest;
		cout << "\nВремя разгона до 100км/ч: " << obchee1.razgon_do_100;
		cout << "\nОбъем бензобака: " << obchee1.obem_benzobaka;
		cout << "\nМасса: " << obchee1.massa;
	}
	else
	{
		cout << "Общая информация отсутствует";
	}
	
}

void obchee_name(obchee* obchee)
{
	if (&obchee->massa >= 0)
	{
		system("cls");
		cout << "Введите новое название модели: ";
		gets_s(obchee->name);
		while (strlen(obchee->name) == 0)
		{
			printf("Неверно введена модель автомобиля, попробуйте еще: ");
			gets_s(obchee->name);
		}
	}
	else
	{
		cout << "Общая информация не найдена.\n\nНажмите любую клавишу для возврата в основное меню.";
		_getch();
	}
}