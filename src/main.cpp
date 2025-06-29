#include <iostream>
#include <fstream>

#include "lettercell.hpp"
#include "error.hpp"

int main(int argc, char** argv){

	if(argc < 2){
		std::cerr << error::invalid_usage().what() << std::endl;
		return 1;
	}

	std::string command = argv[1];

	std::string code;
	if(command == "run" || command == "pp"){
		if(argc < 3){
			std::cerr << error::missing_filename().what() << std::endl;
			return 1;
		}

		try{
			std::fstream readFile;
			readFile.open(argv[2]);
			
			if(readFile.bad()) throw 1;
			
			bool isOpen;
			while((isOpen = readFile.is_open()) && !readFile.eof()){
				std::string temp;
				readFile >> temp;
				code += temp;
			}
			
			if(!isOpen) throw 2;
			
			readFile.close();
		}
		catch(...){
			std::cerr << error::file_error(argv[2]).what() << std::endl;
			return 2;
		}
	}
	else if(command == "help"){
		std::cout << error::help_string << std::endl;
		return 0;
	}


	try{
		if(command == "pp"){
			std::cout << LetterCell::preprocess(code);
		}
		else if(command == "run"){
			LetterCell lc(code);

			lc.run();
		}
	}
	catch(error::error &e){
		std::cerr << e.what() << std::endl;
		return 3;
	}
	catch(...){
		std::cerr << "Unknown error" << std::endl;
		return 4;
	}

}
