#include "FileCombiner.h"
#include <iostream>
#include <fstream>

FileCombiner::FileCombiner()
{
    //
}

void FileCombiner::Run()
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