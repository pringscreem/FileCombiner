Objective:
	This project is intended to provide a C++ program which can be used to
	combine multiple C++ files into a single file.

Current Use:
	The program is used from the command line, by executing the file with command 
	line arguments that are used to determine the way the files are combined and 
	which files are combined, as well as the name of combined file output.

		Use Example:
		./FileCombine combine myCombinedFile game.h game.cpp main.cpp

		The above command should copy the files "game.h", "game.cpp", and "main.cpp"
		into one file named "myCombinedFile.cpp".

		Second Example:
		./FileCombine help outputFile asdf.cpp qwerty.h qwerty.cpp main.cpp dvorak.cpp

		This second example should print out the instructions for using the program and 
		ignore all the other arguments after "help".

		Other options for execution:
			simplecombine - This does not remove any include statements.
			commentcombine - This comments out the include statements instead of removing
							 them.


Current Functionality:
	See above examples.
	The default combine operation removes the "include" statements for class 
	header files so that the combined file can be immediately compiled.

	Other options include not removing any include statements or commenting 
	out the include statements.

Current State:
	There are excessive explanatory comments everywhere, and there are project 
	notes, learning notes, experimental files (learning and testing) in the 
	project.

	There are no formal descriptions of functions, files, classes, or anything 
	else yet.

Future Objectives:
	This project or a future version of it will serve as a tool within a 
	webpage that allows users to easily combine several C++ files into a
	single file that can be compiled with an online compiler.  The goal 
	of the tool is to provide a solution for writing C++ in multiple files 
	and still frequently compiling to check for errors during times when 
	a compiler is only available via a website which compiles single files.

Future Users:
	The intended audience is students and beginners who are under other 
	pressures and have not yet installed a compiler on their computer, 
	or do not have access to a computer that they can install a compiler on.

Future Additions:
	Unit tests should be added at a future time.
	The accompanying website should be created.
	If it is possible to directly use this project's code, that would be 
	preferable, but if not, the project may need to be rewritten in a 
	more amenable language.
