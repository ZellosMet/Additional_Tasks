#pragma once

template<typename T1, typename T2> T1 Array_Min(T1 arr[], T2 size)
{
	float min = arr[0];
	for (int i = 0; i < size; i++) if (min > arr[i]) min = arr[i];
	return min;
}