#include "lettercell.hpp"

#include <string>

std::string LetterCell::preprocess(std::string orig){
	std::string res;

	bool comment = false;
	for(size_t i = 0; i < orig.size(); ++i){
		char &c = orig.at(i);
		
		if(c == '(') comment = true;
		else if(c == ')') comment = false;
		if(!comment && c >= 'a' && c <= 'z') res += c;
	}

	return res;
}
