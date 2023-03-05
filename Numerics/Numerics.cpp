#include<iostream>
using namespace std;

/*
Задание: В проекте Numerics реализовать перевод десятичного числа в шестнадцатеричную систему счисления (Hexadecimal).
*/

void main()
{
	setlocale(LC_ALL, "ru");
	const int SIZE = 16;
	long long dec;

	cout << "Введите число для преобразования в шестнадцатиричную систему "; cin >> dec;
	cout << endl;

	char dex_value[SIZE] = {};

	if (dec > 0)
	{
		for (int j = SIZE; j > 0; )
		{
			while (dec)
			{
				dex_value[j - 1] = dec % 16 < 10 ? dec % 16 + 48 : dec % 16 + 55;
				dec /= 16;
				j--;
			}
			j--;
			dex_value[j] = -1; //костыль
		}
		for (int i = 0; i < SIZE; i++)
		if (dex_value[i] != int(-1)) cout << dex_value[i]; //работа через костыль
	}
	else
	{
		dec = -dec-1;
		
		for (int j = SIZE; j > 0; )
		{
			while (dec)
			{
				dex_value[j - 1] = 15 - dec % 16 < 10 ? (15 - dec % 16) + 48 : (15 - dec % 16) + 55;
				dec /= 16;
				j--;
			}
		j--;
		dex_value[j] = -1; //костыль
	}
		for (int i = 0; i < SIZE; i++)
		{
			if (dex_value[i] == int(-1)) cout << (char)70; //работа через костыль
			else cout << dex_value[i];
		}
	}

}