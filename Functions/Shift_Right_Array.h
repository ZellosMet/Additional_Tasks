#pragma once

template<typename T1, typename T2, typename T3> void Shift_Right_Array(T1 arr[], T2 size, T3 step)
{
	float tmp = 0;
	for (int i = 0; i < step; i++)
	{
		tmp = arr[size - 1];
		for (int j = size - 1; j >= 0; j--) arr[j] = arr[j - 1];
		arr[0] = tmp;
	}
}