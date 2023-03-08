#include<iostream>
#include<ctime>
#include <algorithm>
using namespace std;

/*
Задание:	Двумерный массив заполнить случайными числами и отсортировать в порядке возрастания;
			Есть двумерный массив, заполненный заведомо повторяющимися случайными числами. Необходимо найти в этом массиве повторяющиеся элементы, 
			вывести их на экран, и вывести на экран количество их повторений;
*/

void Fill_Matrix(int arr[][5], int row, int col); //Функция заполнения матрицы
void Show_Matrix(int arr[][5], int row, int col); // Функция вывода матрицы

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");

	const int SIZE = 5;
	int matrix[SIZE][SIZE] = {};
	int duplic_value, count_duplic, tmp, i, j;
	bool end = true, duplic_check = true;

	cout << "Сгенерированный массив\n";
	Fill_Matrix(matrix, SIZE, SIZE);
	Show_Matrix(matrix, SIZE, SIZE);

	cout << endl;

	while (end) //Цикл сортировки пузыриком
	{
		end = false;
		i = 0; j = 0;
		for (int n = 0; n < SIZE; n++)
		{
			for (int m = (n ? 0 : 1); m < SIZE; m++)
			{
				if (matrix[i][j] > matrix[n][m]) 
				{
					tmp = matrix[i][j];
					matrix[i][j] = matrix[n][m];
					matrix[n][m] = tmp;
					end = true;
				}
				i = n;
				j = m;
			}
		}
	}

	cout << "Отсортированный массив\n";
	Show_Matrix(matrix, SIZE, SIZE);
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

void Fill_Matrix(int arr[][5], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = rand() % 9 + 1;
		}
	}
}

void Show_Matrix(int arr[][5], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << "[ " << arr[i][j] << " ] ";
		}
		cout << endl;
	}
}