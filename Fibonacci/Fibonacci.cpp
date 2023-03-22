#include<iostream>
using namespace std;

//#define FIBONACCI_LIMIT
//#define FIBONACCI_ELEMENT

unsigned long long Fibonacci(int i);

void main()
{

	int value;
	setlocale(LC_ALL, "ru");

#ifdef FIBONACCI_LIMIT

	cout << "Введите предел ряда Фибоначчи: "; cin >> value;

	for (int i = 0; Fibonacci(i) < value; i++)
	{
		cout << Fibonacci(i) << " ";
	}

#endif

#ifdef FIBONACCI_ELEMENT
	
	cout << "Введите количество элементов ряда Фибоначчи: "; cin >> value;

	for (int i = 0; i < value; i++)
	{
		cout << Fibonacci(i) << " ";
	}
	
#endif 
}

unsigned long long Fibonacci(int i)
{
	if (i == 0) return 0;
	if (i == 1 || i == 2) return 1;
	return Fibonacci(i - 1) + Fibonacci(i - 2);
}