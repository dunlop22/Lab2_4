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
	cout << "������� ��� �������� : ";
	gets_s(voditel_create.name);
	while (strlen(voditel_create.name) == 0)
	{
		printf("������� ������ ��� ��������, ���������� ���: ");
		gets_s(voditel_create.name);
	}
	cout << "������� �������: ";
	while (scanf("%lf", &voditel_create.age) != 1)
	{
		printf("������� ������ ������� ��������, ���������� ���: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');
	cout << "������� ��� �������� (�/�): ";
	gets_s(voditel_create.pol);
	while (strlen(voditel_create.pol) == 0)
	{
		printf("������� ������ ��� ��������, ���������� ���: ");
		gets_s(voditel_create.pol);
	}
	cout << "������� ������ Covid-19 (���������/������/����������): ";
	gets_s(voditel_create.covid_19);
	while (strlen(voditel_create.covid_19) == 0)
	{
		printf("������� ������ ������ COVID-19, ���������� ���: ");
		gets_s(voditel_create.covid_19);
	}
	cout << "������� ���� ��������: ";
	while (scanf("%lf", &voditel_create.stag) != 1)
	{
		printf("������� ������ ���� ��������, ���������� ���: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');
	return voditel_create;
}

void prosmotr_voditel(voditel vod)
{
    if (vod.age >= 0)
    {
        cout << "\n\n���������� � ��������";
        cout << "\n���: " << vod.name;
        cout << "\n�������: " << vod.age;
        cout << "\n���: " << vod.pol;
        cout << "\n������ Covid-19: " << vod.covid_19;
        cout << "\n����: " << vod.stag << "\n***************************************\n\n";
    }
    else
    {
        cout << "���������� � �������� �����������";
    }
}

void voditel_covid(voditel* vod)
{
	if (vod->age >= 0)
	{
		cout << "������� ����� ��������� Covid-19 � ��������: ";
		gets_s(vod->covid_19);
		while (strlen(vod->covid_19) == 0)
		{
			printf("������� ������� ���������, ���������� ���: ");
			gets_s(vod->covid_19);
		}
	}
	else
	{
		cout << "���������� � �������� �����������";
	}
}

