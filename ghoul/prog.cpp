#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
#define GHOUL 142
void outSpace() {
	for (int i = 0; i < 43; i++)
		cout << " ";
}
int main()
{
	int dead = 1000;
	while(dead > 0)
	{
		outSpace();
		std::cout << dead << " - 7 = " << dead - 7 << endl;
		dead -= 7;
		this_thread::sleep_for(chrono::milliseconds(50));
	}
	outSpace();
	cout << "I am ... Ghoul\n";
}