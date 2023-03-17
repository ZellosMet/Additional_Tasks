#pragma once
template<typename T1, typename T2, typename T3> void Shift_Left_Array(T1 arr[], T2 size, T3 step)
{
	float tmp = 0;
	for (int i = 0; i < step; i++)
	{
		tmp = arr[0];
		for (int j = 0; j < size; j++) arr[j] = arr[j + 1];
		arr[size - 1] = tmp;
	}
}