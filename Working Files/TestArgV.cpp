//This program prints the name of each argument and its' position in the argv array to the console.
#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "argc: " << argc << std::endl;

    for(int i = 0; i < argc; i++)
    {
        std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
    }

    return 0;
}

//argc is one greater than the number of command line arguments given.
//argv[0] is the address of the program itself.
//argv[1] and anything above are the command line arguments given by the user.

/**
 * Example Output (from https://www.onlinegdb.com/online_c++_compiler):
* argc: 5
* argv[0]: ./a.out //"a.out" is the default filename.
* argv[1]: asdf
* argv[2]: qwerty
* argv[3]: dvorak
* argv[4]: 123
 */


// $ ./TestArgv asdf qwerty dvorak
// argc: 4
// argv[0]: C:\msys64\home\sonnl\FileCombiner\TestArgv.exe
// argv[1]: asdf
// argv[2]: qwerty
// argv[3]: dvorak
