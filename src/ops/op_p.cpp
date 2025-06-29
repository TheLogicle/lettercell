#include "../lettercell.hpp"

#include <iostream>

void LetterCell::op_p(){

	if(rhHasCell) return; //no-op if the readhead is already holding a cell

	auto cell = cells.find(rhLoc);
	if(cell == cells.end()){

		//the current space does NOT have a cell
		//so we must "pick it up" from stdin
		char c;
		do{
			c = std::cin.get();
		} while(c == -1);

		rhVal = (uint8_t) c;
	}
	else{
		//the current space HAS a cell
		rhVal = cell->second;
		cells.erase(cell);
	}

	rhHasCell = true;
	
}
