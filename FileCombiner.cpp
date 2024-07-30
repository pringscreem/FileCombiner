/*
*MIT License
*
*Copyright(c)[2024][Scott Sonnleitner]
*
*Permission is hereby granted, free of charge, to any person obtaining a copy
*of this softwareand associated documentation files(the "Software"), to deal
*in the Software without restriction, including without limitation the rights
*to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
*copies of the Software, and to permit persons to whom the Software is
*furnished to do so, subject to the following conditions :
*
*The above copyright noticeand this permission notice shall be included in all
*copies or substantial portions of the Software.
*
*THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
*AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
*SOFTWARE.
*/


#include "FileCombiner.h"
#include <iostream>
#include <fstream>
#include <cstring>

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
             //if(argv[1] != 'simplecombine')
             for(int j = 3; j < argc; j++)
             {
                 checkFileName = argv[j];
                 //If there is a match, trip the flag
                 if(outputString.find("#include \"" + checkFileName + "\"") != std::string::npos)
                 {
                     skipLineFlag = true;
                 }
             }
             //If the flag has been tripped, skip the line //Call the helper function
             if(skipLineFlag)
             {
                 //Skip the line //Call the helper function
                 //std::cout << "Line " << count << " NOT added to " << outputFilename << std::endl;
                 std::cout << "Line " << count << " called helper function on " << inputFileName << std::endl;
                 funcPtr(outputFile, outputString);
                 count++;
                 continue;//Something isn't right with the logic here.
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
    PrintArgv();
    //std::string helpStr = "help";
    //if(argv[1] == helpStr.c_str())
    if(!strcmp(argv[1], "help"))
    {
        Help();
        std::cout << "Line 92\n";
    }
    else if(!strcmp(argv[1], "combine"))
    {
        //std::string combineStr = "combine";
        //if(argv[1] == combineStr.c_str())
        {
            funcPtr = &HelperCombine;
            //Combine();
        }
    }
    else if(!strcmp(argv[1], "simplecombine"))
    {
        //std::string combineStr = "combine";
        //if(argv[1] == combineStr.c_str())
        {
            funcPtr = &HelperSimpleCombine;
            //SimpleCombine();
        }
    }
    else if(!strcmp(argv[1], "commentcombine"))
    {
        //std::string combineStr = "combine";
        //if(argv[1] == combineStr.c_str())
        {
            funcPtr = &HelperCommentCombine;
            //CommentCombine();
        }
    }
    else
    {
        std::cout << "Command not recognized.  "
                  << "Use \"help\" to see instructions "
                  << "or \"combine\", \"simplecombine\" "
                  << "or \"commentcombine\" to combine files.\n";

        for(int i = 0; i < argc; i++)
        {
            std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
        }
    }
}

void FileCombiner::PrintArgv()
{
    for(int i = 0; i < argc; i++)
    {
        std::cout << "argv[" << i << "]: " << argv[i] << "\n";
    }
}

void FileCombiner::HelperCombine(std::ofstream outputFile, std::string outputString)
{
    //Skip the line //Do nothing...?
}

void FileCombiner::HelperSimpleCombine(std::ofstream outputFile, std::string outputString)
{
    //Don't skip the line //Add the line
    outputFile << outputString;
}

void FileCombiner::HelperCommentCombine(std::ofstream outputFile, std::string outputString)
{
    //Comment out the line //Add the line with the comment symbol at the beginning
    outputFile << "//" << outputString;
}

//void FileCombiner::SimpleCombine()
//{
//    std::ofstream outputFile;
//    std::string outputFilename(argv[2]);//= static_cast<std::string>(argv[2]) + ".cpp"; //argv[2] should be the output name (second argument given)
//                                 //static_cast can't call constructors, and converting from a C-Style String to a STD::String is done with a constructor.
//    std::cout << "The outputFilename is " << outputFilename << std::endl;
//    outputFile.open(outputFilename, std::ios_base::out); //Open the string held in outputFilename ("argv[2].cpp") in append mode ("std::ios_base::app")
//                                                         //We might want the regular output mode, std::ios_base::out 
//                                                         //(this will make a file if it doesn't exist, whereas append mode will not).
//    for(int i = 3; i < argc; i++) //The first three arguments are the path, the command, and the output file.
//    {
//        //Open the desired file
//        std::ifstream inputFile;
//        std::string inputFileName(argv[i]);
//        inputFile.open(inputFileName);
//        std::string outputString;
//        int count = 1;
//            //Console output statements to illustrate what is happening
//        std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
//        std::cout << "inputFileName: " << inputFileName << std::endl;
//        //Variables for the while-loop
//        std::string checkFileName;
//        bool skipLineFlag = false;
//   //Go through the file line by line
//        while(std::getline(inputFile, outputString))
//        {
//                //Copy the line
//                outputFile << outputString << '\n';
//                std::cout << "Line " << count << " added to " << outputFilename << std::endl;
//                count++;   
//        }
//        inputFile.close();
//    }
//    outputFile.close();
//}

//void FileCombiner::CommentCombine()
//{
//    std::ofstream outputFile;
//    std::string outputFilename(argv[2]);//= static_cast<std::string>(argv[2]) + ".cpp"; //argv[2] should be the output name (second argument given)
//                                 //static_cast can't call constructors, and converting from a C-Style String to a STD::String is done with a constructor.
//    std::cout << "The outputFilename is " << outputFilename << std::endl;
//    outputFile.open(outputFilename, std::ios_base::out); //Open the string held in outputFilename ("argv[2].cpp") in append mode ("std::ios_base::app")
//                                                         //We might want the regular output mode, std::ios_base::out 
//                                                         //(this will make a file if it doesn't exist, whereas append mode will not).
//    for(int i = 3; i < argc; i++) //The first three arguments are the path, the command, and the output file.
//    {
//        //Open the desired file
//        std::ifstream inputFile;
//        std::string inputFileName(argv[i]);
//        inputFile.open(inputFileName);
//        std::string outputString;
//        int count = 1;
//            //Console output statements to illustrate what is happening
//        std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
//        std::cout << "inputFileName: " << inputFileName << std::endl;
//        //Variables for the while-loop
//        std::string checkFileName;
//        bool skipLineFlag = false;
//   //Go through the file line by line
//        while(std::getline(inputFile, outputString))
//        {
//            //Reset the flag
//            skipLineFlag = false;
//            //Check the current line for every filename
//            for(int j = 3; j < argc; j++)
//            {
//                checkFileName = argv[j];
//                //If there is a match, trip the flag
//                if(outputString.find("#include \"" + checkFileName + "\"") != std::string::npos)
//                {
//                    skipLineFlag = true;
//                }
//            }
//            //If the flag has been tripped, skip the line //Comment out the line
//            if(skipLineFlag)
//            {
//                //SKip the line //Comment out the line
//                outputFile << "//" << outputString << '\n';
//                std::cout << "Line " << count << " COMMENTED OUT and added to " << outputFilename << std::endl;
//                count++;
//                continue;
//            }
//            //Otherwise, copy the line
//            else
//            {
//                outputFile << outputString << '\n';
//                std::cout << "Line " << count << " added to " << outputFilename << std::endl;
//                count++;
//            }
//        }
//        inputFile.close();
//    }
//    outputFile.close();
//}