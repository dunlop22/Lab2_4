
#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <iostream>
#include <conio.h>
#include "avto.h"
#include "koleso.h"
#include <windows.h>
#include "korobka.h"
#include "motor.h"
#include "obchee.h"
#include "voditel.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int menu, podmenu, glmenu;
	glmenu = 0;
	obchee obchie;
	motor motorishe;
	korobka_peredach korobas;
	koleso kolesiki;
	voditel vodila;
	avto avtomobil1;
	obchie.obem_benzobaka = -1;
	vodila.age = -1;
	motorishe.koni = -1;
	korobas.kolvo_peredach = -1;
	kolesiki.visota = -1;
	
	do
	{
		podmenu = 0;
		system("cls");
		cout << "1) Общее\n2) Двигатель\n3) Коробка\n4) Колеса\n5) Автомобиль\n6) Водитель\n7) Создание нескольких автомобилей с увеличенным диаметром колес\n\nESC - выход";
		glmenu = _getch();
		if (glmenu == '1')
		{
			do
			{
				system("cls");
				cout << "1) Добавление общей информации\n2) Просмотр общей информации\n3) Изменение названия\n\nESC - Возврат в меню";
				podmenu = _getch();
				if (podmenu == '1')
				{
					do
					{
						system("cls");
						cout << "\n1) Ввод собственных данных об общем\n2) Создание по конструктору";
						menu = _getch();
					} while (menu != '1' && menu != '2');
					system("cls");
					if (menu == '1')
					{
						obchie = new_obchee_info();
					}
					else
					{
						char name[20] = "Subaru";
						char tip_privoda[20] = "4WD";
						char tip_topliva[20] = "Бензин";
						obchie = new_obchee(5, 1500, name, 7, tip_privoda, tip_topliva, 65);
					}
				}
				else if (podmenu == '2')
				{
					system("cls");
					prosmotr_obchee(obchie);
					cout << "\n\nНажмите любую клавишу для возврата в меню";
					_getch();
				}
				else if (podmenu == '3')
				{
					obchee_name(&obchie);
				}
			} while (podmenu != 27);
		}
		else if (glmenu == '2')
		{
			do
			{
				system("cls");
				cout << "1) Добавление информации о двигателе\n2) Просмотр информации о двигателе\n3) Увеличение мощности\n\nESC - Возврат в меню";
				podmenu = _getch();
				if (podmenu == '1')
				{
					do
					{
						system("cls");
						cout << "\n1) Ввод собственных данных о двигателе\n2) Создание по конструктору";
						menu = _getch();
					} while (menu != '1' && menu != '2');
					system("cls");
					if (menu == '1')
					{
						motorishe = new_motor_info();
					}
					else
					{
						char name[20] = "stok";
						motorishe = new_motor(100, 10, name, 2, 4, 4);
					}
				}
				else if (podmenu == '2')
				{
					system("cls");
					prosmotr_motor(motorishe);
					cout << "\n\nНажмите любую клавишу для возврата в меню.";
					_getch();
				}
				else if (podmenu == '3')
				{
					system("cls");
					motor_force(&motorishe);
				}
			} while (podmenu != 27);
		}
		else if (glmenu == '3')
		{
			do
			{
				system("cls");
				cout << "1) Добавление информации о коробке\n2) Просмотр информации о коробке\n3) Изменение количества передач\n\nESC - Возврат в меню";
				podmenu = _getch();
				if (podmenu == '1')
				{
					do
					{
						system("cls");
						cout << "\n1) Ввод собственных данных о коробке\n2) Создание по конструктору";
						menu = _getch();
					} while (menu != '1' && menu != '2');
					system("cls");
					if (menu == '1')
					{
						korobas = new_korobka_info();
					}
					else
					{
						char tip_korobki[20] = "АКПП";
						korobas = new_korobka_peredach(5, tip_korobki);
					}
				}
				else if (podmenu == '2')
				{
					system("cls");
					prosmotr_korobka_peredach(korobas);
					cout << "\n\nНажмите любую клавишу для возврата в меню.";
					_getch();
				}
				else if (podmenu == '3')
				{
					system("cls");
					korobka_peredach_peredacha_plus(&korobas);
					cout << "\n\nНажмите любую клавишу для возврата в основное меню.";
					_getch();
				}
			} while (podmenu != 27);
		}
		else if (glmenu == '4')
		{
			do
			{
				system("cls");
				cout << "1) Добавление информации о колесах\n2) Просмотр информации о колесах\n3) Изменение диаметра колеса\n\nESC - Возврат в меню";
				podmenu = _getch();
				if (podmenu == '1')
				{
					do
					{
						system("cls");
						cout << "\n1) Ввод собственных данных о колесах\n2) Создание по конструктору";
						menu = _getch();
					} while (menu != '1' && menu != '2');
					system("cls");
					if (menu == '1')
					{
						kolesiki = new_koleso_info();
					}
					else
					{
						char tip_diska[20] = "Литье";
						kolesiki = new_koleso(230, 55, 17, tip_diska);
					}
				}
				else if (podmenu == '2')
				{
					system("cls");
					prosmotr_koleso(kolesiki);
					cout << "\n\nНажмите любую клавишу для возврата в меню.";
					_getch();
				}
				else if (podmenu == '3')
				{
					if (&kolesiki.visota >= 0)
					{
						system("cls");
						koleso_diamter(&kolesiki);
					}
					cout << "\n\nНажмите любую клавишу для возврата в основное меню.";
					_getch();
				}
				glmenu = 0;
			} while (podmenu != 27);
		}
		/*
		else if (glmenu == '5')
		{
			do
			{

				system("cls");
				cout << "1) Сборка автомобиля из существующих компонентов\n2) Просмотр информации об автомобиле\n3) Привязка/отвязка водителя\n\nESC - выход в меню";
				podmenu = _getch();
				if (podmenu == '1')
				{
					system("cls");
					avtomobil1 = new_avto(&motorishe, &kolesiki, &korobas, &obchie);
					if (avtomobil1.har3.shirina >= 0 && avtomobil1.har2.klapan >= 0 && avtomobil1.har4.kolvo_peredach >= 0 && avtomobil1.har5.kolvo_mest >= 0)
					{
						cout << "успешно собран";
					}
					else
					{
						cout << "Автомобиль не может быть собран из-за отсутствия даных о каком-либо из агрегатов";
					}
					cout << "\n\nНажите любую клавишу для возврата в меню";
					_getch();
				}
				else if (podmenu == '2')
				{
					system("cls");
					if (avtomobil1.har3.shirina >= 0)
					{
						prosmotr_avto(&avtomobil1);

					}
					else
					{
						cout << "Информация об автомобиле не найдена.";
					}
					cout << "\n\nНажите любую клавишу для возврата в меню";
					_getch();
				}
				else if (podmenu == '3')
				{
					system("cls");
					if (vodila.age >= 0 && avtomobil1.har3.shirina >= 0 && avtomobil1.har2.klapan >= 0 && avtomobil1.har4.kolvo_peredach >= 0 && avtomobil1.har5.kolvo_mest >= 0)
					{

						do
						{
							system("cls");
							cout << "1) Привязать водителя к автомобилю\n2) Отвязать водителя от автомобиля\n\nESC - выход";
							podmenu = _getch();
							if (podmenu == '1')
							{
								system("cls");
								vod_avto(&avtomobil1, &vodila);
								cout << "Водитель успешно привязан";
							}
							else if (podmenu == '2')
							{
								system("cls");
								avto_otv(&avtomobil1);
								cout << "Водитель успешно отвязан от автомобиля";
							}
							cout << "\n\nНажите любую клавишу для возврата в меню";
							_getch();
						} while (podmenu != 27);
					}
					else
					{
						cout << "Информация о водителе или автомобиле не найдена\n\nНажите любую клавишу для возврата в меню";
						_getch();
					}
				}
			} while (podmenu != 27);
		}
		*/
		else if (glmenu == '6')
		{
			do
			{
				system("cls");
				cout << "1) Добавление информации о водителе\n2) Просмотр информации о водителе\n3) Изменение состояния у водителя\n\nESC - Возврат в меню";
				podmenu = _getch();
				if (podmenu == '1')
				{
					do
					{
						system("cls");
						cout << "\n1) Ввод собственных данных о водителе\n2) Создание по конструктору";
						menu = _getch();
					} while (menu != '1' && menu != '2');
					system("cls");
					if (menu == '1')
					{
						vodila = new_voditel_info();
					}
					else
					{
						char name[50] = "Иванов .И.";
						char pol[20] = "М";
						char covid_19[20] = "Переболел";
						vodila = new_voditel(25, 2, name, pol, covid_19);
					}
				}
				else if (podmenu == '2')
				{
					system("cls");
					prosmotr_voditel(vodila);
					cout << "\n\nНажмите любую клавишу для возврата в меню.";
					_getch();
				}
				else if (podmenu == '3')
				{
					system("cls");
					voditel_covid(&vodila);
					cout << "\n\nНажмите любую клавишу для возврата в основное меню.";
					_getch();
				}
			} while (podmenu != 27);
		}
		/*
		else if (glmenu == '7')
		{

			avto* mashina;
			mashina = (avto*)malloc(0 * sizeof(avto));
			int n = -1;
			int i;
			double temp, hag;
			do
			{
				system("cls");
				cout << "1) Создание n автомобилей\n2) Просмотр списка авто\n\nESC - выход в меню";
				podmenu = _getch();

				if (podmenu == '1')
				{
					system("cls");
					cout << "Введите количество автомобилей для создания: ";
					while (scanf("%d", &n) != 1 || n < 0)
					{
						printf("Неверно введено количество, попробуйте еще: ");
						while (getchar() != '\n');
					}
					while (getchar() != '\n');

					cout << "Введите шаг увеличения диаметра колеса: ";
					while (scanf("%lf", &hag) != 1 || hag < 0)
					{
						printf("Неверно введено количество, попробуйте еще: ");
						while (getchar() != '\n');
					}
					while (getchar() != '\n');
					mashina = (avto*)malloc(n * sizeof(avto));
					mashina[0] = new_avto(&motorishe, &kolesiki, &korobas, &obchie);
					if (mashina[0].har3.shirina >= 0 && mashina[0].har2.klapan >= 0 && mashina[0].har4.kolvo_peredach >= 0 && mashina[0].har5.kolvo_mest >= 0)
					{
						cout << "успешно собран";
						temp = kolesiki.diametr;
						for (i = 1; i < n; i++)
						{
							koleso_diamter(&kolesiki, kolesiki.diametr + hag);
							mashina[i] = new_avto(&motorishe, &kolesiki, &korobas, &obchie);
						}
						kolesiki.diametr = temp;
					}
					else
					{
						system("cls");
						cout << "Автомобиль не может быть собран из-за отсутствия даных о каком-либо из агрегатов";
						n = -1;
					}
					cout << "\n\nНажите любую клавишу для возврата в меню";
					_getch();
				}
				else if (podmenu == '2')
				{
					system("cls");
					if (n >= 0)
					{
						for (i = 0; i < n; i++)
						{
							cout << "АВТО №" << i + 1 << "\n\n";
							prosmotr_avto(&mashina[i]);
						}
					}
					else
					{
						cout << "Информация об авто не найдена";
					}
					cout << "\n\nНажите любую клавишу для возврата в меню";
					_getch();
				}

			} while (podmenu != 27);
		}
		*/
	} while (glmenu != 27);

}
