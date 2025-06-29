#include "../lettercell.hpp"

void LetterCell::op_l(){
	--rhLoc;
}

void LetterCell::op_r(){
	++rhLoc;
}
