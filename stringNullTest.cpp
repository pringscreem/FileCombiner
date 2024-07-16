#include <iostream>

int strCmp(char string1[], char string2[]);

int main(int argc, char* argv[])
{
    //This works:
    char string1[] = "asdf";
    char string2[] = "dvorak";
    //This is because the compiler knows the array size at compile time (from the string length).
    //It needs the length because it is on the stack.
    //Character arrays are null-terminated, apparently (what about int's or float's?).
    //  int's and float's can't be compared using strcmp() (they would have to be in ASCII 
    //  values, as characters, and that would just be a string comparison).
    //  int's and float's have their own operators ("==", "<", ">", etc.) implemented for 
    //  comparisons.

    //This fails (segmentation fault):
    //char* string1 = argv[1];
    //char* string2 = argv[2];
    //It appears that char* is not null-terminated, but a char array, i.e. char str[], is.

    //This also failed:
    //char* string11 = argv[1];
    //char* string22 = argv[2];
    //char string1[] = string11;
    //char string2[] = string22;

    std::cout << "The result of strCmp is " 
              << strCmp(string1, string2) 
              << "\n";
}

int strCmp(char string1[], char string2[])
{
    for(int i = 0; ; i++)
    {
        if(string1[i] != string2[i])
        {
            return string1[i] < string2[i] ? -1 : 1;
        }

        if(string1[i] == '\0')
        {
            return 0;
        }
    }
}