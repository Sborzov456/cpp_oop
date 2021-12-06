#include <iostream>
class dice
{
	private:
		int size;
		int* a;
	public:
		dice();//constructor 
		dice(int s);//constructor whith size
		dice(const dice& from_obj);//copy constructor
		dice(dice& from_obj)
		{
			a = from_obj.a;
			size = from_obj.size;
			from_obj.a = nullptr;
		}
		~dice();//destructor 
		int get_size() const { return size; }
		int* get_a() const { return a; }
		void set_rand();
		int sum_of_dice();
		int coincidences();
		void print_dice();
		int operator [] (int index)
		{
			if (index < size) return a[index];
			else return -1;
		}
		dice& operator += (int value)
		{
			int flag = -1;
			for (int i = 0; i < size; i++) if (a[i] == -1) flag = 1;
			if (flag == -1)
			{
				int* buf = new int[size + 1];
				for (int i = 0; i < size; i++) buf[i] = a[i];
				size++;
				delete[]a;
				a = buf;
				a[size - 1] = value;
			}
			else
			{
				for (int i = 0; i < size; i++)
				{
					if (a[i] == -1)
					{
						a[i] = value; 
						break;
					}
				}
			}
			return *this;
		}
		dice& operator -= (int value)
		{
			for (int i = 0; i < size; i++) if (a[i] == value) a[i] = -1;
			return *this;
		}
};