#include <iostream>
#include "FileCombiner.h"

int main(int argc, char* argv[])
{
    FileCombiner fileCombiner(argc, argv);

    //fileCombiner.Help();
    fileCombiner.Run(argc, argv);

    return 0;
}