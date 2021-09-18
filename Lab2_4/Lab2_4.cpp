
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
	vodila.age = -1;
	avto avtomobil1;
	do
	{


		podmenu = 0;
		system("cls");
		cout << "1) Общее\n2) Двигатель\n3) Коробка\n4) Колеса\n5) Автомобиль\n6) Водитель\n7) Создание нескольких автомобилей с увеличенным диаметром колес\n\nESC - выход";
		glmenu = _getch();
		if (glmenu == '1')
		{
			char tip_privoda[20]; char name[20]; char tip_topliva[20];
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
						new_obchee_info();
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
					if (&obchie.massa >= 0)
					{
						prosmotr_obchee(&obchie);
					}
					else
					{
						cout << "Общая информация не найдена.";
					}
					cout << "\n\nНажмите любую клавишу для возврата в меню.";
					_getch();
				}
				else if (podmenu == '3')
				{
					if (&obchie.massa >= 0)
					{
						system("cls");
						cout << "Введите новое название модели: ";
						gets_s(name);
						while (strlen(name) == 0)
						{
							printf("Неверно введена модель автомобиля, попробуйте еще: ");
							gets_s(name);
						}
						obchee_name(&obchie, name);
					}
					else
					{
						cout << "Общая информация не найдена.\n\nНажмите любую клавишу для возврата в основное меню.";
						_getch();
					}
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
					double koni, rasxod, klapan, rab_obem, kol_vo_cilindr;
					char name[20];
					do
					{
						system("cls");
						cout << "\n1) Ввод собственных данных о двигателе\n2) Создание по конструктору";
						menu = _getch();
					} while (menu != '1' && menu != '2');
					system("cls");
					if (menu == '1')
					{
						
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
					if (&motorishe.kol_vo_cilindr >= 0)
					{
						prosmotr_motor(&motorishe);
					}
					else
					{
						cout << "Не найден двигатель для показа информации о нем.";
					}
					cout << "\n\nНажмите любую клавишу для возврата в меню.";
					_getch();
				}
				else if (podmenu == '3')
				{
					if (&motorishe.kol_vo_cilindr >= 0)
					{
						system("cls");
						double force;
						cout << "Введите количество дополнительных сил (кол-во может быть отрицательным): ";
						while (scanf("%lf", &force) != 1 || force + motorishe.koni < 0)
						{
							printf("Неверно введено значение количества лошадиных сил, попробуйте еще: ");
							while (getchar() != '\n');
						}
						while (getchar() != '\n');
						motor_force(&motorishe, force);
					}
					else
					{
						cout << "Не найден двигатель для добавления сил.\n\nНажмите любую клавишу для возврата в основное меню.";
						_getch();
					}
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
					double kolvo_peredach;
					char tip_korobki[20];
					do
					{
						system("cls");
						cout << "\n1) Ввод собственных данных о коробке\n2) Создание по конструктору";
						menu = _getch();
					} while (menu != '1' && menu != '2');
					system("cls");
					if (menu == '1')
					{
						system("cls");
						cout << "Добавление информации о коробке передач автомобиля\n\nВведите тип коробки передач (АКПП/МКПП): ";
						gets_s(tip_korobki);
						while (strlen(tip_korobki) == 0)
						{
							printf("Неверно введена модель автомобиля, попробуйте еще: ");
							gets_s(tip_korobki);
						}

						cout << "Введите количество передач коробки: ";
						while (scanf("%lf", &kolvo_peredach) != 1 || kolvo_peredach > 0)
						{
							printf("Неверно введено значение количества передач, попробуйте еще: ");
							while (getchar() != '\n');
						}
						while (getchar() != '\n');

						korobas = new_korobka_peredach(kolvo_peredach, tip_korobki);
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
					if (&korobas.kolvo_peredach >= 0)
					{
						prosmotr_korobka_peredach(&korobas);
					}
					else
					{
						cout << "Не найдена коробка передач для показа информации о ней.";
					}
					cout << "\n\nНажмите любую клавишу для возврата в меню.";
					_getch();
				}
				else if (podmenu == '3')
				{
					if (&korobas.kolvo_peredach >= 0)
					{
						system("cls");
						double peredach;
						cout << "Введите количество дополнительных передач (кол-во может быть отрицательным): ";
						while (scanf("%lf", &peredach) != 1 || korobas.kolvo_peredach + peredach < 0)
						{
							printf("Неверно введено значение количества передач, попробуйте еще: ");
							while (getchar() != '\n');
						}
						while (getchar() != '\n');
						//korobas = korobka_peredach_peredacha_plus(&korobas, peredach);
						korobka_peredach_peredacha_plus(&korobas, peredach);
					}
					else
					{
						cout << "Не найдена коробка передач для добавления передач.\n\nНажмите любую клавишу для возврата в основное меню.";
						_getch();
					}
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
					double visota, shirina, diametr;
					char tip_diska[20];
					do
					{
						system("cls");
						cout << "\n1) Ввод собственных данных о колесах\n2) Создание по конструктору";
						menu = _getch();
					} while (menu != '1' && menu != '2');
					system("cls");
					if (menu == '1')
					{
						system("cls");
						cout << "Добавление информации о колесах автомобиля\n\nВведите ширину колеса: ";
						while (scanf("%lf", &shirina) != 1 || shirina < 0)
						{
							printf("Неверно введено значение ширины колеса, попробуйте еще: ");
							while (getchar() != '\n');
						}
						while (getchar() != '\n');

						cout << "Введите высоту колеса: ";
						while (scanf("%lf", &visota) != 1 || visota < 0)
						{
							printf("Неверно введено значение высоты колеса, попробуйте еще: ");
							while (getchar() != '\n');
						}
						while (getchar() != '\n');

						cout << "Введите диаметр колеса в дюймах: ";
						while (scanf("%lf", &diametr) != 1 || diametr < 0)
						{
							printf("Неверно введено значение диаметра колеса, попробуйте еще: ");
							while (getchar() != '\n');
						}
						while (getchar() != '\n');

						cout << "Введите тип колесного диска (штамповка/литье/ковка): ";
						gets_s(tip_diska);
						while (strlen(tip_diska) == 0)
						{
							printf("Неверно введен тип колесного диска, попробуйте еще: ");
							gets_s(tip_diska);
						}

						kolesiki = new_koleso(shirina, visota, diametr, tip_diska);
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
					if (&kolesiki.shirina >= 0)
					{
						prosmotr_koleso(&kolesiki);
					}
					else
					{
						cout << "Не найдена информация о колесах.";
					}
					cout << "\n\nНажмите любую клавишу для возврата в меню.";
					_getch();
				}
				else if (podmenu == '3')
				{
					if (&kolesiki.visota >= 0)
					{
						system("cls");
						int diametr;
						cout << "Введите новый диаметр колеса (может быть отрицательным): ";
						while (scanf("%lf", &diametr) != 1 || diametr > 0)
						{
							printf("Неверно введено значение диаметра, попробуйте еще: ");
							while (getchar() != '\n');
						}
						while (getchar() != '\n');
						koleso_diamter(&kolesiki, diametr);
					}
					else
					{
						cout << "Не найдено колесо для изменения диаметра.\n\nНажмите любую клавишу для возврата в основное меню.";
						_getch();
					}
				}
				glmenu = 0;
			} while (podmenu != 27);
		}
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
		else if (glmenu == '6')
		{
			do
			{
				double age, stag;
				char name[50]; char pol[20]; char covid_19[20];
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
						cout << "Введите ФИО водителя : ";
						gets_s(name);
						while (strlen(name) == 0)
						{
							printf("Неверно введен ФИО водителя, попробуйте еще: ");
							gets_s(name);
						}
						cout << "Введите возраст: ";
						while (scanf("%lf", &age) != 1)
						{
							printf("Неверно введен возраст водителя, попробуйте еще: ");
							while (getchar() != '\n');
						}
						while (getchar() != '\n');
						cout << "Введите пол водителя (М/Ж): ";
						gets_s(pol);
						while (strlen(pol) == 0)
						{
							printf("Неверно введен пол водителя, попробуйте еще: ");
							gets_s(pol);
						}
						cout << "Введите статус Covid-19 (переболел/привит/неизвестно): ";
						gets_s(covid_19);
						while (strlen(covid_19) == 0)
						{
							printf("Неверно введен статус COVID-19, попробуйте еще: ");
							gets_s(covid_19);
						}
						cout << "Введите стаж водителя: ";
						while (scanf("%lf", &stag) != 1)
						{
							printf("Неверно введен стаж водителя, попробуйте еще: ");
							while (getchar() != '\n');
						}
						while (getchar() != '\n');

						vodila = new_voditel(age, stag, name, pol, covid_19);
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
					if (&vodila.age >= 0)
					{
						prosmotr_voditel(&vodila);
					}
					else
					{
						cout << "Не найдена информация о водителе.";
					}
					cout << "\n\nНажмите любую клавишу для возврата в меню.";
					_getch();
				}
				else if (podmenu == '3')
				{
					if (&kolesiki.visota >= 0)
					{
						system("cls");
						int diametr;
						cout << "Введите новое состояние Covid-19 у водителя: ";

						gets_s(covid_19);
						while (strlen(name) == 0)
						{
							printf("Неверно введено состояние, попробуйте еще: ");
							gets_s(name);
						}

						voditel_covid(&vodila, covid_19);
					}
					else
					{
						cout << "Не найден водитель для изменения состояния.\n\nНажмите любую клавишу для возврата в основное меню.";
						_getch();
					}
				}
			} while (podmenu != 27);
		}
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
	} while (glmenu != 27);

}
