#pragma once
#include <string>

class FileCombiner
{
    public:
        FileCombiner(int argcIn, char** argvIn);
        void Run(int argc, char** argv);
        void Help();

    private:
        int argc = 0;
        char** argv = nullptr;
};