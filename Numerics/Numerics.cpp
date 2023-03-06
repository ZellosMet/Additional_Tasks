#include<iostream>
using namespace std;

/*
Задание: В проекте Numerics реализовать перевод десятичного числа в шестнадцатеричную систему счисления (Hexadecimal).
*/

#define FIRST_ASCII_NUMBER 48
#define FIRST_ASCII_LETTER 55
#define ASCII_LETTER_F 70
#define HIDE -1

void Show_Array(char arr[], int size);

void main()
{
	setlocale(LC_ALL, "ru");
	const int NUMBER_SYSTEM = 16;
	long long dec_number;

	cout << "Введите число для преобразования в шестнадцатиричную систему "; cin >> dec_number;
	cout << endl;

	char dex_number[NUMBER_SYSTEM] = {};

	if (dec_number > 0)
	{
		for (int j = NUMBER_SYSTEM; j > 0; )
		{
			while (dec_number)
			{
				dex_number[j - 1] = dec_number % NUMBER_SYSTEM < 10 ? dec_number % NUMBER_SYSTEM + FIRST_ASCII_NUMBER : dec_number % NUMBER_SYSTEM + FIRST_ASCII_LETTER;
				dec_number /= NUMBER_SYSTEM;
				j--;
			}
			j--;
			dex_number[j] = HIDE;
		}
		Show_Array(dex_number, NUMBER_SYSTEM);
	}
	else if (dec_number < 0)
	{
		dec_number = -dec_number - 1;
		for (int j = NUMBER_SYSTEM; j > 0; )
		{
			while (dec_number)
			{
				dex_number[j - 1] = NUMBER_SYSTEM - 1 - dec_number % NUMBER_SYSTEM < 10 ? (NUMBER_SYSTEM - 1 - dec_number % NUMBER_SYSTEM) + FIRST_ASCII_NUMBER : (NUMBER_SYSTEM - 1 - dec_number % NUMBER_SYSTEM) + FIRST_ASCII_LETTER;
				dec_number /= NUMBER_SYSTEM;
				j--;
			}
			j--;
			dex_number[j] = ASCII_LETTER_F;
		}
		Show_Array(dex_number, NUMBER_SYSTEM);
	}
	else cout << "Результат: " << dec_number << endl;
}

void Show_Array(char arr[], int size)
{
	cout << "Результат: ";
	for (int i = 0; i < size; i++) if (arr[i] != int(HIDE)) cout << arr[i];
	cout << endl;
}