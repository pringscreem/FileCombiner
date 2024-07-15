#pragma once
#include <string>

class FileCombiner
{
    public:
        FileCombiner(int argcIn, char** argvIn);
        void Combine(); //I don't think we need to pass any variables to Combine because they are passed/copied in the constructor.
        void Help();
        void Run();
        void PrintArgv();

    private:
        int argc = 0;
        char** argv = nullptr;
};