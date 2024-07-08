#include "FileCombiner.h"
#include <iostream>
#include <fstream>

FileCombiner::FileCombiner(int argcIn, char** argvIn)
{
    argc = argcIn;
    argv = argvIn;
}

void FileCombiner::Help()
{
    std::cout << "This program combines multiple files into a single document.\n";
    std::cout << "It is executed from the command line with several arguments:\n";
    std::cout << "The first argument must be either the \"help\" or \"combine\" command.\n";
    std::cout << "The \"help\" command prints this help menu.\n";
    std::cout << "The \"combine\" command executes the file combining operation with the designated files.\n";
    std::cout << "The second argument must be the output file name.\n";
    std::cout << "The rest of the arguments must be the names of the files to combine.\n";
    std::cout << "of the files and create a file with the name entered in the second argument.\n";
}


//Probably working, returning an error on this computer (not using makefiles or CMake yet).
void FileCombiner::Run(int argc, char** argv)
{
    std::ofstream outputFile;
    std::string outputFilename(argv[2]);//= static_cast<std::string>(argv[2]) + ".cpp"; //argv[2] should be the output name (second argument given)
                                 //static_cast can't call constructors, and converting from a C-Style String to a STD::String is done with a constructor.
    std::cout << "The outputFilename is " << outputFilename << std::endl;
    // outputFile.open(outputFilename, std::ios_base::app); //Open the string held in outputFilename ("argv[2].cpp") in append mode.

    for(int i = 2; i < argc; i++)
    {
         std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
         std::ifstream inputFile;
         inputFile.open(static_cast<std::string>(argv[i]));
         std::string outputString;
         int count = 0;
         while(std::getline(inputFile, outputString))
         {
            outputFile << outputString << '\n';
            std::cout << "Line " << count << " added to " << outputFilename << std::endl;
            count++;
         }
    
    outputFile.close();
    }
}