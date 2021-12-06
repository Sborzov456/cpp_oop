#include "dice.h"
int main()
{
	dice d;
	std::cout << "Dice: ";
	d.print_dice();
	std::cout << std::endl;
	int choice = -1;
	while (choice != 0)
	{
		std::cout << "0. Quit" << std::endl;
		std::cout << "1. Set rand dice" << std::endl;
		std::cout << "2. Add dice" << std::endl;
		std::cout << "3. Delete dice" << std::endl;
		std::cout << "4. Find dice by index" << std::endl;
		std::cout << "5. Summ of dice" << std::endl;
		std::cout << "6. Find coincidences" << std::endl;
		std::cout << "7. Print dice" << std::endl;
		std::cout << "8. Copy one object to another" << std::endl;
		std::cin >> choice;
		if (choice == 1)
		{
			d.set_rand();
		}
		if (choice == 2)
		{
			int value;
			std::cout << "Enter value: ";
			std::cin >> value;
			d += value;
		}
		if (choice == 3)
		{
			int value;
			std::cout << "Enter value: ";
			std::cin >> value;
			int flag = -1;
			for (int i = 0; i < d.get_size(); i++)
			{
				if (d[i] == value)
				{
					flag = 1;
					d -= value;
					break;
				}
			}
			if (flag == -1) std::cout << "Error!" << std::endl;
		}
		if (choice == 4)
		{
			int index;
			std::cout << "Enter index: ";
			std::cin >> index;
			if (d[index] == -1) std::cout << "Error" << std::endl;
			else std::cout << "Value: " << d[index] << std::endl;
		}
		if (choice == 5)
		{
			std::cout << "Summ: " << d.sum_of_dice() << std::endl;;
		}
		if (choice == 6)
		{
			if (d.coincidences() != -1) std::cout << "Repeats: " << d.coincidences() << std::endl;
			else std::cout << "No coincidences" << std::endl;
		}
		if (choice == 7)
		{
			std::cout << "Dice: ";
			d.print_dice();
			std::cout << std::endl;
		}
		if (choice == 8)
		{
			dice d_copy(d);
			std::cout << "Copy object: ";
			d_copy.print_dice();
			std::cout << std::endl;
		}
	}
	return 0;
}