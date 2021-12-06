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
			std::cin >> choice;
			try {
				if (choice == 1)
				{
					d.set_rand();
				}
				if (choice == 2)
				{
					int value;
					std::cout << "Enter value: ";
					std::cin >> value;
					d.add_dice(value);
				}
				if (choice == 3)
				{
					int value;
					std::cout << "Enter value: ";
					std::cin >> value;
					if (d.delete_dice(value) == -1) std::cout << "Error" << std::endl;;
				}
				if (choice == 4)
				{
					int index;
					std::cout << "Enter index: ";
					std::cin >> index;
					if (d.find_value_by_index(index) == -1) std::cout << "Error" << std::endl;
					else std::cout << "Value: " << d.find_value_by_index(index) << std::endl;
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
			}
			catch (const char* msg)
			{
				std::cout << msg << std::endl;
			}
		}
	return 0;
}