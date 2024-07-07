#include "FileCombiner.h"
#include <iostream>
#include <fstream>

FileCombiner::FileCombiner(int argcIn, char** argvIn)
{
    argc = argcIn;
    argv = argvIn;
}

void Help()
{
    std::cout << "This program combines multiple C++ files into a single document.\n";
    std::cout << "It is executed from the command line with several arguments:";
    std::cout << "The first argument should be either the "help" or "combine" command.";
    std::cout << "The second argument should be the output file name.";
    std::cout << "The rest of the arguments should be the names of the files to combine.";
    std::cout << "If the first argument is "help", a description of how to use the program";
    std::cout << "should be printed to the console.";
    std::cout << "If the first argument is "combine", the program should execute the combining";
    std::cout << "of the files and create a file with the name entered in the second argument.";
}

void FileCombiner::Run(int argc, char** argv)
{

    //std::ofstream outputFile;
    std::string outputFilename = static_cast<std::string>(argv[2]) + ".cpp"; //argv[2] should be the output name (second argument given)
    //std::cout << "The outputFilename is " << outputFilename << std::endl;
    std::ofstream outputFile;
    outputFile.open(outputFilename, std::ios_base::app); //Open the string held in outputFilename ("argv[2].cpp") in append mode.

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
        //  outputFile << inputFile; //Incorrect... We have to use getline instead (and go through a loop)

    }

    outputFile.close();
}