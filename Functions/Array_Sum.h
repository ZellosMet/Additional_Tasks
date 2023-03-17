#pragma once

template<typename T1, typename T2> T1 Array_Sum(T1 arr[], T2 size)
{
	float sum = 0;
	for (int i = 1; i < size; i++) sum += arr[i];
	return sum;
}