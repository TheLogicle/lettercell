#include "../lettercell.hpp"

void LetterCell::op_s(){
	if(!rhHasCell){
		rhHasCell = true;
		rhVal = 0;
	}
}
