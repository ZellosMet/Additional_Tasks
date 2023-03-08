#include<iostream>
#include<ctime>
using namespace std;

/*
Задание:	Двумерный массив заполнить уникальными случайными числами.
			Двумерный массив заполнить случайными числами и отсортировать в порядке возрастания;
			Есть двумерный массив, заполненный заведомо повторяющимися случайными числами. Необходимо найти в этом массиве повторяющиеся элементы, 
			вывести их на экран, и вывести на экран количество их повторений;
*/

void Fill_Matrix(int arr[][5], int size); //Функция заполнения матрицы
void Unique_Fill_Matrix(int arr[][5], int size); //Функция заполнения матрицы уникальными значениями
void Show_Matrix(int arr[][5], int size); // Функция вывода матрицы
void Sort_Matrix(int arr[][5], int size);

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");

	const int SIZE = 5;
	int matrix[SIZE][SIZE] = {};
	int duplic_value, count_duplic;
	bool duplic_check = true;

	cout << "Сгенерированный массив уникальных значений\n";
	Unique_Fill_Matrix(matrix, SIZE);
	Show_Matrix(matrix, SIZE);

	cout << "\nОтсортированный массив уникальных значени\n";

	Sort_Matrix(matrix, SIZE);
	Show_Matrix(matrix, SIZE);

	cout << "\nСгенерированный массив\n";
	Fill_Matrix(matrix, SIZE);
	Show_Matrix(matrix, SIZE);

	cout << "\nОтсортированный массив\n";
	Show_Matrix(matrix, SIZE);
	cout << endl;

	for (int i = 0; i < SIZE + SIZE; i++)
	{
		duplic_value = count_duplic = 0;
		duplic_check = false;

		for (int k = 0; k < SIZE; k++) //Цикл проверки элемента массива на повторение
		{
			for (int j = k; j < SIZE; j++) 
			{
				if (matrix[k][j] == matrix[k][j] && matrix[k][j] > 0)
				{
					duplic_check = true;
					duplic_value = matrix[k][j];
					break;
				}
			}
			if (duplic_check)
			{
				break;
			}
		}

		for (int k = 0; k < SIZE; k++) // Цикл подсчёта повторяющихся значений
		{
			for (int j = 0; j < SIZE; j++) 
			{
				if (matrix[k][j] == duplic_value)
				{
					matrix[k][j] = -matrix[k][j];
					count_duplic++;
				}
			}
		}
		if (duplic_check && count_duplic > 1) cout << "Число " << duplic_value << " повторилось " << count_duplic << " раз" << endl;
	}
}

void Fill_Matrix(int arr[][5], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = rand() % 9 + 1 ;
		}
	}
}

void Unique_Fill_Matrix(int arr[][5], int size)
{
	int rnd;
	bool check = true;
	for (int n = 0; n < size; n++)
	{
		for (int m = 0; m < size; )
		{
			check = true;
			rnd = rand() % 30;
			for (int x = 0; x < size; x++)
			{
				for (int y = 0; y < size; y++)
				{
					if (arr[x][y] == rnd)check = false;
				}
			}
			if (check)
			{
				arr[n][m] = rnd;
				m++;
			}
		}
	}
}

void Show_Matrix(int arr[][5], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << "[ " << arr[i][j] << " ] ";
		}
		cout << endl;
	}
}

void Sort_Matrix(int arr[][5], int size)
{
	int tmp, i, j;
	bool end = true;
	while (end)
	{
		end = false;
		i = 0; j = 0;
		for (int n = 0; n < size; n++)
		{
			for (int m = (n ? 0 : 1); m < size; m++)
			{
				if (arr[i][j] > arr[n][m])
				{
					tmp = arr[i][j];
					arr[i][j] = arr[n][m];
					arr[n][m] = tmp;
					end = true;
				}
				i = n;
				j = m;
			}
		}
	}
}