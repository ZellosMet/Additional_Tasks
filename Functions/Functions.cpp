#include<iostream>
#include<ctime>
#include<conio.h>
using namespace std;

/*
Задание:	Создать ветку FunctionsTemplates, и в этой ветке шаблонизировать все функции для работы с массивами;
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

//Список шаблонных функций

template<typename T1, typename T2> void Fill_Array(T1 arr[], T2 size);
template<typename T1, typename T2, typename T3> void Show_Array(T1 arr[], T2 size, T3 target);
template<typename T1, typename T2> T1 Array_Sum(T1 arr[], T2 size);
template<typename T1, typename T2> T1 Array_Max(T1 arr[], T2 size);
template<typename T1, typename T2> T1 Array_Min(T1 arr[], T2 size);
template<typename T1, typename T2, typename T3> void Shift_Left_Array(T1 arr[], T2 size, T3 step);
template<typename T1, typename T2, typename T3> void Shift_Right_Array(T1 arr[], T2 size, T3 step);

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

template<typename T1, typename T2> void Fill_Array(T1 arr[], T2 size)
{
	int rnd_i;
	float rnd_f;
	bool check;
	for (int i = 0; i < size; )
	{
		check = true;
		rnd_i = rand() % 9;
		rnd_f = (float)(rand() % 99 + 1)/100;
		rnd_f += rnd_i;
		for (int j = 0; j < size; j++) if (arr[j] == rnd_f) check = false;
		if (check)
		{
			arr[i] = rnd_f;
			i++;
		}
	}
}

template<typename T1, typename T2, typename T3> void Show_Array(T1 arr[], T2 size, T3 target)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == target)
		{
			cout << "| " << arr[i] << " | ";
		}
		else
		{
			cout << "< " << arr[i] << " > ";
		}
	}
}

template<typename T1, typename T2, typename T3> void Shift_Left_Array(T1 arr[], T2 size, T3 step)
{
	float tmp = 0;
	for (int i = 0; i < step; i++)
	{
		tmp = arr[0];
		for (int j = 0; j < size; j++) arr[j] = arr[j + 1];
		arr[size - 1] = tmp;
	}
}

template<typename T1, typename T2, typename T3> void Shift_Right_Array(T1 arr[], T2 size, T3 step)
{
	float tmp = 0;
	for (int i = 0; i < step; i++)
	{
		tmp = arr[size - 1];
		for (int j = size - 1; j >= 0; j--) arr[j] = arr[j - 1];
		arr[0] = tmp;
	}
}

template<typename T1, typename T2> T1 Array_Sum(T1 arr[], T2 size)
{
	float sum = 0;
	for (int i = 1; i < size; i++) sum += arr[i];
	return sum;
}

template<typename T1, typename T2> T1 Array_Max(T1 arr[], T2 size)
{
	float max = arr[0];
	for (int i = 0; i < size; i++) if (max < arr[i]) max = arr[i];
	return max;
}

template<typename T1, typename T2> T1 Array_Min(T1 arr[], T2 size)
{
	float min = arr[0];
	for (int i = 0; i < size; i++) if (min > arr[i]) min = arr[i];
	return min;
}
