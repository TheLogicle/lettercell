#include "lettercell.hpp"

LetterCell::LetterCell (std::string code)
	: activated (false),

		ind (0),

		rhLoc (0),
		rhHasCell (0),
		rhVal (false)
{
	this->code = code;

	this->code = preprocess(this->code);
	this->labels = processLabels(&(this->code));
}
