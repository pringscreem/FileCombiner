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
	void (*myFuncPtr)() = &myFunction; //The syntax for declaring function pointers is weird

	std::cout << "Before calling myFuncPtr\n";
	myFuncPtr(); //The pointer has to be called with the same syntax as a function.
	std::cout << "After calling myFuncPtr\n";

	std::cout << "Before calling callFuncPtr\n";
	callFuncPtr(myFuncPtr); //Here we don't add the parentheses because we are passing it as a pointer parameter, not accessing it as a function.
	std::cout << "After calling callFuncPtr\n";

	return 0;
}

void myFunction()
{
	std::cout << "myFunction\n";
}

void callFuncPtr(void (*fPtr)())
{
	fPtr();
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