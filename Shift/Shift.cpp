#include<iostream>
#include<ctime>
#include<conio.h>

using namespace std;

/*Задание:	Создать массив из десяти элементов заполнить УНИКАЛЬНЫМИ случайными числами в диапазоне от 0 до 10;
			Реализовать циклический сдвиг массива на заданное число элементов. Элементы массива должны не просто вывестись на экран в другом порядке,
			а должны изменить свое расположение в памяти;
			Выполнить циклический сдвиг массива вправо.
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

void Fill_Array(int arr[], int size); //Функция заполнения массива уникальными значениями
void Show_Array(int arr[], int size); //Функция вывода массива
void Shift_Array(int arr[], int size, int shift, int step); //Функция сдвига элементов массива массивом(право/лево)


void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");

	int control;
	int step = 1;
	int shift = 0;
	const int SIZE = 10;
	int array[SIZE] = {};

	cout << "Управление:\nШаг задаётся нажатием на цифру от 1 до 5(поумолчанию 1)\n";
	cout << "Стрелочками выбирается направление смещения\n"; 
	cout << "ESC - Выход\n\n";
	cout << "Сгенерированный массив: \n\n";

	Fill_Array(array, SIZE);
	Show_Array(array, SIZE);
	cout << endl << endl;

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
			Shift_Array(array, SIZE, shift, step); Show_Array(array, SIZE); cout << endl << endl; break;
		case MOVE_RIGHT: shift = MOVE_RIGHT; cout << "Сдвиг на право с шагом: " << step << endl;
			Shift_Array(array, SIZE, shift, step); Show_Array(array, SIZE); cout << endl << endl; break;
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

void Show_Array(int arr[], int size)
{
	for (int i = 0; i < size; i++) cout << "[ " << arr[i] << " ] ";
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