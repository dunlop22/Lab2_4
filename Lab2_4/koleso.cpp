#include "koleso.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
using namespace std;

koleso new_koleso_info()
{
	koleso kolesa;
	system("cls");
	cout << "Добавление информации о колесах автомобиля\n\nВведите ширину колеса: ";
	while (scanf("%lf", &kolesa.shirina) != 1 || kolesa.shirina < 0)
	{
		printf("Неверно введено значение ширины колеса, попробуйте еще: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');

	cout << "Введите высоту колеса: ";
	while (scanf("%lf", &kolesa.visota) != 1 || kolesa.visota < 0)
	{
		printf("Неверно введено значение высоты колеса, попробуйте еще: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');

	cout << "Введите диаметр колеса в дюймах: ";
	while (scanf("%lf", &kolesa.diametr) != 1 || kolesa.diametr < 0)
	{
		printf("Неверно введено значение диаметра колеса, попробуйте еще: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');

	cout << "Введите тип колесного диска (штамповка/литье/ковка): ";
	gets_s(kolesa.tip_diska);
	while (strlen(kolesa.tip_diska) == 0)
	{
		printf("Неверно введен тип колесного диска, попробуйте еще: ");
		gets_s(kolesa.tip_diska);
	}
	return kolesa;
}

//функция создания колеса
koleso new_koleso(double shirina, double visota, double diametr, char tip_diska[20])
{
	koleso koleso_create;
	strcpy(koleso_create.tip_diska, tip_diska);
	koleso_create.shirina = shirina;
	koleso_create.visota = visota;
	koleso_create.diametr = diametr;
	return koleso_create;
}

//функция вывода информации о колесе
void prosmotr_koleso(koleso koleso_1)
{
	if (koleso_1.visota >= 0)
	{
		cout << "\n\nИНФОРМАЦИЯ О КОЛЕСАХ\nШирина колеса: " << koleso_1.shirina;
		cout << "\nДиаметр колеса: " << koleso_1.diametr;
		cout << "\nВысота колеса: " << koleso_1.visota;
		cout << "\nТип диска: " << koleso_1.tip_diska;
	}
	else
	{
		cout << "Информация о колесе еще не была добавлена";
	}
}

void koleso_diamter(koleso* koleso1)
{
	if (koleso1->visota >= 0)
	{
		double diametr;
		cout << "Введите новый диаметр колеса (может быть отрицательным): ";
		while (scanf("%lf", &diametr) != 1 || diametr < 0)
		{
			printf("Неверно введено значение диаметра, попробуйте еще: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');
		koleso1->diametr = diametr;
	}
	else
	{
		cout << "Информация о колесе еще не была добавлена";
	}
}