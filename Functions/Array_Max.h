#pragma once

template<typename T1, typename T2> T1 Array_Max(T1 arr[], T2 size)
{
	float max = arr[0];
	for (int i = 0; i < size; i++) if (max < arr[i]) max = arr[i];
	return max;
}
