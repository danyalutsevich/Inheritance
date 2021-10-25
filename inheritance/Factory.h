#pragma once

#include "Library.h"
#include <fstream>

class LitFactory {

private:

	size_t parts;

	std::string* splitString(std::string str, char sym) {

		size_t pos = 0;
		parts = 1;

		while ((pos = str.find(sym, pos + 1)) != std::string::npos) {
			parts++;
		}

		std::string* res = new std::string[parts];
		pos = 0;
		size_t pos2;

		for (int i = 0; i < parts - 1; i++) {

			pos2 = str.find(sym, pos + 1);
			res[i] = str.substr(pos, pos2 - pos);
			pos = pos2;


		}

		res[parts - 1] = str.substr(pos + 1);



		return res;
	}

public:


	Literature* fromString(std::string str) {


		//splitt for lines
		auto arr = splitString(str, '\n');

		size_t lines = parts;

		if (lines < 2 || lines>3) {

			return NULL;
		}

		//split :

		auto pair1 = splitString(arr[0], ':');
		auto pair2 = splitString(arr[1], ':');


		if (lines == 2) {

			if (pair2[0] == "author") {

				Book* book = new Book;
				return book->SetAuthor(pair2[1])->SetTitle(pair1[1]);

			}
			if (pair2[0] == "number") {

				Journal* journal = new Journal;
				return journal->SetNumber(stoi(pair2[1]))->SetTitle(pair1[1]);

			}
			if (pair2[0] == "number") {

				Journal* journal = new Journal;
				return journal->SetNumber(stoi(pair2[1]))->SetTitle(pair1[1]);

			}
		}
		if (lines == 3) {

			auto pair3 = splitString(arr[2], ':');
			if (pair3[0] == "date") {

				Booklet* booklet = new Booklet;
				return booklet->SetDate(pair3[1])->SetAuthor(pair2[1])->SetTitle(pair1[1]);

			}
			if (pair3[0] == "year") {

				Magazine* mag = new Magazine;
				return mag->SetYear(stoi(pair3[1]))->SetNumber(stoi(pair2[1]))->SetTitle(pair1[1]);

			}
		}

		return NULL;

	}

	Literature* fromFile(std::string filename) {
	
		std::ifstream input;
		input.open(filename);
		char chunk[100];
		std::string str;

		while (!input.eof())
		{
			input.read(chunk, 5);
			std::streamsize n = input.gcount();
			chunk[n] = 0;


			str += chunk;
		}

		input.close();

		return fromString(str);

	
	}

};