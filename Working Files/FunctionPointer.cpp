#include <iostream>

void myFunction();

int main(int argc, char* argv[])
{
	void (*myFuncPtr)() = &myFunction;

	std::cout << "Before calling myFuncPtr\n";
	myFuncPtr;
	std::cout << "After calling myFuncPtr\n";

	return 0;
}

void myFunction()
{
	std::cout << "myFunction\n";
}