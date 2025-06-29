#ifndef ERROR_HPP
#define ERROR_HPP

#include <string>

namespace error{

	const std::string usage_string_run = "Usage: lettercell run <file>";
	const std::string usage_string_pp = "Usage: lettercell pp <file>";

	const std::string usage_string = std::string{"Usage: lettercell run <file>     <-- run a file\n"}
	                                              + "       lettercell pp <file>      <-- don't run, only preprocess a file and output to stdout\n"
	                                              + "       lettercell help";

	const std::string help_string = std::string{}
		+ "This is an interpreter for the LetterCell language.\n\n"
		+ usage_string + "\n\n"
		+ "LetterCell is an esoteric programming language (a.k.a. esolang). It is based upon the concept of a readhead which can freely traverse over an infinitely long line of memory cell slots.\n\n"
		+ "Here is a visualization:\n\n"
		+ "                  readhead --->    |015|\n"
		+ "                                    \\ /\n"
		+ "                                     v\n\n"
		+ "... |     | 000 | 053 |     | 125 |     | 002 | ...  <--- memory slots\n\n"
		+ "- The readhead can freely move left and right.\n"
		+ "- The readhead has a space in it where it can store a memory cell.\n"
		+ "    - Memory cells hold exactly one byte of data.\n"
		+ "- The readhead can spawn a new cell in its storage area, and it can also vaporize the cell it is holding.\n"
		+ "- It can drop cells into the line of slots, and it can also pick up cells from there.\n"
		+ "- It can only change the value of the cell it is currently holding.\n\n"
		+ "Operations:\n"
		+ "  l - Move readhead left one space\n"
		+ "  r - Move readhead right one space\n"
		+ " zl - Move readhead left 16 spaces\n"
		+ " zr - Move readhead right 16 spaces\n"
		+ "  s - Spawn new memory cell with value 0\n"
		+ "  v - Vaporize current memory cell\n"
		+ "  p - Pick up memory cell\n"
		+ "  d - Drop memory cell\n"
		+ "  t - Increment current memory cell\n"
		+ "  b - Decrement current memory cell\n"
		+ " zt - Increment current memory cell by 16\n"
		+ " zb - Decrement current memory cell by 16\n"
		+ " k, kk, kkk, ... - Create label with the same amount of characters as k's (Example: kx is a label named x, and kkkfoo is a label named foo)\n"
		+ " g, gg, ggg, ... - Go to label (same syntax as k declaration). This will only go to the label if ONE of the following conditions are met:\n"
		+ "        1. The readhead is NOT currently holding a cell\n"
		+ "        2. The readhead IS currently holding a cell, and it is NOT set to 0\n\n"
		+ "The interpreter only reads the operator characters listed above, and all other characters are ignored."
		+ "\nHowever, comments may be written in non-nestable (parentheses), and such comments can contain operator characters which will be ignored.\n\n"
		+ "Do 'lettercell help | less' if this help page gets cut off by terminal scrolling.";

	struct error{
		virtual std::string what(){return "Unknown error";}
	};

	struct bad_syntax_k: error{
		std::string what() override{
			return "Bad syntax: Label definition does not have enough characters";
		};
	};
	struct bad_syntax_g: error{
		std::string what() override{
			return "Bad syntax: Goto call does not have enough characters";
		}
	};
	struct bad_syntax_z: error{
		std::string what() override{
			return "Bad syntax: Invalid letter after z operation. Valid letters are l, r, t, b";
		}
	};

	struct invalid_usage: error{
		std::string what() override{
			return "Welcome to LetterCell!\n\n" + usage_string;
		}
	};
	struct missing_filename: error{
		std::string what() override{
			return "Error: Missing filename\n" + usage_string_run;
		}
	};

	struct file_error: error{
		std::string filename;
		file_error(std::string filename){this->filename = filename;}
		std::string what() override{
			return "Error: Could not read file '" + filename + "'";
		}
	};

}


#endif
