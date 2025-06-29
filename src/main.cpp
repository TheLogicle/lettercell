#include <iostream>
#include <unordered_map>
#include <cstdint>
#include <fstream>

#include "lettercell.hpp"

int main(int argc, char** argv){

	if(argc < 2) throw 255; //need to input filename as argument

	int fileArg = 1;
	bool preprocOnly = false;

	if(argv[1][0] == '-'){
		++fileArg;
		preprocOnly = true;
		if(argv[1][1] != 'p' || argv[1][2] != '\0') throw 255; //unrecognized flag
	}

	std::fstream readFile;
	readFile.open(argv[fileArg]);

	if(readFile.bad()) throw 255;

	std::string code;

	bool isOpen;
	while((isOpen = readFile.is_open()) && !readFile.eof()){
		std::string temp;
		readFile >> temp;
		code += temp;
	}

	if(!isOpen) throw 255;

	readFile.close();


	if(preprocOnly){
		std::cout << LetterCell::preprocess(code);
	}
	else{
		LetterCell lc(code);

		lc.run();
	}
}
