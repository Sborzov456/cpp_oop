#include <iostream>
#define SIZE 6
class dice
{
	private:
		int a[SIZE];
		int t_size;
	public:
		dice()
		{
			t_size = 0;
			for (int i = 0; i < SIZE; i++) a[i] = -1;
		}
		void set_rand();
		int add_dice(int value);
		int delete_dice(int value);
		int find_value_by_index(int index);
		int sum_of_dice();
		int coincidences();
		void print_dice();
};