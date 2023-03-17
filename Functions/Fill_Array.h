#pragma once

template<typename T1, typename T2> void Fill_Array(T1 arr[], T2 size)
{
	srand(time(NULL));

	int rnd_i;
	float rnd_f;
	bool check;
	for (int i = 0; i < size; )
	{
		check = true;
		rnd_i = rand() % 9;
		rnd_f = (float)(rand() % 99 + 1) / 100;
		rnd_f += rnd_i;
		for (int j = 0; j < size; j++) if (arr[j] == rnd_f) check = false;
		if (check)
		{
			arr[i] = rnd_f;
			i++;
		}
	}
}
