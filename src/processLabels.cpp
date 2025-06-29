#include "lettercell.hpp"

#include <string>
#include <unordered_map>

#include "error.hpp"

std::unordered_map<std::string, size_t> LetterCell::processLabels (std::string* code)
{

	std::unordered_map<std::string, size_t> labels;

	for (int i = 0; i < code->size(); ++i)
	{
		#define c (code->at(i))

		if (c == 'k')
		{
			size_t startPos = i;

			size_t size = 0;
			try
			{
				while (true)
				{
					if (c == 'k')
					{
						++size;
						++i;
					}
					else break;
				}
			}
			catch (...)
			{
				throw error::bad_syntax_k();
			}

			std::string lblName = code->substr(i, size);
			i += size - 1;

			//throw an error if there is already a label with that name
			if (labels.find(lblName) != labels.end()) throw 255;

			labels.insert({lblName, startPos});

			*code = code->substr(0, startPos) + code->substr(i+1);
			i = startPos - 1;
		}
		else if (c == 'g') //this is to allow to goto labels with k in the name
		{
			size_t startPos = i;

			size_t size = 0;
			try
			{
				while (true)
				{
					if (c == 'g')
					{
						++size;
						++i;
					}
					else break;
				}
			}
			catch (...)
			{
				throw error::bad_syntax_g();
			}

			i += size - 1;
		}
	}

	//this will print out all labels that have been scanned
	/*
	printf("label count: %ld\n", labels.size());
	for (auto i = labels.begin(); i != labels.end(); ++i)
	{
		printf("%s: %s\n", i->first.c_str(), std::to_string(i->second).c_str());
	}
	*/

	return labels;
}
