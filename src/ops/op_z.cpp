#include "../lettercell.hpp"

void LetterCell::op_z(){
	if(code.at(ind+1) == 'l') rhLoc -= 16;
	else if(code.at(ind+1) == 'r') rhLoc += 16;
	else if(code.at(ind+1) == 't') rhVal = (rhVal+16) % 256;
	else if(code.at(ind+1) == 'b') rhVal = (rhVal-16+256) % 256;
	else throw 255;

	++ind;
}
