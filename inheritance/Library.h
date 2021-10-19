#pragma once

#include <iostream>
#include <string>

class Literature {
private:
	std::string title;

public:
	Literature* SetTitle(std::string title) {
		this->title = title;
		return this;
	}

	std::string GetTitle() {
		return title;
	}
	virtual std::string toString() = 0;
};

class Book :public Literature {

private:
	std::string author;
public:
	Book* SetAuthor(std::string author) {

		this->author = author;
		return this;
	}

	std::string GetAuthor() {

		return author;
	}

	virtual std::string toString() {

		std::string res;
		res += GetTitle() + " " + GetAuthor();

		return res;
	}

};

class Journal : public Literature {

private:
	int number;
public:
	Journal* SetNumber(int number) {

		this->number = number;
		return this;
	}

	int GetNumber() {

		return number;
	}

	std::string toString() {
		std::string res;
		res += GetTitle() + " (" + std::to_string(number) + ")";
		return res;

	}

};

class Newspaper : public Literature {

private:
	std::string date;
public:
	Newspaper* SetDate(std::string date) {

		this->date = date;
		return this;
	}

	std::string GetDate() {

		return date;
	}
	std::string toString() {

		std::string res;
		res += GetTitle() + " " + GetDate();
		return res;

	}

};

class Booklet : public Book {

private:
	std::string date;
public:

	Booklet* SetDate(std::string date) {

		this->date = date;
		return this;
	}

	std::string GetDate() {

		return date;
	}

	std::string toString() {

		std::string res;
		res += GetAuthor() + " " + GetTitle() + " " + GetDate();
		return res;

	}

};
