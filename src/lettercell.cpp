#include "lettercell.hpp"

LetterCell::LetterCell(std::string code){
	this->code = code;

	this->code = preprocess(this->code);
	this->labels = processLabels(&(this->code));
}
