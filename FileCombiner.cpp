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
void FileCombiner::Combine()
{
    std::ofstream outputFile;
    std::string outputFilename(argv[2]);//= static_cast<std::string>(argv[2]) + ".cpp"; //argv[2] should be the output name (second argument given)
                                 //static_cast can't call constructors, and converting from a C-Style String to a STD::String is done with a constructor.
    std::cout << "The outputFilename is " << outputFilename << std::endl;
    outputFile.open(outputFilename, std::ios_base::out); //Open the string held in outputFilename ("argv[2].cpp") in append mode ("std::ios_base::app")
                                                         //We might want the regular output mode, std::ios_base::out 
                                                         //(this will make a file if it doesn't exist, whereas append mode will not).
    for(int i = 3; i < argc; i++) //The first three arguments are the path, the command, and the output file.
    {
        //Open the desired file
         std::ifstream inputFile;
         std::string inputFileName(argv[i]);
         inputFile.open(inputFileName);
         std::string outputString;
         int count = 1;
             //Console output statements to illustrate what is happening
             std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
             std::cout << "inputFileName: " << inputFileName << std::endl;
             //Variables for the while-loop
             std::string checkFileName;
             bool skipLineFlag = false;
        //Go through the file line by line
         while(std::getline(inputFile, outputString))
         {
             //Reset the flag
             skipLineFlag = false;
             //Check the current line for every filename
             for(int j = 3; j < argc; j++)
             {
                 checkFileName = argv[j];
                 //If there is a match, trip the flag
                 if(outputString.find("#include \"" + checkFileName + "\"") != std::string::npos)
                 {
                     skipLineFlag = true;
                 }
             }
             //If the flag has been tripped, skip the line
             if(skipLineFlag)
             {
                 //Skip the line
                 std::cout << "Line " << count << " NOT added to " << outputFilename << std::endl;
                 count++;
                 continue;
             }
             //Otherwise, copy the line
             else
             {
                 outputFile << outputString << '\n';
                 std::cout << "Line " << count << " added to " << outputFilename << std::endl;
                 count++;
             }
         }
         inputFile.close();
    }
    outputFile.close();
}

void FileCombiner::Run()
{
    if(argv[1] == "help")
    {
        Help();
    }
    else if(argv[i] == "combine")
    {
        Combine();
    }
}