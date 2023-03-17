#include<iostream>
#include<ctime>

using namespace std;

void Fill_Array(int arr[], int size); //Функция заполнения массива целыми значениями
void Fill_Array(double arr[], int size); //Функция заполнения массива вещественными значениями
void Fill_Array(char arr[], int size); //Функция заполнения массива символьными значенями
void Fill_Array(int arr[], int size, bool ur); //Функция заполнения массива уникальными значениями
void Search_Array(int arr[], int size); //Функция поиска повторяющихся значений
void Search_Array(double arr[], int size);
void Search_Array(char arr[], int size);
void Show_Array(int arr[], int size); //Функция вывода массива
void Show_Array(double arr[], int size); 
void Show_Array(char arr[], int size); 

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");

	const int SIZE = 10;
	bool ur = 0;
	int i_array[SIZE] = {};	
	double d_array[SIZE] = {};
	char c_array[SIZE] = {};

	cout << "Сгенерированный массив уникальных значений:\n";
	Fill_Array(i_array, SIZE, ur);
	Show_Array(i_array, SIZE);
	cout << endl << endl;

	cout << "Сгенерированный массив целых значений:\n";
	Fill_Array(i_array, SIZE);
	Show_Array(i_array, SIZE);
	cout << endl << endl;
	Search_Array(i_array, SIZE);
	cout << endl;

	cout << "Сгенерированный массив вещественных чисел:\n";
	Fill_Array(d_array, SIZE);
	Show_Array(d_array, SIZE);
	Search_Array(d_array, SIZE);
	cout << endl << endl;

	cout << "Сгенерированный массив символов чисел:\n";
	Fill_Array(c_array, SIZE);
	Show_Array(c_array, SIZE);
	Search_Array(d_array, SIZE);
	cout << endl << endl;
}

void Fill_Array(int arr[], int size)
{
	for (int i = 0; i < size; i++) arr[i] = rand() % 5;
}

void Fill_Array(double arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 1000;
		arr[i] /= 100;
	}
}

void Fill_Array(char arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = 65 + rand() % 26;
	}
}

void Fill_Array(int arr[], int size, bool ur)
{
	int rnd;
	for (int i = 0; i < size; )
	{
		ur = true;
		rnd = rand() % 11;
		for (int j = 0; j < size; j++) if (arr[j] == rnd) ur = false;
		if (ur)
		{
			arr[i] = rnd;
			i++;
		}
	}
}

void Search_Array(int arr[], int size)
{
	int count_duplic = 0;
	int duplic_value = 0;
	bool duplic_check;
	for (int i = 0; i < size; i++)
	{
		duplic_value = count_duplic = 0;
		duplic_check = false;
		for (int j = i + 1; j < size; j++) //Цикл проверки элемента массива на повторение
		{
			if (arr[i] == arr[j] && arr[i] >= 0)
			{
				duplic_check = true;
				duplic_value = arr[i];
				break;
			}
		}
		for (int j = 0; j < size; j++) // Цикл вывода повторяющихся значений
		{
		if (arr[j] == duplic_value)
			{
				arr[j] = -arr[j];
				count_duplic++;
			}
		}
		if (duplic_check) cout << "Число " << duplic_value << " повторилось " << count_duplic << " раз" << endl;
	}
}

void Search_Array(double arr[], int size)
{
	int count_duplic = 0;
	double duplic_value = 0;
	bool duplic_check;
	for (int i = 0; i < size; i++)
	{
		duplic_value = count_duplic = 0;
		duplic_check = false;
		for (int j = i + 1; j < size; j++) 
		{
			if (arr[i] == arr[j] && arr[i] > 0)
			{
				duplic_check = true;
				duplic_value = arr[i];
				break;
			}
		}
	for (int j = 0; j < size; j++) 
	{
		if (arr[j] == duplic_value)
		{
			arr[j] = -arr[j];
			count_duplic++;
		}
	}
	if (duplic_check) cout << "Число " << duplic_value << " повторилось " << count_duplic << " раз" << endl;
	}
	cout << "\nОтработала функция поиска повторов"; // Для отображения работы функции
}

void Search_Array(char arr[], int size)
{
	int count_duplic = 0;
	int duplic_value = 0;
	bool duplic_check;
	for (int i = 0; i < size; i++)
	{
		duplic_value = count_duplic = 0;
		duplic_check = false;
		for (int j = i + 1; j < size; j++) 
		{
			if (arr[i] == arr[j] && arr[i] > 0)
			{
				duplic_check = true;
				duplic_value = arr[i];
				break;
			}
		}
	for (int j = 0; j < size; j++) 
	{
		if (arr[j] == duplic_value)
		{
			arr[j] = -arr[j];
			count_duplic++;
		}
	}
	if (duplic_check) cout << "Число " << duplic_value << " повторилось " << count_duplic << " раз" << endl;
	}
	cout << "\nОтработала функция поиска повторов"; // Для отображения работы функции
}

void Show_Array(int arr[], int size)
{
	for (int i = 0; i < size; i++) cout << "[ " << arr[i] << " ] ";
}

void Show_Array(double arr[], int size)
{
	for (int i = 0; i < size; i++) cout << "[ " << arr[i] << " ] ";
}

void Show_Array(char arr[], int size)
{
	for (int i = 0; i < size; i++) cout << "[ " << arr[i] << " ] ";
}