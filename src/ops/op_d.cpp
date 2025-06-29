#include "../lettercell.hpp"

#include <iostream>

void LetterCell::op_d(){
	if(!rhHasCell) return; //no-op if the readhead isn't holding a cell

	if(cells.find(rhLoc) == cells.end()){
		//the current space does NOT have a cell
		cells.insert({rhLoc, rhVal});
	}
	else{
		//the current space HAS a cell
		//so the dropped cell will instead "fall" into stdout
		std::cout << (char) rhVal;
	}

	rhHasCell = false;
}
