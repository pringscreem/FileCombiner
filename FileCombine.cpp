#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[])
{

    //std::ofstream outputFile;
    std::string outputFilename = static_cast<std::string>(argv[2]) + ".cpp"; //argv[2] should be the output name (second argument given)
    //std::cout << "The outputFilename is " << outputFilename << std::endl;
    outputFile.open(outputFilename, std::ios_base::app); //Open the string held in outputFilename ("argv[2].cpp") in append mode.
    //We need to get the argv and append the file extension to it (".cpp").
    //The argv might have to be cast to a string.

    //We do a for-loop that declares a new input filestream, initializes it to the current argv[i] string
    //as its' filename, and appends the contents of that file to the output file.

    outputFile.close();
    return 0;
}

void Game::OutputTxtToFile(std::string requestedOutputStr, float requestedOutputNum)
{
	//C:\msys64\home\ssonn\GitHub2023\Chili-Framework-2016\Debug
	std::ofstream MyOutputFile;
	MyOutputFile.open("MyOutput2.txt", std::ios_base::app);
	MyOutputFile << requestedOutputStr;
	MyOutputFile << requestedOutputNum;
	MyOutputFile.close();

}