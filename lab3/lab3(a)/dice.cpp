#include "dice.h"
void dice::set_rand()
{
	t_size = 6;
	for (int i = 0; i < SIZE; i++) a[i] = rand() % SIZE;
}
int dice::add_dice(int value)
{
	int i;
	if ((t_size < SIZE) && (value <= 6))
	{
		for (i = 0; i < SIZE; i++)
		{
			if (a[i] == -1) break;
		}
		a[i] = value;
		t_size++;
		return 1;
	}
	else if (t_size >= SIZE) throw "Error: Current size bigger then max size";
	else throw "Error: Incorrect value";
}
int dice::delete_dice(int value)
{
	int err = -1, i;
	for (i = 0; i < SIZE; i++)
	{
		if (a[i] == value)
		{
			a[i] = -1;
			err = 1;
		}
	}
	return err;
}
int dice::find_value_by_index(int index)
{
	if ((index < SIZE) && (a[index] != -1)) return a[index];
	else return -1;
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
