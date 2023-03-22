#include<iostream>
#include<ctime>
using namespace std;

/*
Задание:	В проекте 2D реализовать алгоритм умножения матриц.
			Найти определитель матрицы третьего порядка используя алгоритм Саррюса;
*/

const int ROW = 3;
const int COL = 3;

void Fill_Matrix(int arr[ROW][COL], int row, int col); //Функция заполнения матрицы
void Show_Matrix(int arr[ROW][COL], int row, int col); // Функция вывода матрицы
void Multip_Matrix(int f_arr[ROW][COL], int s_arr[ROW][COL], int m_arr[ROW][COL], int row, int col); // Функция перемножения матриц
void Move_Matrix(int arr[ROW][COL], int row, int col); //Функция циклического смещения элементов матрицы

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");

	int multip_element = 1; //Переменная произведения элементов
	long long det = 0; //Детерминант матрици

	int first_matrix[ROW][COL] = {};
	int second_matrix[ROW][COL] = {};
	int multip_matrix[ROW][COL] = {};

	cout << "Сгенерированный первый массив" << endl;
	Fill_Matrix(first_matrix, ROW, COL);
	Show_Matrix(first_matrix, ROW, COL);

	cout << "\nСгенерированный второй массив" << endl;
	Fill_Matrix(second_matrix, ROW, COL);
	Show_Matrix(second_matrix, ROW, COL);

	cout << "\nПроизведение массивов" << endl;
	Multip_Matrix(first_matrix, second_matrix, multip_matrix, ROW, COL);
	Show_Matrix(multip_matrix, ROW, COL);

	for (int i = 0; i < COL; i++) //Циклы нахождения детерминанта методом Саррюса
	{
		for (int i = 0, j = 0; i < COL; i++, j++)
		{
			multip_element *= multip_matrix[i][j];
		}
		det += multip_element;
		multip_element = 1;
		Move_Matrix(multip_matrix, ROW, COL);
	}

	for (int i = 0; i < COL; i++)
	{
		for (int i = 0, j = COL-1; i < COL; i++, j--)
		{
			multip_element *= multip_matrix[i][j];
		}
		det -= multip_element;
		multip_element = 1;
		Move_Matrix(multip_matrix, ROW, COL);
	}

	cout << endl << "Детерминант произведения матрицы = " << det << endl;

}

void Fill_Matrix(int arr[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = rand() % 9 + 1;
		}
	}
}

void Show_Matrix(int arr[ROW][COL], int row, int col)
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

void Multip_Matrix(int f_arr[ROW][COL], int s_arr[ROW][COL], int m_arr[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			m_arr[i][j] = f_arr[i][j] * s_arr[i][j];
		}
	}
}

void Move_Matrix(int arr[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		int tmp = arr[i][0];
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = arr[i][j + 1];
		}
		arr[i][row - 1] = tmp;
	}
}