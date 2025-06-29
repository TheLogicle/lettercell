#include "lettercell.hpp"

#include <string>

std::string LetterCell::preprocess (std::string orig)
{
	std::string res;

	bool comment = false;
	for (size_t i = 0; i < orig.size(); ++i)
	{
		char &c = orig.at(i);
		
		if (c == '(') comment = true;
		else if (c == ')') comment = false;
		if (!comment && (
		                 c == 'l' || c == 'r' || c == 'z'
		              || c == 's' || c == 'v' || c == 'p'
		              || c == 'd' || c == 't' || c == 'b'
		              || c == 'g' || c == 'k'
		           )) res += c;
	}

	return res;
}
