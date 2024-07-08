#include <iostream>
#include "FileCombiner.h"

int main(int argc, char* argv[])
{
    FileCombiner fileCombiner(argc, argv);

    fileCombiner.Help();

    return 0;
}