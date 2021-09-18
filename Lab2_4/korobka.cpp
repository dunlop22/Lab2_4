#include "korobka.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
using namespace std;

korobka_peredach new_korobka_info()
{
	korobka_peredach korobka_peredach_create;
	system("cls");
	cout << "Добавление информации о коробке передач автомобиля\n\nВведите тип коробки передач (АКПП/МКПП): ";
	gets_s(korobka_peredach_create.tip_korobki);
	while (strlen(korobka_peredach_create.tip_korobki) == 0)
	{
		printf("Неверно введена модель автомобиля, попробуйте еще: ");
		gets_s(korobka_peredach_create.tip_korobki);
	}

	cout << "Введите количество передач коробки: ";
	while (scanf("%lf", &korobka_peredach_create.kolvo_peredach) != 1 || korobka_peredach_create.kolvo_peredach < 0)
	{
		printf("Неверно введено значение количества передач, попробуйте еще: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');

	return korobka_peredach_create;
}

korobka_peredach new_korobka_peredach(double kolvo_peredach, char tip_korobki[20])
{
	korobka_peredach korobka_peredach_create;
	strcpy(korobka_peredach_create.tip_korobki, tip_korobki);
	korobka_peredach_create.kolvo_peredach = kolvo_peredach;
	return korobka_peredach_create;
}

void prosmotr_korobka_peredach(korobka_peredach korobka_peredach1)
{
	if (korobka_peredach1.kolvo_peredach >= 0)
	{
		cout << "\n\nИНФОРМАЦИЯ О КОРОБКЕ ПЕРЕКЛЮЧЕНИЯ ПЕРЕДАЧ\nТип коробки переключения передач: " << korobka_peredach1.tip_korobki;
		cout << "\nКоличество передач коробки: " << korobka_peredach1.kolvo_peredach;
	}
	else
	{
		cout << "Информации о коробках передач отсутствует";
	}
}

void korobka_peredach_peredacha_plus(korobka_peredach* korobka_peredach1)
{
	if (korobka_peredach1->kolvo_peredach >= 0)
	{
		double peredach;
		cout << "Введите количество дополнительных передач (кол-во может быть отрицательным): ";
		while (scanf("%lf", &peredach) != 1 || korobka_peredach1->kolvo_peredach + peredach < 0)
		{
			printf("Неверно введено значение количества передач, попробуйте еще: ");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');
		korobka_peredach1->kolvo_peredach = korobka_peredach1->kolvo_peredach + peredach;
	}
	else
	{
		cout << "Информации о коробках передач отсутствует";
	}
}
