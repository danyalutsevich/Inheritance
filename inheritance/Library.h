#pragma once

#include <iostream>

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

};

class NewsPaper : public Literature {

private:
	std::string date;
public:
	NewsPaper* SetDate(std::string date) {

		this->date = date;
		return this;
	}

	std::string GetDate() {

		return date;
	}

};