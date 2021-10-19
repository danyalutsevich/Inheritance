
#include <iostream>
#include "Library.h"



int main()
{

	Book* book = new Book;
	book->SetAuthor("author")->SetTitle("book");

	Journal * journal = new Journal;
	journal->SetNumber(1)->SetTitle("journal");
	
	Newspaper* newspaper = new Newspaper;
	newspaper->SetDate("date")->SetTitle("newspaper");

	Booklet* booklet = new Booklet;
	booklet->SetDate("date")->SetAuthor("author")->SetTitle("booklet");

	Literature** funds = new Literature*[4];

	funds[0] = book;
	funds[1] = journal;
	funds[2] = newspaper;
	funds[3] = booklet;
	
	for (int i = 0; i < 4; i++) {

		std::cout << funds[i]->toString() << "\n";

	}


	delete booklet;
	delete newspaper;
	delete journal;
	delete book;
	return 0;

}

