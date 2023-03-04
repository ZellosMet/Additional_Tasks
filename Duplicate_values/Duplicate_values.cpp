#include<iostream>
#include<ctime>
#include<conio.h>

using namespace std;

void Fill_Array(int arr[], int size);
void Show_Array(int arr[], int size);

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");

	const int SIZE = 10;
	int array[SIZE] = {};
	int duplic = 0;
	int dup = 0;
	bool duplic_check;

	cout << "Сгенерированный массив: \n\n";

	Fill_Array(array, SIZE);
	Show_Array(array, SIZE);

	cout << endl;

	for (int i = 0; i < SIZE; i++)
	{		
		dup = 0;
		duplic = 0;
		duplic_check = false;
		for (int j = i+1; j < SIZE; j++)
		{
			if (array[i] == array[j] && array[i] > 0)
			{ 
				duplic_check = true; 
				dup = array[i]; 
				break; 
			}
		}

		for (int j = 0; j < SIZE; j++)
		{
			if (array[j]==dup)
			{
				array[j] = -array[j];
				duplic++;
			}
		}
		if (duplic_check)
		{
		cout << "Число " << dup << " повторилось " << duplic << " раз" << endl;
		}
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