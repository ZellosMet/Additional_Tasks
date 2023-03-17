#include<iostream>
#include<ctime>
#include<conio.h>
#include"Fill_Array.h"
#include"Show_Array.h"
#include"Array_Sum.h"
#include"Array_Max.h"
#include"Array_Min.h"
#include"Shift_Left_Array.h"
#include"Shift_Right_Array.h"
using namespace std;

/*
Задание:	От ветки FunctionsTemplates создать ветку TemplatedFunctionsSeparation, и в ней, шаблонные функции разделить на файлы.
*/

#define MOVE_LEFT 75  //Задание переменных для отлова с клавиатуры
#define MOVE_RIGHT 77
#define ESC 27

enum STEP
{
	One = 49,
	Two,
	Three,
	Four,
	Five
};

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");

	int control, step = 1;
	float target;
	const int SIZE = 10;
	float array[SIZE] = {};

	cout << "Сгенерированный массив: " << endl;

	Fill_Array(array, SIZE);
	target = array[5];
	Show_Array(array, SIZE, target);

	cout << "\n\nСреднее арифметическое целочисленного массива " << Array_Sum(array, SIZE) / SIZE << endl;
	cout << "Сумма вещественного массива " << Array_Sum(array, SIZE) << endl;
	cout << "Минимальное целочисленного массива " << Array_Min(array, SIZE) << endl;
	cout << "Максимальное вещественного массива " << Array_Max(array, SIZE) << endl << endl;

	do //Цикл отлова событий
	{
		control = _getch();
		switch (control)
		{
		case One: step = 1; cout << "Установлен шаг 1\n\n"; break;
		case Two: step = 2; cout << "Установлен шаг 2\n\n"; break;
		case Three: step = 3; cout << "Установлен шаг 3\n\n"; break;
		case Four: step = 4; cout << "Установлен шаг 4\n\n"; break;
		case Five: step = 5; cout << "Установлен шаг 5\n\n"; break;
		case MOVE_LEFT: cout << "Сдвиг на лево с шагом: " << step << endl;
			Shift_Left_Array(array, SIZE, step); Show_Array(array, SIZE, target); cout << endl << endl; break;
		case MOVE_RIGHT: cout << "Сдвиг на право с шагом: " << step << endl;
			Shift_Right_Array(array, SIZE, step); Show_Array(array, SIZE, target); cout << endl << endl; break;
		}
	} while (control != ESC);
}








