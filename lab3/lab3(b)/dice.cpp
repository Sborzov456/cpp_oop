#include "dice.h"
void dice::set_rand()
{
	for (int i = 0; i < SIZE; i++) a[i] = rand() % SIZE;
}
int dice::sum_of_dice()
{
	int sum = 0;
	for (int i = 0; i < SIZE; i++) sum = sum + a[i];
	return sum;
}
int dice::coincidences()
{
	for (int j = 0; j < SIZE; j++)
	{
		for (int i = j + 1; i < SIZE; i++)
		{
			if ((a[i] == a[j]) && (a[i] != -1)) return a[i];
		}
	}
	return -1;
}
void dice::print_dice()
{
	for (int i = 0; i < SIZE; i++)
	{
		if (a[i] != -1) std::cout << a[i] << " ";
	}
}