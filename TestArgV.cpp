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
* argv[0]: ./a.out
* argv[1]: asdf
* argv[2]: qwerty
* argv[3]: dvorak
* argv[4]: 123
 */