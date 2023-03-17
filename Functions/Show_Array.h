#pragma once

#include<iostream>
#include<ctime>
#include<conio.h>

template<typename T1, typename T2, typename T3> void Show_Array(T1 arr[], T2 size, T3 target)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == target)
		{
			std::cout << "| " << arr[i] << " | ";
		}
		else
		{
			std::cout << "< " << arr[i] << " > ";
		}
	}
}