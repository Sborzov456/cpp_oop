#include <iostream>
#define SIZE 6
class dice
{
	private:
		int a[SIZE];
	public:
		dice()
		{
			for (int i = 0; i < SIZE; i++) a[i] = i + 1;
		}
		dice& operator += (int value)
		{
			for (int i = 0; i < SIZE; i++) if (a[i] == -1) { a[i] = value; break; };
			return *this;
		}
		dice& operator -= (int value)
		{
			for (int i = 0; i < SIZE; i++) if (a[i] == value) a[i] = -1;
			return *this;
		}
		int operator [] (int index)
		{
			if (index < SIZE) return a[index];
			else return -1;
		}
		void set_rand();
		int sum_of_dice();
		int coincidences();
		void print_dice();

};