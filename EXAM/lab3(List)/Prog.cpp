#include "List.h"
int dialog(const int numberOfOptions, const char** msgs)
{
	for (int i = 0; i < numberOfOptions; i++)
		std::cout << msgs[i] << std::endl;
	int choice;
	std::cout << "Option --> ";
	std::cin >> choice;
	if (choice > numberOfOptions || choice < 0) {
		std::cout << "Invalid input!\n";
		return -1;
	}
	else return choice;
}

List foo() {
	List tmpList = { 1,1,1 };
	return tmpList;
}

int main()
{
	std::cout << "      LIST TESTING\n\n";
	List list;
	std::cout << "Enter list: ";
	try {
		std::cin >> list;
	}
	catch (const std::exception& exc) {
		std::cerr << exc.what();
	}
	int option = -1;
	const char* msgs[] = {
	"[0]: Quit",
	"[1]: Push Back",
	"[2]: Push Back OVERLOAD",
	"[3]: Add By Before Node",
	"[4]: Delete By Data",
	"[5]: Delete By Data OVERLOAD",
	"[6]: Print",
	"[7]: Print OVERLOAD",
	"[8]: Copy Constructor",
	"[9]: Moving Constructor"
	};

	while (option) {
		option = dialog(10, msgs);
		if (option == 1) {
			int data;
			std::cout << "Data --> ";
			std::cin >> data;
			list.pushBack(data);
		}
		if (option == 2) {
			int data;
			std::cout << "Data --> ";
			std::cin >> data;
			list += data;
		}
		if (option == 3) {
			int data;
			std::cout << "Data --> ";
			std::cin >> data;

			int dataBefore;
			std::cout << "Data Before --> ";
			std::cin >> dataBefore;

			if(!list.addIntoPos(data, dataBefore))
				std::cout << "Data Befor not found!\n";
		}
		if (option == 4) {
			int data;
			std::cout << "Data --> ";
			std::cin >> data;
			if (!list.deleteByData(data))
				std::cout << "Node not found!\n";
		}
		if (option == 5) {
			int data;
			std::cout << "Data --> ";
			std::cin >> data;
			list -= data;
		}
		if (option == 6) {
			list.printList();
		}
		if (option == 7) {
			std::cout << list;
		}
		if (option == 8) {
			List copyList(list);
			std::cout << "Copyed List: " << copyList;
		}
		if (option == 9) {
			List movedList(foo());
			std::cout << "Moved List: " << movedList;
		}
	}
	return 0;
}