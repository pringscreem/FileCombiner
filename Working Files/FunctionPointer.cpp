#include <iostream>

void myFunction();
//void myFunction()
//{
//	std::cout << "myFunction\n";
//}

void callFuncPtr(void (*fPtr)());
//void callFuncPtr(void (*fPtr)())
//{
//	fPtr();
//}

int main(int argc, char* argv[])
{
	void (*myFuncPtr)() = &myFunction;

	std::cout << "Before calling myFuncPtr\n";
	myFuncPtr();
	std::cout << "After calling myFuncPtr\n";

	std::cout << "Before calling callFuncPtr\n";
	callFuncPtr(myFuncPtr());
	std::cout << "After calling callFuncPtr\n";

	return 0;
}

void myFunction()
{
	std::cout << "myFunction\n";
}

void callFuncPtr(void (*fPtr)())
{
	fPtr;
}


////Chat GPT Example
//#include <iostream>
//
//// Define a function that we will call using a function pointer
//void greet()
//{
//	std::cout << "Hello, World!" << std::endl;
//}
//
//// Define another function that takes a function pointer as a parameter
//void executeFunction(void (*funcPtr)())
//{
//// Call the function using the function pointer
//	funcPtr();
//}
//
//int main()
//{
//// Declare a function pointer and assign it to the greet function
//	void (*funcPtr)() = &greet;
//
//	// Call the function directly using the function pointer
//	funcPtr();
//
//	// Call the function using another function that takes a function pointer as an argument
//	executeFunction(funcPtr);
//
//	return 0;
//}