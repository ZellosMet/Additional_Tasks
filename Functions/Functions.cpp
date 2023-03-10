#include<iostream>
#include<ctime>
#include<conio.h>
using namespace std;

/*
Задание:	Написать перегруженные функции для работы с одномерными
			типа int, float, double и char:
			??? Sum(???);	//ВОЗВРАЩАЕТ сумму элементов массива
			??? Avg(???);	//ВОЗВРАЩАЕТ среднее-арифметическое элементов массива
			??? minValueIn(???);	//ВОЗВРАЩАЕТ минимальное значение из массива
			??? maxValueIn(???);	//ВОЗВРАЩАЕТ максимальное значение из массива
			??? shiftLeft(???);		//циклически сдвигает массив на заданное число элементов влево
			??? shiftRight(???);	//циклически сдвигает массив на заданное число элементов вправо
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

//Список перегрузок функций
void Fill_Array(int arr[], int size);
void Fill_Array(float arr[], int size);

void Show_Array(int arr[], int size);
void Show_Array(float arr[], int size);

double Array_Sum(int arr[], int size);
double Array_Sum(float arr[], int size);

int Array_Max(int arr[], int size);
float Array_Max(float arr[], int size);

int Array_Min(int arr[], int size);
float Array_Min(float arr[], int size);

void Shift_Array(int arr[], int size, int shift, int step);
void Shift_Array(float arr[], int size, int shift, int step);


void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");

	int control;
	int step = 1;
	int shift = 0;
	const int SIZE = 10;
	int i_array[SIZE] = {};
	float f_array[SIZE] = {};

	Fill_Array(i_array, SIZE);
	Fill_Array(f_array, SIZE);

	Show_Array(f_array, SIZE);
	Show_Array(i_array, SIZE);

	cout << "Среднее арифметическое целочисленного массива " << Array_Sum(i_array, SIZE) / SIZE << endl;
	cout << "Сумма вещественного массива " << Array_Sum(f_array, SIZE) << endl;
	cout << "Минимальное целочисленного массива " << Array_Min(i_array, SIZE) << endl;
	cout << "Максимальное вещественного массива " << Array_Max(f_array, SIZE) << endl << endl;

	Show_Array(f_array, SIZE);

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
		case MOVE_LEFT: shift = MOVE_LEFT; cout << "Сдвиг на лево с шагом: " << step << endl;
			Shift_Array(f_array, SIZE, shift, step); Show_Array(f_array, SIZE); cout << endl; break;
		case MOVE_RIGHT: shift = MOVE_RIGHT; cout << "Сдвиг на право с шагом: " << step << endl;
			Shift_Array(f_array, SIZE, shift, step); Show_Array(f_array, SIZE); cout << endl; break;
		}
	} while (control != ESC);

	
}

void Fill_Array(int arr[], int size)
{
	int rnd;
	bool check;
	for (int i = 0; i < size; )
	{
		check = true;
		rnd = rand() % 20;
		for (int j = 0; j < size; j++) if (arr[j] == rnd) check = false;
		if (check)
		{
			arr[i] = rnd;
			i++;
		}
	}
}

void Fill_Array(float arr[], int size)
{
	int i_rnd;
	float f_rnd;
	bool check;
	for (int i = 0; i < size; )
	{
		check = true;
		i_rnd = (rand() % 9 + 1);
		f_rnd = (rand() % 9 + 2);
		f_rnd /= i_rnd;
		for (int j = 0; j < size; j++) if (arr[j] == f_rnd) check = false;
		if (check)
		{
			arr[i] = f_rnd;
			i++;
		}
	}
}

void Show_Array(int arr[], int size)
{

	cout << "Вызвалась функция заполнения массива целыми значениями\n";
	for (int i = 0; i < size; i++) cout << "[ " << arr[i] << " ] ";
	cout << endl << endl;
}

void Show_Array(float arr[], int size)
{
	cout << "Вызвалась функция заполнения массива вещественными значениями\n\n";
	for (int i = 0; i < size; i++) cout << "[ " << arr[i] << " ] ";
	cout << endl << endl;
}

void Shift_Array(float arr[], int size, int shift, int step)
{
	float tmp = 0;
	if (shift == MOVE_LEFT)
	{
		for (int i = 0; i < step; i++)
		{
			tmp = arr[0];
			for (int j = 0; j < size; j++) arr[j] = arr[j + 1];
			arr[size - 1] = tmp;
		}
	}
	else
	{
		for (int i = 0; i < step; i++)
		{
			tmp = arr[size - 1];
			for (int j = size - 1; j >= 0; j--) arr[j] = arr[j - 1];
			arr[0] = tmp;
		}
	}
}

void Shift_Array(int arr[], int size, int shift, int step)
{
	int tmp = 0;
	if (shift == MOVE_LEFT)
	{
		for (int i = 0; i < step; i++)
		{
			tmp = arr[0];
			for (int j = 0; j < size; j++) arr[j] = arr[j + 1];
			arr[size - 1] = tmp;
		}
	}
	else
	{
		for (int i = 0; i < step; i++)
		{
			tmp = arr[size - 1];
			for (int j = size - 1; j >= 0; j--) arr[j] = arr[j - 1];
			arr[0] = tmp;
		}
	}
}

double Array_Sum(int arr[], int size)
{
	int sum = 0;
	for (int i = 1; i < size; i++) sum += arr[i];
	return sum;
}
double Array_Sum(float arr[], int size)
{
	float sum = 0;
	for (int i = 1; i < size; i++) sum += arr[i];
	return sum;
}

float Array_Max(float arr[], int size)
{
	float max = arr[0];
	for (int i = 0; i < size; i++) if (max < arr[i]) max = arr[i];
	return max;
}
int Array_Max(int arr[], int size)
{
	int max = arr[0];
	for (int i = 0; i < size; i++) if (max < arr[i]) max = arr[i];
	return max;
}

int Array_Min(int arr[], int size)
{
	int min = arr[0];
	for (int i = 0; i < size; i++) if (min > arr[i]) min = arr[i];
	return min;
}
float Array_Min(float arr[], int size)
{
	float min = arr[0];
	for (int i = 0; i < size; i++) if (min > arr[i]) min = arr[i];
	return min;
}