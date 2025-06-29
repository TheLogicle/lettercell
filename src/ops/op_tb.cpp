#include "../lettercell.hpp"

void LetterCell::op_t(){
	rhVal = (rhVal+1) % 256;
}

void LetterCell::op_b(){
	rhVal = (rhVal-1+256) % 256;
}
