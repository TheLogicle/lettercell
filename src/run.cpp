#include "lettercell.hpp"

void LetterCell::run ()
{
	if (activated) throw 255; //cannot call run() on a LetterCell object more than once

	activated = true;

	for (ind = 0; ind < code.size(); ++ind)
	{
		switch (code.at(ind))
		{
			case 'l': op_l(); break;
			case 'r': op_r(); break;
			case 'z': op_z(); break;
			case 's': op_s(); break;
			case 'v': op_v(); break;
			case 'p': op_p(); break;
			case 'd': op_d(); break;
			case 't': op_t(); break;
			case 'b': op_b(); break;
			case 'g': op_g(); break;
			default: throw 255;
		}
	}
}
