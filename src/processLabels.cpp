#include "lettercell.hpp"

#include <string>
#include <unordered_map>

std::unordered_map<std::string, size_t> LetterCell::processLabels(std::string* code){

	std::unordered_map<std::string, size_t> labels;

	for(int i = 0; i < code->size(); ++i){
		#define c (code->at(i))

		if(c == 'k'){
			size_t startPos = i;

			size_t size = 0;
			while(true){
				if(c == 'k'){
					++size;
					++i;
				}
				else break;
			}

			std::string lblName = code->substr(i, size);
			i += size - 1;

			//throw an error if there is already a label with that name
			if(labels.find(lblName) != labels.end()) throw 255;

			labels.insert({lblName, startPos});

			*code = code->substr(0, startPos) + code->substr(i+1);
			i = startPos - 1;
		}
	}

	return labels;
}
