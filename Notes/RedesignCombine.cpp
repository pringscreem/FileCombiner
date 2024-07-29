//Function Pointers Redesign

void CommentCombineHelper()
{
	//Check for the filenames

	//If they are found, write them to the file with a comment at the beginning.

	//It looks like we have to open and close the file inside the helper function.
	//We can pass the string we are checking with getline/outputString (variable 
	//set by getline)

	//Read the function to check if this will work.
}

//Summary of current version
void Combine()
{
	//Open Output File

	for(/*Files to combine*/)
	{
		//Open Input File
		while(/*getline through the current file*/)
		{
			for(/*Files being combined*/)
			{
				//Check for include statement with filename
				//Trip the skip line flag if it is found
			}
			if(/*Skip line flag is tripped*/)
			{
				//Skip the line		//We could call the helper function here.
									//The price is that we call a dummy function if
									//the simple combine is selected.
									//This would mean we just wasted our time checking 
									//for the include statement in each line.
									//It would be better to call the helper function 
									//before it checks every line for the include statements.
			}
			else
			{
				//Copy the line
			}
		}
		//Close Input File (looping through them)
	}

	//Close Output File
}









//If-Else Version
void FileCombiner::Combine(std::string outputMode)
{
	//Do the copy loop (while-loop)
	while()
	{

		//Check for the output mode //We could do this with a switch statement.[Use if-else, see below.]
		if()
		{
			//output mode 1
			//The output mode functions will need the getline string (modify and return).
		}
		else if()
		{
			//output mode 2
		}
		//It would be nice if we could assign the helper function outside the loop and just 
		//call it inside the loop, instead of checking all the parameters on every iteration
		//of the loop.
		//	^This would probably require a function pointer, so that we could assign it 
		//	 outside of the loop.
	}
}

//Switch Statement:
//	Add a new output mode
//	Assign the command line argument to the string parameter of the Combine function
//	Assign a number to the new argument
//	Add the number to the switch statement
//	Create the new output mode function
// 
//	*Switch statements can have cascading effects on execution (everything past a number)
//	 ^A break statement is included to prevent the cascade (which is why it didn't cause more 
//	  problems in the past).

//If-Else Statement:
//  Add a new output mode
//	Assign the command line argument to the string parameter of the Combine function
//	Add the string to the if-else chain
//	Create the new output mode function
//
//	*Using if-else statements requires fewer modifications to add a new output mode in the 
//	 future


//Old Version
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