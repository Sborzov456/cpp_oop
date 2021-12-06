#include "dice.h"
dice::dice()
{
	size = 6;
	a = new int[size];
	for (int i = 0; i < 6; i++) a[i] = i + 1;
}
dice::dice(int s)
{
	size = s;
	a = new int[size];
	for (int i = 0; i < size; i++) a[i] = i + 1;
}
dice::dice(const dice& from_obj)
{
	size = from_obj.get_size();
	a = new int[size];
	for (int i = 0; i < size; i++) a[i] = from_obj[i];
}
dice::~dice()
{
	delete[]a;
}
void dice::set_rand()
{
	for (int i = 0; i < size; i++) a[i] = rand() % size;
}
int dice::sum_of_dice()
{
	int sum = 0;
	for (int i = 0; i < size; i++) sum = sum + a[i];
	return sum;
}
int dice::coincidences()
{
	for (int j = 0; j < size; j++)
	{
		for (int i = j + 1; i < size; i++)
		{
			if ((a[i] == a[j]) && (a[i] != -1)) return a[i];
		}
	}
	return -1;
}
void dice::print_dice()
{
	for (int i = 0; i < size; i++)
	{
		if (a[i] != -1) std::cout << a[i] << " ";
	}
}