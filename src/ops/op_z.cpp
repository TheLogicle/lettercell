#include "../lettercell.hpp"

#include "../error.hpp"

void LetterCell::op_z(){
	if(ind+1 >= code.size()) throw error::bad_syntax_z();
	if(code.at(ind+1) == 'l') rhLoc -= 16;
	else if(code.at(ind+1) == 'r') rhLoc += 16;
	else if(code.at(ind+1) == 't') rhVal = (rhVal+16) % 256;
	else if(code.at(ind+1) == 'b') rhVal = (rhVal-16+256) % 256;
	else throw error::bad_syntax_z();

	++ind;
}
