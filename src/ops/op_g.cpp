#include "../lettercell.hpp"

void LetterCell::op_g(){

	#define c (code.at(ind))

	if(c == 'g'){
		size_t size = 0;
		while(true){
			if(c == 'g'){
				++size;
				++ind;
			}
			else break;
		}

		std::string lblName = code.substr(ind, size);

		auto pos = labels.find(lblName);

		if(pos == labels.end()) throw 255; //throw an error if the label is not found

		//only go if there is no current cell or if the current cell holds a nonzero value
		if(!rhHasCell || (rhHasCell && rhVal > 0)) ind = pos->second - 1;
		else ind += size - 1;
	}

	#undef c

}
