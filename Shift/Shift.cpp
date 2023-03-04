#include<iostream>
#include<ctime>
#include<conio.h>

using namespace std;

/*�������:	������� ������ �� ������ ��������� ��������� ����������� ���������� ������� � ��������� �� 0 �� 10;
			����������� ����������� ����� ������� �� �������� ����� ���������. �������� ������� ������ �� ������ ��������� �� ����� � ������ �������,
			� ������ �������� ���� ������������ � ������;
			��������� ����������� ����� ������� ������.
*/

#define MOVE_LEFT 75  //������� ���������� ��� ������ � ����������
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

void Fill_Array(int arr[], int size); //������� ���������� ������� ����������� ����������
void Show_Array(int arr[], int size); //������� ������ �������
void Shift_Array(int arr[], int size, int shift, int step); //������� ������ ��������� ������� ��������(�����/����)


void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");

	int control;
	int step = 1;
	int shift = 0;
	const int SIZE = 10;
	int array[SIZE] = {};

	cout << "����������: ��� ������� �������� �� ����� �� 1 �� 5(����������� 1). ����������� ���������� ����������� ��������\n\n";
	cout << "��������������� ������: \n\n";

	Fill_Array(array, SIZE);
	Show_Array(array, SIZE);
	cout << endl << endl;

	do //���� ������ �������
	{
		control = _getch();
		switch (control)
		{
		case One: step = 1; cout << "���������� ��� 1\n\n"; break;
		case Two: step = 2; cout << "���������� ��� 2\n\n"; break;
		case Three: step = 3; cout << "���������� ��� 3\n\n"; break;
		case Four: step = 4; cout << "���������� ��� 4\n\n"; break;
		case Five: step = 5; cout << "���������� ��� 5\n\n"; break;
		case MOVE_LEFT: shift = MOVE_LEFT; cout << "����� �� ���� � �����: " << step << endl;
			Shift_Array(array, SIZE, shift, step); Show_Array(array, SIZE); cout << endl << endl; break;
		case MOVE_RIGHT: shift = MOVE_RIGHT; cout << "����� �� ����� � �����: " << step << endl;
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
		check = false;
		rnd = rand() % 20;
		for (int j = 0; j < size; j++) if (arr[j] == rnd) check = true;
		if (!check)
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