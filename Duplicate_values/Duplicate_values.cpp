#include<iostream>
#include<ctime>

using namespace std;

/*
Задание:	Есть массив из 10 элементов. Значения некоторых элементов в этом массиве заведомо повторяются.  
			Необходимо найти повторяющиеся значения в этом массиве, вывести их на экран, и вывести на экран количество повторений каждого такого значения.
*/

void Fill_Array(int arr[], int size); //Функция заполнения массива
void Show_Array(int arr[], int size); //Функция вывода массива

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");

	const int SIZE = 10;
	int array[SIZE] = {};
	int count_duplic = 0;
	int duplic_value = 0;
	bool duplic_check;

	cout << "Сгенерированный массив: \n\n";

	Fill_Array(array, SIZE);
	Show_Array(array, SIZE);

	cout << endl << endl;

	for (int i = 0; i < SIZE; i++) 
	{		
		duplic_value = count_duplic = 0;
		duplic_check = false;
		for (int j = i+1; j < SIZE; j++) //Цикл проверки элемента массива на повторение
		{
			if (array[i] == array[j] && array[i] > 0)
			{ 
				duplic_check = true; 
				duplic_value = array[i];
				break; 
			}
		}

		for (int j = 0; j < SIZE; j++) // Цикл вывода повторяющихся значений
		{
			if (array[j]== duplic_value)
			{
				array[j] = -array[j];
				count_duplic++;
			}
		}
		if (duplic_check) cout << "Число " << duplic_value << " повторилось " << count_duplic << " раз" << endl;
	}

}

void Fill_Array(int arr[], int size)
{
	for (int i = 0; i < size; i++) arr[i] = rand() % 9 +1;
}

void Show_Array(int arr[], int size)
{
	for (int i = 0; i < size; i++) cout << "[ " << arr[i] << " ] ";
}