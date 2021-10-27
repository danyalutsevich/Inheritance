#pragma once

#include "Library.h"
#include <fstream>
#include <filesystem>
#include <vector>

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
			if (pair2[0] == "date") {

				Newspaper* journal = new Newspaper;
				return journal->SetDate(pair2[1])->SetTitle(pair1[1]);

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

	Literature** fromDir(std::string directory) {

		int litCount = 0;

		for (auto const& dir : std::filesystem::directory_iterator(directory)) {

			if (dir.path().extension() == ".lit") {

				litCount++;
			}

		}

		std::string* filename = new std::string[litCount];
		Literature** funds = new Literature * [litCount];
		litCount = 0;

		for (auto const& dir : std::filesystem::directory_iterator(directory)) {

			if (dir.path().extension() == ".lit") {

				filename[litCount] = dir.path().filename().string();
				litCount++;

			}

		}


		for (int i = 0; i < litCount; i++) {

			funds[i] = fromFile(directory + "/" + filename[i]);

		}

		return funds;
	}

	std::vector<Literature*> fromDirectory(std::string directory) {

		namespace fs = std::filesystem;

		std::vector<Literature*>funds;

		for (fs::directory_entry const& dir : fs::directory_iterator(directory)) {
			
			if (dir.is_regular_file()) {

				if (dir.path().extension() == ".lit") {

					Literature* fund = fromFile(dir.path().string());
					if (fund) {

						funds.push_back(fund);
					
					}

				}
			}

		}

		return funds;
	}

};