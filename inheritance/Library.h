#pragma once

#include <iostream>
#include <string>

class Literature {
private:
	std::string title;

public:
	Literature() : title{ "" } {

		//std::cout << "Literature constructor " << this << "\n";
	}

	Literature* SetTitle(std::string title) {
		this->title = title;
		return this;
	}

	std::string GetTitle() {
		return title;
	}

	virtual std::string toString() = 0;

	virtual ~Literature() {

		//std::cout << "Literature destructor " << this << "\n";
	}

};

class Book :public Literature {

private:
	std::string author;
public:

	Book() :author{ "" } {

		//std::cout << "Book constructor " << this << "\n";

	}

	Book* SetAuthor(std::string author) {

		this->author = author;
		return this;
	}

	std::string GetAuthor() {

		return author;
	}

	virtual std::string toString() {

		std::string res;
		res += "Book: " + GetTitle() + " " + GetAuthor();

		return res;
	}

	~Book() {

		//std::cout << "Book destructor " << this << "\n";
	}

};

class Journal : public Literature {

private:
	int number;
public:
	Journal() :number{ 0 } {
	//	std::cout << "Journal constructor " << this << "\n";
	}

	Journal* SetNumber(int number) {

		this->number = number;
		return this;
	}

	int GetNumber() {

		return number;
	}

	std::string toString() {
		std::string res;
		res += "Journal: " + GetTitle() + " (" + std::to_string(number) + ")";
		return res;

	}
	~Journal() {

	//	std::cout << "Journal destructor " << this << "\n";
	}

};

class Newspaper : public Literature {

private:
	std::string date;
public:
	Newspaper() :date{ "" } {
		//std::cout << "Newspaper constructor " << this << "\n";
	}

	Newspaper* SetDate(std::string date) {

		this->date = date;
		return this;
	}

	std::string GetDate() {

		return date;
	}
	std::string toString() {

		std::string res;
		res +="Newspaper: "+ GetTitle() + " " + GetDate();
		return res;

	}
	~Newspaper() {

		//std::cout << "Newspaper destructor " << this << "\n";
	}
};

class Booklet : public Book {

private:
	std::string date;
public:
	Booklet() :date{ "" } {

		//std::cout << "Booklet constructor " << this << "\n";
	}

	Booklet* SetDate(std::string date) {

		this->date = date;
		return this;
	}

	std::string GetDate() {

		return date;
	}

	std::string toString() {

		std::string res;
		res += "Booklet: " + GetAuthor() + " " + GetTitle() + " " + GetDate();
		return res;

	}
	~Booklet() {

	//	std::cout << "Booklet destructor " << this << "\n";
	}

};

class Childish {

private:

public:

};

class Magazine : public Journal, public Childish {

private:
	int year;
public:

	Magazine() :year{ 0 } {
		//std::cout << "Magazine constructor " << this << "\n";
	}

	Magazine* SetYear(int year) {

		this->year = year;
		return this;
	}

	int GetYear() {
		return year;
	}

	std::string toString() {

		return "Magazine: " + GetTitle() + " (" + std::to_string(GetNumber()) + ")" + " " + std::to_string(year);
	}

	~Magazine() {

		//std::cout << "Magazine destructor " << this << "\n";
	}

};
