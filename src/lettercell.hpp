#ifndef LETTERCELL_HPP
#define LETTERCELL_HPP

#include <string>
#include <unordered_map>
#include <cstdint>

class LetterCell{

	private:
		//this becomes true when run() is called
		bool activated{false};

		//the code string and the current index in the code string
		std::string code;
		size_t ind{0};

		//contains all labels
		std::unordered_map<std::string, size_t> labels;

		//contains all placed cells
		std::unordered_map<int32_t, uint8_t> cells;

		//readhead state
		int32_t rhLoc{0};
		bool rhHasCell{0};
		uint8_t rhVal{false};

		//letter operations
		void op_l();
		void op_r();
		void op_z();
		void op_s();
		void op_v();
		void op_p();
		void op_d();
		void op_t();
		void op_b();
		void op_g();


	public:
		//remove all unnecessary characters and comments from the code
		static std::string preprocess(std::string orig);

		//process labels in the code (the input code must be already preprocessed)
		static std::unordered_map<std::string, size_t> processLabels(std::string* code);

		void run();

		LetterCell(std::string code);

};

#endif
