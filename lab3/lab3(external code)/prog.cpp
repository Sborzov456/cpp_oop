#include <iostream>
#include <stdexcept>
#include "sequence.h"
int dialog(const char** msgs, int rc)
{
	int choice;
	while (1)
	{
		for (int i = 0; i < rc; i++) std::cout << msgs[i] << std::endl;
		std::cout << "Enter your choice: ";
		std::cin >> choice;
		if (choice >= 0 && choice < rc) break;
		if (!std::cin.good()) {
			throw std::exception("Error! Incorrect input\n");
		}
		throw std::exception("Error! This option does not exist\n");
	}
	return choice;
}
int main()
{
	int k;
	std::cout << "Enter 1 element in 1 chain" << std::endl;
	std::cin >> k;
	Chain chain1(k);
	std::cout << chain1;
	const char* msgs[] = { 
	"0. Quit",
	"1. Add",
	"2. Increasing or descending sequence?",
	"3. Average vs The most frequent" };
	int choice = -1;
	while (choice != 0)
	{
		try
		{
			choice = dialog(msgs, 4);
			std::cout << choice << std::endl;
		}
		catch (const std::exception& exc)
		{
			std::cerr << exc.what();
		}
		if (choice == 1)
		{
			int q;
			std::cout << "Enter number" << std::endl;
			if ((std::cin >> q).good())
			{
				chain1.push(q);
				std::cout << chain1;
			}
			else 
			{
				std::cin.clear();
				std::cout << "Invalid number" << std::endl;
			}
		}
		if (choice == 2)
		{
			int i = 0;
			int flag = 0;
			Chain chain2;
			chain2 = und_chain(chain1);
			if ((chain1.get_top() >= 3) && (chain2.get_top() == chain1.get_top()))
			{
				for (i = 0; i < chain1.get_top(); i++)
				{
					if (i > 0 && flag == 0)
					{
						if (chain1[i] >= chain1[i - 1]) flag = 1;
						else flag = 2;
					}
				}
				if (flag == 1) std::cout << "Sequence is increasing" << std::endl;
				if (flag == 2) std::cout << "Sequence is decreasing" << std::endl;
			}
			else std::cout <<"The sequence is not increasing or decreasing"<< std::endl;
		}
		if (choice == 3)
		{
			double average;
			double summ = 0;
			int tmf = -1;
			for (int i = 0; i < chain1.get_top(); i++)
			{
				summ = summ + chain1[i];
				if (chain1.same_elem(chain1[i]) > tmf) tmf = chain1[i];
			}
			average = summ / chain1.get_top();
			std::cout << "Average: " << average;
			std::cout << std::endl;
			std::cout << "The most frequent: " << tmf;
			std::cout << std::endl;
		}
	}
	return 0;
}