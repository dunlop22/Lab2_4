#include "voditel.h";

voditel new_voditel(double age, double stag, char name[20], char pol[20], char covid_19[20])
{
    voditel voditel_create;
    voditel_create.age = age;
    strcpy(voditel_create.covid_19, covid_19);
    strcpy(voditel_create.name, name);
    strcpy(voditel_create.pol, pol);
    voditel_create.stag = stag;
    return voditel_create;
}

voditel new_voditel_info()
{
	voditel voditel_create;
	cout << "Введите ФИО водителя : ";
	gets_s(voditel_create.name);
	while (strlen(voditel_create.name) == 0)
	{
		printf("Неверно введен ФИО водителя, попробуйте еще: ");
		gets_s(voditel_create.name);
	}
	cout << "Введите возраст: ";
	while (scanf("%lf", &voditel_create.age) != 1)
	{
		printf("Неверно введен возраст водителя, попробуйте еще: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');
	cout << "Введите пол водителя (М/Ж): ";
	gets_s(voditel_create.pol);
	while (strlen(voditel_create.pol) == 0)
	{
		printf("Неверно введен пол водителя, попробуйте еще: ");
		gets_s(voditel_create.pol);
	}
	cout << "Введите статус Covid-19 (переболел/привит/неизвестно): ";
	gets_s(voditel_create.covid_19);
	while (strlen(voditel_create.covid_19) == 0)
	{
		printf("Неверно введен статус COVID-19, попробуйте еще: ");
		gets_s(voditel_create.covid_19);
	}
	cout << "Введите стаж водителя: ";
	while (scanf("%lf", &voditel_create.stag) != 1)
	{
		printf("Неверно введен стаж водителя, попробуйте еще: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');
	return voditel_create;
}

void prosmotr_voditel(voditel vod)
{
    if (vod.age >= 0)
    {
        cout << "\n\nИНФОРМАЦИЯ О ВОДИТЕЛЕ";
        cout << "\nФИО: " << vod.name;
        cout << "\nВозраст: " << vod.age;
        cout << "\nПол: " << vod.pol;
        cout << "\nСтатус Covid-19: " << vod.covid_19;
        cout << "\nСтаж: " << vod.stag << "\n***************************************\n\n";
    }
    else
    {
        cout << "Информация о водителе отсутствует";
    }
}

void voditel_covid(voditel* vod)
{
	if (vod->age >= 0)
	{
		cout << "Введите новое состояние Covid-19 у водителя: ";
		gets_s(vod->covid_19);
		while (strlen(vod->covid_19) == 0)
		{
			printf("Неверно введено состояние, попробуйте еще: ");
			gets_s(vod->covid_19);
		}
	}
	else
	{
		cout << "Информация о водителе отсутствует";
	}
}

